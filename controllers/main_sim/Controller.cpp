#include "Controller.hpp"
#include "CommonDefine.hpp"
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

bool Controller::clockForward() {
    return this->robot->step(TIME_STEP) != -1;
}
