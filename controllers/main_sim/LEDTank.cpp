#include <stdio.h>
#include "includes/Event.hpp"
#include "LEDTank.hpp"
#include <unistd.h>

LEDTank::LEDTank(Controller *controller){
  this->state = _STATE_INITIAL;
  this->controller = controller;

  this->turnTimes = 0;
}

void LEDTank::execState(){
  switch(this->state){
  case STATE_INIT:
    
    break;
  case STATE_FOWARD:
    positionValue = controller->getPosition();

    break;
  case STATE_STOP:
    
    break;
  default:
    break;
  }
}

void LEDTank::doTransition(unsigned long event){
  this->_beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_INIT;

    //entry
    printf("STOP\n");
controller->changeDriveMode(STOP,0);
turnTimes = 0;

    break;  
  case STATE_INIT:
    if(((event & E_TRUE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_FOWARD;

      //entry
      controller->changeDriveMode(FORWARD,50);
printf("FORWARD\n");
controller->positionReset();
    }
    break;
  case STATE_FOWARD:
    if(((event & E_CHANGE_DISTANCE) != 0) && (positionValue.distance >= 0.3)){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      printf("STOP\n");
controller->changeDriveMode(STOP,0);
    }
    break;
  case STATE_STOP:
    break;
  default:
    break;
  }
}

void LEDTank::printValues(){
    printf("distance=%f, angle=%f \n", positionValue.distance, positionValue.angle);
    printf("range=%f \n", rangeDistance);
    printf("color: R=%d, G=%d, B=%d \n", colorValue.red, colorValue.green, colorValue.blue);
    printf("line: l=%d, c=%d, r=%d \n", lineValue.left, lineValue.center, lineValue.right);
}