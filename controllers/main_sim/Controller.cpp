#include "includes/Controller.hpp"
#include "includes/CommonDefine.hpp"
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
    // 測距センサ初期化
    this->rangeSensor = RangeSensor::getInstance(robot, "RangeSensor", TIME_STEP);
    // カラーセンサ初期化
    this->colorSensor = ColorSensor::getInstance(robot, "ColorSensor", TIME_STEP);
    // ラインセンサ初期化
    this->lineSensor = LineSensor::getInstance(
        robot,
        "LineSensorLeft",
        "LineSensorCenter",
        "LineSensorRight",
        TIME_STEP
    );
    // Positionセンサ初期化
    position = Position::getInstance(robot, "positionSensorL", "positionSensorR");
    // モータドライバ初期化
    twinWheelDriver = TwinWheelDriver::getInstance(robot, "motorL", "motorR");
}

Controller::~Controller(void) {
}

void Controller::positionReset(void) {
    position->reset();
}

void Controller::getPosition(float* distance, float* angle) {
    position->getPosition(distance, angle);
}

void Controller::changeDriveMode(Mode mode, int pwmDuty) {
    this->twinWheelDriver->changeDriveMode(mode, pwmDuty);
}

bool Controller::clockForward() {
    return this->robot->step(TIME_STEP) != -1;
}

float Controller::getRange() {
    return this->rangeSensor->getRange();
}

float Controller::getColorValue() {
    return this->colorSensor->getColorValue();
}

void Controller::getLineValue(float* left, float* center, float* right) {
    this->lineSensor->getLineValue(left, center, right);
}
