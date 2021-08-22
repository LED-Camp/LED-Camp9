#include "includes/LineSensor.hpp"
#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include "includes/UserDefine.hpp"
#include "../includes/CommonDefine.hpp"
#include <cstdint>

LineSensor* LineSensor::_instance = 0;

LineSensor::LineSensor(
    Supervisor* supervisor,
    std::string sensorNameLeft,
    std::string sensorNameCenter,
    std::string sensorNameRight,
    int timeStep
) {
    this->sensorElementLeft = supervisor->getDistanceSensor(sensorNameLeft);
    this->sensorElementCenter = supervisor->getDistanceSensor(sensorNameCenter);
    this->sensorElementRight = supervisor->getDistanceSensor(sensorNameRight);
    this->sensorElementLeft->enable(timeStep);
    this->sensorElementCenter->enable(timeStep);
    this->sensorElementRight->enable(timeStep);
}

LineSensor* LineSensor::getInstance(
    Supervisor* supervisor,
    std::string sensorNameLeft,
    std::string sensorNameCenter,
    std::string sensorNameRight,
    int timeStep
){
    if (_instance == 0) {
        _instance = new LineSensor(
            supervisor,
            sensorNameLeft,
            sensorNameCenter,
            sensorNameRight,
            timeStep
        );
    }
    return _instance;
}

LineValue LineSensor::getLineValue(){
    LineValue lineValue;
    if(this->sensorElementLeft->getValue() > THRESHOLD_LINE_VALUE) {
        lineValue.left = LINE_SENSOR_VALUE_BLACK;
    } else {
        lineValue.left = LINE_SENSOR_VALUE_WHITE;
    }
    if(this->sensorElementCenter->getValue() > THRESHOLD_LINE_VALUE) {
        lineValue.center = LINE_SENSOR_VALUE_BLACK;
    } else {
        lineValue.center = LINE_SENSOR_VALUE_WHITE;
    }
    if(this->sensorElementRight->getValue() > THRESHOLD_LINE_VALUE) {
        lineValue.right = LINE_SENSOR_VALUE_BLACK;
    } else {
        lineValue.right = LINE_SENSOR_VALUE_WHITE;
    }
    return lineValue;
}
