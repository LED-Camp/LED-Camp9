#include "includes/TwinWheelDriver.hpp"
#include "includes/UserDefine.hpp"
#include <stdio.h>

using namespace webots;

TwinWheelDriver *TwinWheelDriver::_instance = 0;

TwinWheelDriver *TwinWheelDriver::getInstance(Robot *robot,
                                              std::string motorNameL,
                                              std::string motorNameR) {
    if(_instance == 0) {
        _instance = new TwinWheelDriver(robot, motorNameL, motorNameR);
    }

    return _instance;
}

TwinWheelDriver::TwinWheelDriver(Robot *robot, std::string motorNameL,
                                 std::string motorNameR) {
    this->motorL = robot->getMotor(motorNameL);
    motorL->setPosition(INFINITY);
    this->motorR = robot->getMotor(motorNameR);
    motorR->setPosition(INFINITY);
}

void TwinWheelDriver::changeDriveMode(Mode mode, int voltageLevel) {
    // voltage_level : 0〜100
    double l =
        ((double)voltageLevel * MAX_SPEED / 100.0) * (L_MOTOR_COFF / 100);
    double r =
        ((double)voltageLevel * MAX_SPEED / 100.0) * (R_MOTOR_COFF / 100);

    if(mode == STOP) {
        motorL->setVelocity(0.0);
        motorR->setVelocity(0.0);
    } else if(mode == FORWARD) {
        motorL->setVelocity(l);
        motorR->setVelocity(r);
    } else if(mode == BACKWARD) {
        motorL->setVelocity(-l);
        motorR->setVelocity(-r);
    } else if(mode == CW) {
        motorL->setVelocity(l);
        motorR->setVelocity(-r);
    } else if(mode == CCW) {
        motorL->setVelocity(-l);
        motorR->setVelocity(r);
    }
}
