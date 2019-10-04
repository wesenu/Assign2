#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include <iostream>
#include "gameofLife.cpp"

class MirrorMode
{
public:
  MirrorMode();
  ~MirrorMode();

  int calculateMirror(int x, int y, int rows, int columns, int ***grid);

};

#endif
