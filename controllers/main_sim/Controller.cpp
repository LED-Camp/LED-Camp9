#include "Controller.hpp"

using namespace webots;

Controller* Controller::_instance = 0;

Controller* Controller::getInstance(Robot* robot) {
    if (_instance == 0) {
        _instance = new Controller(robot);
    }

    return _instance;
}

Controller::Controller(Robot* robot) {
    this->robot = robot;
    twinWheelDriver = TwinWheelDriver::getInstance(robot, "motorL", "motorR");
}

Controller::~Controller(void) {
}


void Controller::changeDriveMode(Mode mode, int pwmDuty) {
    twinWheelDriver->changeDriveMode(mode, pwmDuty);
}



