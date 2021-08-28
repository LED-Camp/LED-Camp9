#ifndef __LEDTank__
#define __LEDTank__

#include "includes/Controller.hpp"
#include "ColorValue.hpp"
#include "LineValue.hpp"
#include "PositionValue.hpp"

#define _STATE_INITIAL 0x00000000
#define STATE_INIT ((unsigned long)1)
#define STATE_FOWARD ((unsigned long)2)
#define STATE_STOP ((unsigned long)3)

class LEDTank{
 public:
  LEDTank(Controller *controller);
  void execState();
  void doTransition(unsigned long event);
  unsigned long _state;
  void printValues();

 private:
   Controller *controller;
   unsigned long _beforeState;
   unsigned long state;
  PositionValue positionValue;
  int turnTimes;
  ColorValue colorValue;
  LineValue lineValue;
  float rangeDistance;

};

#endif