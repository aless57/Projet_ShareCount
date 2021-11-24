/** @file RelationTableModel.cpp
 **
 ** This file is an improved version of the Qt example available at 
 ** https://doc.qt.io/qt-5/qtsql-relationaltablemodel-example.html.
 **
 ** It proposes a class-based (instead of function-based) programmation,
 ** avoids static methods when possible, and allows dynamic
 ** definition of the database from a SQL queries file 
 ** (instead of hard-coded queries).
 **
 ** @author  A. Scheuer, correcting a Qt example.
 **/

// Original file used QtWidgets, which is not available in Qt 4
#include <QtSql> 
#include <QMainWindow>
#include <QTableView> 
#include <QApplication>
#include <QMessageBox> 
#include <QFileDialog> 
#include "Connection.hpp"

//### DB View Class ##################################################

/** @brief  This class uses a QTableView and a couple 
 **         (QSqlRelationalTableModel, QSqlRelationalDelegate)
 **         to display and edit a given SQL database.
 **/
class DatabaseView {  // The graphic objects are statically allocated
  /// The relational table model used to format the display.
  QSqlRelationalTableModel model;

  /// The table view opened to display the database.
  QTableView               view;

  /// The relational delegate used to display and edit the database.
  QSqlRelationalDelegate   delegate;

public:
  /** @brief  This constructor needs the database to display, 
   **         and an optional widget which is the parent of the view.
   **
   ** @param  db      the database which will be displayed and edited,
   ** @param  parent  the parent widget of the view (optional).
   **/
  DatabaseView(QSqlDatabase& db, QWidget* parent = nullptr)
    : model(parent, db), view(parent), delegate(&view) {}

  /** @brief  Updates the database when the view is deleted. */
  ~DatabaseView() { model.submitAll(); }
  
  /** @brief   Initialises the view with a given title.
   ** @return  whether the model was initialised correctly.
   ** @see     initModel, setView.
   **/
  bool init() { 
    const bool res = initModel();
    if (res)  setView();
    return res; 
  }

  /** @brief  Gives a access to the table view.
   **
   ** @return  the table view.
   **/
  QTableView& getView() { return view; }
  
protected:
  /** @brief   Initialises the model. 
   ** @return  true if everything goes right, false otherwise. */
  bool initModel() { 
    model.setTable("employee");  // view will show the employee table
    // wait for submitAll() before changing table
    model.setEditStrategy(QSqlTableModel::OnManualSubmit);
    // show names instead of id for cities & countries
    model.setRelation(2, QSqlRelation("city", "id", "name"));
    model.setRelation(3, QSqlRelation("country", "id", "name"));
    // headers settings
    model.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model.setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model.setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
    model.setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));
    // makes the settings be effective
    return model.select();
  } // end of void initModel()

  /** @brief  Connects the view to the model and the delegate, 
   **         and sets its title.
   **/
  void setView() {
    view.setModel(&model);
    view.setItemDelegate(&delegate);
  } // end of void setView()
  
}; // end of class DatabaseView

//### Application Class ##############################################

/** @brief  This class asks the user which SQLite database to use, and 
 **         displays it using the @ref DatabaseView "database view".
 **/
class MainApplication {
  QApplication& application; 
  QMainWindow   mainWindow;

  /** @brief   Ask the user whether the database should run in memory,
   **          or use a file.
   ** @return  the file name of the database, or an empty string.
   **/
  const QString getDbName() {
    const QMessageBox::StandardButton dbStg = QMessageBox::question
      ( &mainWindow, QObject::tr("DataBase Setting"),
	QObject::tr("Do you want to save your database?\n If you "
		    "answer 'no', it will run in memory only."),
	// this is the default in Qt 5.5, but not in 4.8...
	QMessageBox::StandardButtons( QMessageBox::Yes
				      | QMessageBox::No ) );
    // If needed, ask for the database name
    const QString dbName = dbStg == QMessageBox::Yes ?
      QFileDialog::getSaveFileName
      ( &mainWindow, QObject::tr("Database File"),
       QDir::currentPath(), "SQLite Database (*.db3)",
       nullptr, QFileDialog::DontConfirmOverwrite) : ""; 
    return dbName; 
  } // end of const QString getDbName()

  /** @brief   Ask the user for a SQLite queries file, to modify
   **          the given database.
   ** @param   db  the database to modify.
   ** @return  whether the queries file was applied without error.
   **/
  bool modifyDb(ASqlDatabase& db) {
    const QString fileName = QFileDialog::getOpenFileName
      ( &mainWindow, QObject::tr("Database Initialisation Queries"),
       QDir::currentPath(), "SQLite Queries (*.sqlite)");
    bool db_ok = true; 
    if (! fileName.isEmpty() ) {
      QFile file(fileName); 
      db.exec_file(file);
      db_ok = ! db.lastError().isValid();
    } // end of if (Queries file is not empty)
    return db_ok; 
  } // end of bool modifyDb(ASqlDatabase&)

  int viewDb(QSqlDatabase& db) {
    DatabaseView view(db);
    int result;
    if ( view.init() ) {
      QTableView& table = view.getView();
      mainWindow.hide();
      mainWindow.setCentralWidget(&table); 
      mainWindow.show();
      result = application.exec();
    } else {
      QMessageBox::warning
	( &mainWindow, QObject::tr("Error in View Initialisation"),
	  QObject::tr("The view could not be initialised!") );
      result = 2; 
    }
    return result; 
  } // end of int viewDb(QSqlDatabase&)
  
public:
  /** @brief  Create and open the main window, with a given title.
   ** @param  appli  the Qt main application,
   ** @param  title  the main window title.
   ** @see    QMainWindow, QWidget::setWindowTitle
   **/
  MainApplication(QApplication& appli, const char* title)
    : application(appli) {
    mainWindow.setWindowTitle( QObject::tr(title) );
    mainWindow.setMinimumSize(600, 100); 
    mainWindow.show();
  } // end of MainApplication(QApplication&, const char*)

  /** @brief   The application main method, asking for the database 
   **          and displaying it.
   ** @return  1 if the database could not be created, 
   **          2 if it could not be modified, 
   **          3 if it could not be displayed, 
   **          the result of appli.exec() otherwise.
   ** @see     QApplication.exec()
   **/
  int start() {
    int app_state = 0; 
    const QString dbName = getDbName(); 
    // connects to the database (with the right name)
    ASqlDatabase db("QSQLITE",  dbName.isNull() || dbName.isEmpty() ? 
		    ":memory:" : dbName);
    if ( db.open() ) {
      if ( modifyDb(db) )
	app_state = viewDb(db);
      else {
	QMessageBox::critical
	  ( &mainWindow,
	    QObject::tr("Error in DataBase Initialisation"),
        QObject::tr("Database initialisation returned error") );
	app_state = 2; 
      } // end of else (the database could not be modified)
    } else {
      QMessageBox::critical
	( &mainWindow, QObject::tr("Cannot Open DataBase"),
	  QObject::tr("Unable to establish a database connection.\n"
		      "This example needs SQLite support. Please "
		      "read the Qt SQL driver documentation for "
		      "informations on how to build it.") );
      app_state = 1; 
    } // end of else (BD could not be opened)

    return app_state; 
  } // end of int start()
  
}; // end of class MainApplication

//### Main Function ##################################################

/** @mainpage Qt Relational Table Model Corrected Example
 **
 ** This example is an improved version of the one available at 
 ** https://doc.qt.io/qt-5/qtsql-relationaltablemodel-example.html.
 **
 ** Teaching computer science, object-base programming and robotics
 ** at <a href="http://welcome.univ-lorraine.fr/en">Lorraine 
 ** university</a>, in France, I think that the original example 
 ** suffers from the following misconception errors:
 ** <ol>
 **   <li>it uses static calls to the default database, when it is
 **       more efficient and so easy to access it through a variable 
 **       (I consider that static method, as global variables, 
 **        should not be used when it can be easily avoided);</li>
 **   <li>it contains hard-coded SQL queries (any change of 
 **        the queries requires a new compilation), instead of 
 **       a dynamic access to a file containing these queries; </li>
 **   <li>it proposes a function-based (C like) programming, instead 
 **       of a <a href="inherits.html">class-based</a> one (C++), and 
 **       contains too few comments and no documentation.</li>
 ** </ol>
 **
 ** @author  <a href="http://members.loria.fr/AScheuer">A. Scheuer</a>, 
 **          <a href="http://welcome.univ-lorraine.fr/en">Lorraine
 **           university</a>/<a href="http://fst-en.univ-lorraine.fr"
 **          >FST</a> & <a href="http://www.loria.fr/en">Loria</a>.
 **/

/** @brief  Main function 
 **         of the @ref mainpage "Qt relational table model example".
 **
 ** @param  argc  arguments count, transmitted to the Qt application,
 ** @param  argv  arguments values, transmitted to the Qt application.
 **/
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainApplication dbApp(app, "Relational Table Model");

  return dbApp.start();
} // end of int main(int, char *[]) 
