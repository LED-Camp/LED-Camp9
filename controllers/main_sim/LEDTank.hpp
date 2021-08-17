#ifndef __LEDTank__
#define __LEDTank__

#include "includes/Controller.hpp"
#include "ColorValue.hpp"
#include "LineValue.hpp"
#include "PositionValue.hpp"

#define _STATE_INITIAL 0x00000000
#define STATE_FORWARD ((unsigned long)1)
#define STATE_BACKWARD ((unsigned long)2)

class LEDTank{
 public:
  LEDTank(Controller *controller);
  void execState();
  void doTransition(unsigned long event);
  unsigned long _state;

 private:
   Controller *controller;
   unsigned long _beforeState;
   unsigned long state;
  float distance;
  float angle;
  float rangeDistance;
  int lineLeft;
  int lineCenter;
  int lineRight;
  ColorValue colorValue;
  LineValue lineValue;
  PositionValue positionValue;

};

#endif