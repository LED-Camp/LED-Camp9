#include "includes/Position.hpp"
#include <stdio.h>
#include "includes/UserDefine.hpp"
#include "../includes/CommonDefine.hpp"
using namespace webots;

static float referPosL;
static float referPosR;
#define ABS_FUNC(x) ((x) < 0 ? -(x) : (x))

/*******************************************/
Position* Position::_instance = 0;

Position* Position::getInstance(Robot* robot, std::string ps_nameL, std::string ps_nameR) {
    if (_instance == 0) {
        _instance = new Position(robot, ps_nameL, ps_nameR);
    }

    return _instance;
}

Position::Position(Robot* robot, std::string ps_nameL, std::string ps_nameR) :
        angle(0.0F), distance(0.0F) {
    this->psL = robot->getPositionSensor(ps_nameL);
    psL->enable(TIME_STEP);
    this->psR = robot->getPositionSensor(ps_nameR);
    psR->enable(TIME_STEP);
}

void Position::reset(void) {
    referPosL  = psL->getValue();
    referPosR  = psR->getValue();
}

void Position::getPosition(float* distance, float* angle) {
    float l;
    float r;
    float radNowL;
    float radNowR;
    float distanceTemp;

    radNowL = psL->getValue();
    radNowR = psR->getValue();
    //l = (radNowL - referPosL)/DOUBLE_PI * L;
    //r = (radNowR - referPosR)/DOUBLE_PI * L;
    l = (radNowL - referPosL) * L;
    r = (radNowR - referPosR) * L;
    printf(">>>>>>>>>%f, %f\n", radNowL, radNowR);

    distanceTemp = (l + r) / 2.0;
    *angle = ((( l - r ) / DEPTH) * 180.0) / PI;
    *distance = distanceTemp;
}
