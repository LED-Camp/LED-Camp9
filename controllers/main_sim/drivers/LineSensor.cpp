#include "includes/LineSensor.hpp"
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include "includes/UserDefine.hpp"
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

void LineSensor::getLineValue(std::string* left, std::string* center, std::string* right){
    if(this->sensorElementLeft->getValue() > THRESHOLD_LINE_VALUE) {
        *left = "black";
    } else {
        *left = "white";
    }
    if(this->sensorElementCenter->getValue() > THRESHOLD_LINE_VALUE) {
        *center = "black";
    } else {
        *center = "white";
    }
    if(this->sensorElementRight->getValue() > THRESHOLD_LINE_VALUE) {
        *right = "black";
    } else {
        *right = "white";
    }
}
