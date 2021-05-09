#include "TwinWheelDriver.hpp"
#include "UserDefine.hpp"
#include <stdio.h>

using namespace webots;

TwinWheelDriver* TwinWheelDriver::_instance = 0;

TwinWheelDriver* TwinWheelDriver::getInstance(Robot* robot, std::string motor_nameL, std::string motor_nameR) {
    if (_instance == 0) {
      _instance = new TwinWheelDriver(robot, motor_nameL, motor_nameR);
    }

    return _instance;
}

TwinWheelDriver::TwinWheelDriver(Robot* robot, std::string motor_nameL, std::string motor_nameR) {
  this->motorL = robot->getMotor(motor_nameL);
  motorL->setPosition(INFINITY);
  this->motorR = robot->getMotor(motor_nameR);
  motorR->setPosition(INFINITY);
}

void TwinWheelDriver::changeDriveMode(Mode mode, int voltage_level) {
    //voltage_level : 0〜100
    double l = ((double) voltage_level * MAX_SPEED / 100.0) * (L_MOTOR_COFF / 100) ;
    double r = ((double) voltage_level * MAX_SPEED / 100.0) * (R_MOTOR_COFF / 100) ;

    if (mode == STOP) {
        motorL->setVelocity(0.0);
        motorR->setVelocity(0.0);
    } else if (mode == FORWARD) {
        motorL->setVelocity(l);
        motorR->setVelocity(r);
    } else if (mode == BACKWARD) {
        motorL->setVelocity(-l);
        motorR->setVelocity(-r);
    } else if (mode == CW) {
        motorL->setVelocity(l);
        motorR->setVelocity(-r);
    } else if (mode == CCW) {
        motorL->setVelocity(-l);
        motorR->setVelocity(r);
    }
}
