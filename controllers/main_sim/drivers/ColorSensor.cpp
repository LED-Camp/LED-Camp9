#include "includes/ColorSensor.hpp"
#include <cstdint>
#include <webots/DistanceSensor.hpp>
#include <webots/Robot.hpp>

using namespace webots;
ColorSensor *ColorSensor::_instance = 0;

ColorSensor::ColorSensor(Robot *robot, std::string sensorName, int timeStep) {
    this->sensorElement = robot->getDistanceSensor(sensorName);
    this->sensorElement->enable(timeStep);
}

ColorSensor::~ColorSensor() {}

ColorSensor *ColorSensor::getInstance(Robot *robot, std::string sensorName,
                                      int timeStep) {
    if(_instance == 0) {
        _instance = new ColorSensor(robot, sensorName, timeStep);
    }

    return _instance;
}

float ColorSensor::getColorValue() { return this->sensorElement->getValue(); }
