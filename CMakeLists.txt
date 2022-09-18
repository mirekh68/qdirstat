cmake_minimum_required(VERSION 3.14)

project(QDirstat)
# Toplevel qmake .pro file. Create a Makefile from this with
#
#     qmake
#
# Then build the program with
#
#     make
#
# Then install it with
#
#     sudo make install
#
# By default, everyting is installed to /usr.
# If you want to install to, say, /usr/local, set INSTALL_PREFIX:
#
#     qmake INSTALL_PREFIX=/usr/local


add_subdirectory(src)
add_subdirectory(scripts)
add_subdirectory(doc)
add_subdirectory(man)
add_subdirectory(FileInfoTests)



SUBDIRS  = src scrip#ts doc doc/stats man  FileInfoTests
