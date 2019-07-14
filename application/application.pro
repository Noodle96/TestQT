QT += widgets
requires(qtConfig(filedialog))

HEADERS       = mainwindow.h \
    afd.h \
    syntacticanalysis.h \
    lexemaattributes.h \
    addexample.h
SOURCES       = main.cpp \
    buildsemanticanalysis.cpp \
                mainwindow.cpp \
    buildautomathon.cpp \
    buildwordreserved.cpp \
    line.cpp \
    funcionessupport.cpp \
    buildsintacticanalysis.cpp \
    addexample.cpp
#! [0]
RESOURCES     = \
    application.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target

DISTFILES +=
