
# Qt Example for Relation Table Model

This is an improved version of the Qt example available at 
https://doc.qt.io/qt-5/qtsql-relationaltablemodel-example.html.
It proposes a class-based (instead of function-based) programmation,
avoids static methods when possible, and allows dynamic definition of 
the database from a SQL queries file (instead of hard-coded queries).

## Content

`Connection.hpp` & `RelationTableModel.cpp` are the modified sources 
files, and `RelationTableModel.pro` is the project file for Qt 
(see Compilation).
`Doxyfile` is the doxygen settings file, and is used 
by the `docGen.sh` bash script (see Documentation).
At last, `employee.sqlite` is a SQLite queries file, which can be 
loaded by the generated application to fill the database in memory. 
Otherwise, `employee.db3` file can also be used.

## Compilation

Compilation can be done two ways:

* generating a `Makefile` with `qmake`, and compile with `make`, or

* using `qtcreator` to load the project (`RelationTableModel.pro`
  file).
  
## Documentation

Documentation is generated in the `html` directory by `doxygen`,
simply launching the `docGen.sh` bash script.
The system variables in this script may need to be corrected,
depending on your system installation.
