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
    //カラーセンサ初期化
    this->colorSensor = robot->getDistanceSensor("ColorSensor");
    colorSensor->enable(TIME_STEP);
    //ラインセンサ（中央，左，右）初期化
    this->lineSensorCenter = robot->getDistanceSensor("LineSensorCenter");
    lineSensorCenter->enable(TIME_STEP);
    this->lineSensorRight = robot->getDistanceSensor("LineSensorRight");
    lineSensorRight->enable(TIME_STEP);
    this->lineSensorLeft = robot->getDistanceSensor("LineSensorLeft");
    lineSensorLeft->enable(TIME_STEP);
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

void Controller::outputSensorValues() { //センサ値の取得・出力コード（開発用）
  std::cout << "color value:" << colorSensor->getValue() << std::endl;
  std::cout << "line left:" << lineSensorLeft->getValue()
    << " center:" << lineSensorCenter->getValue()
    << " right:" << lineSensorRight->getValue()
    << std::endl;
};
