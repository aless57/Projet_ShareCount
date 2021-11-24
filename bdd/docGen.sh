#!/bin/bash

# === These variables are needed in the doxygen configuration file ===

# Qt local headers directory
export QT_INC=/usr/include/x86_64-linux-gnu/qt5

# Qt HTML local documentation directory (containing tags files)
export QT_DOC=/usr/share/qt5/doc

# Qt HTML internet documentation URI
export QT_W3=http://doc.qt.io/qt-5

# === Now that these variables are set, start doxygen ================
doxygen
