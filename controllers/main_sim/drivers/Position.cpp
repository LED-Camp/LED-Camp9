#include "includes/Position.hpp"
#include <stdio.h>
#include "includes/UserDefine.hpp"
#include "../includes/CommonDefine.hpp"
using namespace webots;



static float referPositionL;
static float referPositionR;

/*******************************************/
Position* Position::_instance = 0;

<<<<<<< HEAD
Position* Position::getInstance(Robot* robot, std::string psNameL, std::string psNameR) {
    if (_instance == 0) {
        _instance = new Position(robot, psNameL, psNameR);
=======
Position* Position::getInstance(Robot* robot, std::string ps_nameL, std::string ps_nameR) {
    if (_instance == 0) {
        _instance = new Position(robot, ps_nameL, ps_nameR);
>>>>>>> edit: Positionセンサから値取得・表示・APIで距離角度を取得できるようにした
    }

    return _instance;
}


Position::Position(Robot* robot, std::string psNameL, std::string psNameR) {
    this->positionSensorL = robot->getPositionSensor(psNameL);
    positionSensorL->enable(TIME_STEP);
    this->positionSensorR = robot->getPositionSensor(psNameR);
    positionSensorR->enable(TIME_STEP);
}

void Position::reset(void) {
    referPositionL  = positionSensorL->getValue();
    referPositionR  = positionSensorR->getValue();
}

void Position::getPosition(float* distance, float* angle) {
    float l;
    float r;
    float radNowL;
    float radNowR;
    float distanceTemp;

    radNowL = positionSensorL->getValue();
    radNowR = positionSensorR->getValue();
    l = (radNowL - referPositionL) * RADIUS;
    r = (radNowR - referPositionR) * RADIUS;

    distanceTemp = (l + r) / 2.0;
    *angle = (( l - r ) / TREAD) * 180.0 / PI;
    *distance = distanceTemp;
}
