QT += widgets
requires(qtConfig(filedialog))

HEADERS       = mainwindow.h \
    afd.h
SOURCES       = main.cpp \
                mainwindow.cpp \
    buildautomathon.cpp \
    buildwordreserved.cpp
#! [0]
RESOURCES     = \
    application.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target

DISTFILES +=
