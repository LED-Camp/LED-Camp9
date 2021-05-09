#include "Controller.hpp"

using namespace webots;

Controller* Controller::_instance = 0;

Controller* Controller::getInstance() {
    if (_instance == 0) {
        _instance = new Controller();
    }

    return _instance;
}

Controller::Controller() {
    this->robot = new Robot();
    twinWheelDriver = TwinWheelDriver::getInstance(robot, "motorL", "motorR");
}

Controller::~Controller(void) {
}


void Controller::changeDriveMode(Mode mode, int pwmDuty) {
    twinWheelDriver->changeDriveMode(mode, pwmDuty);
}

Robot* Controller::getRobot() {
    return this->robot;
}



