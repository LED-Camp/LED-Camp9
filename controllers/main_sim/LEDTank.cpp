#include <stdio.h>
#include "includes/Event.hpp"
#include "LEDTank.hpp"
#include <unistd.h>

LEDTank::LEDTank(Controller *controller){
  this->state = _STATE_INITIAL;
  this->controller = controller;

  this->cnt_turn = 0;
  this->t_start = 0;
  this->t_end = 0;
}

void LEDTank::execState(){
  switch(this->state){
  case STATE_STOP2:
    
    break;
  case STATE_FRONT1:
    lineValue = controller->getLineValue();
rangingDistance=controller->getRange();
positionValue = controller->getPosition();
    break;
  case STATE_STOP1:
    rangingDistance=controller->getRange();
    break;
  case STATE_RETURN1:
    positionValue = controller->getPosition();
    break;
  case STATE_TURN_5d:
    positionValue = controller->getPosition();
t_end++;

    break;
  case STATE_STOP3:
    
    break;
  case STATE_FRONT2:
    lineValue = controller->getLineValue();
positionValue = controller->getPosition();
    break;
  case STATE_STOP4:
    
    break;
  case STATE_RETURN2:
    positionValue = controller->getPosition();
    break;
  case STATE_STOP5:
    
    break;
  case STATE_RETURN3:
    positionValue = controller->getPosition();
    break;
  case STATE_STOP6:
    
    break;
  default:
    break;
  }
}

void LEDTank::doTransition(unsigned long event){
  this->_beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_FRONT1;

    //entry
    controller->changeDriveMode(FORWARD, 50);
printf("FRONT\n");
controller->positionReset();
cnt_turn = 0;


    break;  
  case STATE_STOP2:
    if(((event & E_TRUE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_TURN_5d;

      //entry
      controller->positionReset();
controller->changeDriveMode(CW, 95);
printf("TURN_RIGHT\n");
t_start = 0;
t_end = 0;

    }
    break;
  case STATE_FRONT1:
    if(((event & E_CHANGE_AREA) != 0) && (
lineValue.center == 0 && (
lineValue.left == 0 ||
lineValue.right == 0 ))){
      // exit
      controller->changeDriveMode(STOP, 0);
sleep(1);

      //action
      

      this->state = STATE_STOP1;

      //entry
      controller->changeDriveMode(STOP, 0);
printf("STOP\n");
distanceA = positionValue.distance;


    }
    break;
  case STATE_STOP1:
    if(((event & E_TRUE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RETURN1;

      //entry
      controller->changeDriveMode(BACKWARD, 50);
printf("RETURN\n");

    }
    break;
  case STATE_RETURN1:
    if(((event & E_CHANGE_DISTANCE) != 0) && (positionValue.distance < (distanceA/2))){
      // exit
      

      //action
      

      this->state = STATE_STOP2;

      //entry
      controller->changeDriveMode(STOP, 0);
printf("STOP!!!\n");
    }
    break;
  case STATE_TURN_5d:
    if(((event & E_TRUE) != 0) && ((t_end - t_start) / 20 > 2)){
      // exit
      controller->changeDriveMode(STOP, 0);
cnt_turn = 0;
sleep(1);

      //action
      

      this->state = STATE_STOP5;

      //entry
      controller->changeDriveMode(STOP, 0);
printf("STOP!!!\n");
    }
    else
    if(((event & E_CHANGE_ANGLE) != 0) && (positionValue.angle > 15)){
      // exit
      controller->changeDriveMode(STOP, 0);
cnt_turn = 0;
sleep(1);

      //action
      

      this->state = STATE_STOP3;

      //entry
      controller->changeDriveMode(STOP, 0);
rangingDistance=controller->getRange();
printf("STOP!!!\n");
    }
    break;
  case STATE_STOP3:
    if(((event & E_CHANGE_RANGING) != 0) && (this->rangingDistance >= 65)){
      // exit
      

      //action
      

      this->state = STATE_TURN_5d;

      //entry
      controller->positionReset();
controller->changeDriveMode(CW, 95);
printf("TURN_RIGHT\n");
t_start = 0;
t_end = 0;

    }
    else
    if(((event & E_CHANGE_RANGING) != 0) && (this->rangingDistance < 65)){
      // exit
      

      //action
      

      this->state = STATE_FRONT2;

      //entry
      controller->positionReset();
controller->changeDriveMode(FORWARD, 50);
printf("FRONT\n");


    }
    break;
  case STATE_FRONT2:
    if(((event & E_CHANGE_AREA) != 0) && (
lineValue.center == 0 && (
lineValue.left == 0 ||
lineValue.right == 0 ))){
      // exit
      controller->changeDriveMode(STOP, 0);
sleep(1);

      //action
      

      this->state = STATE_STOP4;

      //entry
      controller->changeDriveMode(STOP, 0);
printf("STOP!!!\n");
    }
    break;
  case STATE_STOP4:
    if(((event & E_TRUE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RETURN2;

      //entry
      controller->changeDriveMode(BACKWARD, 64);
printf("RETURN\n");

    }
    break;
  case STATE_RETURN2:
    if(((event & E_TRUE
) != 0) && (positionValue.distance < 0)){
      // exit
      controller->changeDriveMode(STOP, 0);
sleep(1);

      //action
      

      this->state = STATE_TURN_5d;

      //entry
      controller->positionReset();
controller->changeDriveMode(CW, 95);
printf("TURN_RIGHT\n");
t_start = 0;
t_end = 0;

    }
    break;
  case STATE_STOP5:
    if(((event & E_TRUE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RETURN3;

      //entry
      controller->positionReset();
controller->changeDriveMode(BACKWARD, 80);
printf("RETURN\n");

    }
    break;
  case STATE_RETURN3:
    if(((event & E_CHANGE_DISTANCE) != 0) && (positionValue.distance < -15)){
      // exit
      controller->changeDriveMode(STOP, 0);
sleep(1);

      //action
      

      this->state = STATE_STOP6;

      //entry
      controller->changeDriveMode(STOP, 0);
printf("STOP!!!\n");
    }
    break;
  case STATE_STOP6:
    if(((event & E_TRUE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_TURN_5d;

      //entry
      controller->positionReset();
controller->changeDriveMode(CW, 95);
printf("TURN_RIGHT\n");
t_start = 0;
t_end = 0;

    }
    break;
  default:
    break;
  }
}