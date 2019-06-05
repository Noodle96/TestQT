QT += widgets
requires(qtConfig(filedialog))

HEADERS       = mainwindow.h \
    afd.h \
    syntacticanalysis.h
SOURCES       = main.cpp \
                mainwindow.cpp \
    buildautomathon.cpp \
    buildwordreserved.cpp \
    line.cpp \
    funcionessupport.cpp \
    buildsintacticanalysis.cpp
#! [0]
RESOURCES     = \
    application.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target

DISTFILES +=
