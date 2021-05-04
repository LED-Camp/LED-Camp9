// File:          controller_for_sim.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <iostream>
#include <stdio.h>
#include <webots/Robot.hpp>
#include "Event.hpp"
#include "Controller.hpp"
#include "LEDTank.hpp"
#include "CommonDefine.hpp"

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  Controller *controller;
  LEDTank *lEDTank;
  Event *event;
  Robot *robot;
  // create the Robot instance.
  robot = new Robot();
  controller = Controller::getInstance(robot);
  lEDTank = new LEDTank(controller);
  event = new Event(controller);

  // get the time step of the current world.
  //int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(TIME_STEP) != -1) {
    if(event->updateEvent() < 0){
        printf("STOP\n");
        controller->changeDriveMode(STOP, 0);
        break;
     }
    lEDTank->execState();
    lEDTank->doTransition(event->getEvent());
  };

  // Enter here exit cleanup code.

  delete lEDTank;
  delete event;
  return 0;
}
