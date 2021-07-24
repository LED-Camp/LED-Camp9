#include "includes/ColorSensor.hpp"
#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include <cstdint>

using namespace webots;
ColorSensor* ColorSensor::_instance = 0;

ColorSensor::ColorSensor(Supervisor* supervisor, std::string sensorName, int timeStep) {
    this->sensorElement = supervisor->getDistanceSensor(sensorName);
    this->sensorElement->enable(timeStep);
}

ColorSensor::~ColorSensor() {

}

ColorSensor* ColorSensor::getInstance(Supervisor* supervisor, std::string sensorName, int timeStep) {
    if (_instance == 0) {
        _instance = new ColorSensor(supervisor, sensorName, timeStep);
    }

    return _instance;
}

float ColorSensor::getColorValue() {
    return this->sensorElement->getValue();
}
