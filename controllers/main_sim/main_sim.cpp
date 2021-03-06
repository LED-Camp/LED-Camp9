
#include <iostream>
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include "includes/Event.hpp"
#include "includes/Controller.hpp"
#include "LEDTank.hpp"

using namespace webots;

/**
 * simmain
 */
int main(int argc, char **argv) {
  Controller *controller;
  LEDTank *lEDTank;
  Event *event;

  controller = Controller::getInstance();
  lEDTank = new LEDTank(controller);
  event = new Event(controller);

  while (controller->clockForward()) {
    if(event->updateEvent() < 0 || controller->timeUp(COMPETITION_TIME)){
        controller->changeDriveMode(STOP, 0);
        controller->clockForward();
        break;
     }
    lEDTank->execState();
    lEDTank->doTransition(event->getEvent());
  }
  controller->stopSimuration();
  delete lEDTank;
  delete event;
  return 0;
}
