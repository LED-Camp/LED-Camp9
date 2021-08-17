#include <stdio.h>
#include "includes/Event.hpp"
#include "LEDTank.hpp"
#include <unistd.h>

LEDTank::LEDTank(Controller *controller){
  this->state = _STATE_INITIAL;
  this->controller = controller;

  this->lineLeft = 0;
  this->lineCenter = 0;
  this->lineRight = 0;
}

void LEDTank::execState(){
  switch(this->state){
  case STATE_TURN:
    rangeDistance = controller->getRange();
    break;
  case STATE_FORWARD:
    colorValue = controller->getColorValue();
    break;
  case STATE_BACKWARD:
    
    break;
  default:
    break;
  }
}

void LEDTank::doTransition(unsigned long event){
  this->_beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_TURN;

    //entry
    controller->positionReset();
controller->changeDriveMode(CW,100);
printf("CW\n");

    break;  
  case STATE_TURN:
    if(((event & E_CHANGE_RANGING) != 0) && (rangeDistance < 50.0)){
      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      controller->positionReset();
controller->changeDriveMode(FORWARD,100);
printf("FORWARD\n");
    }
    break;
  case STATE_FORWARD:
    if(((event & E_CHANGE_COLOR) != 0) && (colorValue.red - colorValue.green > 40
&& colorValue.red - colorValue.blue > 40)){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      controller->positionReset();
controller->changeDriveMode(BACKWARD,100);
printf("FORWARD\n");
    }
    break;
  case STATE_BACKWARD:
    break;
  default:
    break;
  }
}