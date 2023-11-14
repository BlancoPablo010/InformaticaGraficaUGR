DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x050F00

HEADERS += \
  colors.h \
  basic_object3d.h \
    cone.h \
    cube.h \
    cylinder.h \
  object3d.h \
  axis.h \
    ply.h \
    ply_object3d.h \
    revolutionobject3d.h \
    saltamontes.h \
    sphere.h \
  tetrahedron.h \
#  cube.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
    cone.cpp \
    cube.cc \
    cylinder.cpp \
  object3d.cc \
  axis.cc \
    ply.cpp \
    ply_object3d.cpp \
    revolutionobject3d.cpp \
    saltamontes.cpp \
    sphere.cpp \
  tetrahedron.cc \
#  cube.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++14
QT += widgets opengl openglwidgets

DISTFILES += \
    ply_models/airplane.ply
