DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x050F00

HEADERS += \
    include/colors.h \
    include/basic_object3d.h \
    include/cone.h \
    include/cube.h \
    include/cylinder.h \
    include/object3d.h \
    include/axis.h \
    include/ply.h \
    include/ply_object3d.h \
    include/revolutionobject3d.h \
    include/saltamontes.h \
    include/sphere.h \
    include/tetrahedron.h \
    include/glwidget.h \
    include/window.h

SOURCES += \
    source/basic_object3d.cc \
    source/cone.cpp \
    source/cube.cc \
    source/cylinder.cpp \
    source/object3d.cc \
    source/axis.cc \
    source/ply.cpp \
    source/ply_object3d.cpp \
    source/revolutionobject3d.cpp \
    source/saltamontes.cpp \
    source/sphere.cpp \
    source/tetrahedron.cc \
    source/main.cc \
    source/glwidget.cc \
    source/window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++14
QT += widgets opengl openglwidgets

DISTFILES += \
    ply_models/airplane.ply
