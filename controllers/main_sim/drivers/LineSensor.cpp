#include "includes/LineSensor.hpp"
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include "includes/UserDefine.hpp"
#include "../includes/CommonDefine.hpp"
#include <cstdint>

LineSensor* LineSensor::_instance = 0;

LineSensor::LineSensor(
    Robot* robot,
    std::string sensorNameLeft,
    std::string sensorNameCenter,
    std::string sensorNameRight,
    int timeStep
) {
    this->sensorElementLeft = robot->getDistanceSensor(sensorNameLeft);
    this->sensorElementCenter = robot->getDistanceSensor(sensorNameCenter);
    this->sensorElementRight = robot->getDistanceSensor(sensorNameRight);
    this->sensorElementLeft->enable(timeStep);
    this->sensorElementCenter->enable(timeStep);
    this->sensorElementRight->enable(timeStep);
}

LineSensor* LineSensor::getInstance(
    Robot* robot,
    std::string sensorNameLeft,
    std::string sensorNameCenter,
    std::string sensorNameRight,
    int timeStep
){
    if (_instance == 0) {
        _instance = new LineSensor(
            robot,
            sensorNameLeft,
            sensorNameCenter,
            sensorNameRight,
            timeStep
        );
    }
    return _instance;
}

void LineSensor::getLineValue(int* left, int* center, int* right){
    if(this->sensorElementLeft->getValue() > THRESHOLD_LINE_VALUE) {
        *left = LINE_SENSOR_VALUE_BLACK;
    } else {
        *left = LINE_SENSOR_VALUE_WHITE;
    }
    if(this->sensorElementCenter->getValue() > THRESHOLD_LINE_VALUE) {
        *center = LINE_SENSOR_VALUE_BLACK;
    } else {
        *center = LINE_SENSOR_VALUE_WHITE;
    }
    if(this->sensorElementRight->getValue() > THRESHOLD_LINE_VALUE) {
        *right = LINE_SENSOR_VALUE_BLACK;
    } else {
        *right = LINE_SENSOR_VALUE_WHITE;
    }
}
