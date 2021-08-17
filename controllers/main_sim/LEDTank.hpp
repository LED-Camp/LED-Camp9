#ifndef __LEDTank__
#define __LEDTank__

#include "includes/Controller.hpp"
#include "ColorValue.hpp"
#include "LineValue.hpp"
#include "PositionValue.hpp"

#define _STATE_INITIAL 0x00000000
#define STATE_STOP2 ((unsigned long)1)
#define STATE_FRONT1 ((unsigned long)2)
#define STATE_STOP1 ((unsigned long)3)
#define STATE_RETURN1 ((unsigned long)4)
#define STATE_TURN_5d ((unsigned long)5)
#define STATE_STOP3 ((unsigned long)6)
#define STATE_FRONT2 ((unsigned long)7)
#define STATE_STOP4 ((unsigned long)8)
#define STATE_RETURN2 ((unsigned long)9)
#define STATE_STOP5 ((unsigned long)10)
#define STATE_RETURN3 ((unsigned long)11)
#define STATE_STOP6 ((unsigned long)12)

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
  float rangingDistance;
  bool lineL;
  bool lineC;
  bool lineR;
  float distanceA;
  int cnt_turn;
  int t_start;
  int t_end;
  ColorValue colorValue;
  LineValue lineValue;
  PositionValue positionValue;

};

#endif