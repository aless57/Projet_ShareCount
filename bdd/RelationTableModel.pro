# -*- Makefile -*- (to get Makefile-mode in Emacs)
#----------------------------------------------------------------
# Project file from the original example, corrected by A. Scheuer
#----------------------------------------------------------------

TEMPLATE    = app           # to generate an application
TARGET      = relTabGui     # name of this application
QT         += core gui sql  # packages needed
# in Qt 5, widget package is not anymore in gui package
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 

# to use C++11 (for both Qt 4 and Qt 5)
QMAKE_CXXFLAGS += -std=c++11

HEADERS       = Connection.hpp
SOURCES       = RelationTableModel.cpp
