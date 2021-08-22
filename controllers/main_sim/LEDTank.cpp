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
  case STATE_FORWARD:
    positionValue = controller->getPosition();
    break;
  case STATE_BACKWARD:
    positionValue = controller->getPosition();
    break;
  default:
    break;
  }
}

void LEDTank::doTransition(unsigned long event){
  this->_beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_FORWARD;

    //entry
    controller->positionReset();
controller->changeDriveMode(FORWARD,100);
printf("FORWARD\n");

    break;  
  case STATE_FORWARD:
    if(((event & E_CHANGE_DISTANCE) != 0) && (positionValue.distance > 0.5)){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      controller->positionReset();
controller->changeDriveMode(BACKWARD,100);
printf("BACKWARD\n");
    }
    break;
  case STATE_BACKWARD:
    if(((event & E_CHANGE_DISTANCE) != 0) && (positionValue.distance < -0.5
)){
      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      controller->positionReset();
controller->changeDriveMode(FORWARD,100);
printf("FORWARD\n");
    }
    break;
  default:
    break;
  }
}