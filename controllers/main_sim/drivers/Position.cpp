#include "includes/Position.hpp"
#include <stdio.h>
#include "includes/UserDefine.hpp"
#include "../includes/CommonDefine.hpp"
using namespace webots;

static float referPositionL;
static float referPositionR;

/*******************************************/
Position* Position::_instance = 0;

Position* Position::getInstance(Supervisor* supervisor, std::string psNameL, std::string psNameR) {
    if (_instance == 0) {
        _instance = new Position(supervisor, psNameL, psNameR);
    }

    return _instance;
}



Position::Position(Supervisor* supervisor, std::string psNameL, std::string psNameR) {
    this->positionSensorL = supervisor->getPositionSensor(psNameL);
    positionSensorL->enable(TIME_STEP);
    this->positionSensorR = supervisor->getPositionSensor(psNameR);
    positionSensorR->enable(TIME_STEP);
}

void Position::reset(void) {
    referPositionL  = positionSensorL->getValue() * 100;
    referPositionR  = positionSensorR->getValue() * 100;
}

PositionValue Position::getPosition() {
    float l;
    float r;
    float radNowL;
    float radNowR;

    radNowL = positionSensorL->getValue();
    radNowR = positionSensorR->getValue();
    //m単位→cm単位（実機との整合のため）
    radNowL = radNowL * 100;
    radNowR = radNowR * 100;

    l = (radNowL - referPositionL) * RADIUS;
    r = (radNowR - referPositionR) * RADIUS;

    return (PositionValue){
        (float)((l + r) / 2.0), //distance
        (float)((( l - r ) / TREAD) * 180.0 / PI) //angle
    };
}
