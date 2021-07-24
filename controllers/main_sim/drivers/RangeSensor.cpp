#include "includes/RangeSensor.hpp"
#include <cstdint>
#include <webots/DistanceSensor.hpp>
#include <webots/Robot.hpp>

using namespace webots;

RangeSensor *RangeSensor::_instance = 0;

RangeSensor::RangeSensor(Robot *robot, std::string sensorName, int timeStep) {
    this->sensorElement = robot->getDistanceSensor(sensorName);
    this->sensorElement->enable(timeStep);
}

RangeSensor::~RangeSensor() {}

RangeSensor *RangeSensor::getInstance(Robot *robot, std::string sensorName,
                                      int timeStep) {
    if(_instance == 0) {
        _instance = new RangeSensor(robot, sensorName, timeStep);
    }
    return _instance;
}

float RangeSensor::getRange() {
    return this->sensorElement->getValue(); // cm
}
