/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef COLORS_H
#define COLORS_H

#include "vertex.h"

namespace _colors_ne {

  const _vertex3f RED(1,0,0);
  const _vertex3f GREEN(0,1,0);
  const _vertex3f BLUE(0,0,1);
  const _vertex3f CYAN(0,1,1);
  const _vertex3f MAGENTA(1,0,1);
  const _vertex3f YELLOW(1,1,0);
  const _vertex3f BLACK(0,0,0);
  const _vertex3f WHITE(1,1,1);

  const _vertex3f COLORS[]={RED,GREEN,BLUE,CYAN,MAGENTA,YELLOW,BLACK,WHITE};
}

#endif
