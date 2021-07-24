#include "includes/Controller.hpp"
#include "includes/Event.hpp"
#include "includes/LEDTank.hpp"
#include <iostream>
#include <webots/DistanceSensor.hpp>
#include <webots/Robot.hpp>

using namespace webots;

int main(int argc, char **argv) {
    Controller *controller;
    LEDTank *lEDTank;
    Event *event;

    controller = Controller::getInstance();
    lEDTank = new LEDTank(controller);
    event = new Event(controller);

    while(controller->clockForward()) {
        if(event->updateEvent() < 0) {
            printf("STOP\n");
            controller->changeDriveMode(STOP, 0);
            break;
        }
        lEDTank->execState();
        lEDTank->doTransition(event->getEvent());
    };

    delete lEDTank;
    delete event;
    return 0;
}
