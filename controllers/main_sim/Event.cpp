#include "includes/Event.hpp"

#include "iostream"
#include "includes/Controller.hpp"
#include "includes/CommonDefine.hpp"
#include <fcntl.h>

#define ABS_FLOAT(a) ((a) < 0.0F?(a)*-1.0F:(a))

using namespace webots;

Event::Event(Controller *controller) {
    this->event = 0;
    this->controller = controller;
    this->keyboard = Keyboard();
    this->oldKey = -1;
    this->rangeDistanceOld = 0.0F;
    keyboard.enable(100);
    this->distanceOld = 0.0F;
    this->angleOld = 0.0F;
}

int Event::updateEvent() {
    int key = keyboard.getKey();
    float distance;
    float angle;

    float absDistanceDiff;
    float absAngleDiff;

    float rangeDistance;

    rangeDistance = controller->getRange();

    if(key == 'Q'){
        return -1;
    }

    controller->getPosition(&distance, &angle);
    absDistanceDiff = ABS_FLOAT(this->distanceOld - distance);
    absAngleDiff = ABS_FLOAT(this->angleOld - angle);

    // TODO 測距センサの誤差で実質ここ常に発火してしまう
    if(rangeDistance != this->rangeDistanceOld){
        this->event |= E_CHANGE_RANGING;
    }else{
        this->event &= ~E_CHANGE_RANGING;
    }

    // E_UPイベント判定
    if (key == 'W') {
        this->event |= E_UP;
    } else {
        this->event &= ~E_UP;
    }

    // E_DOWNイベント判定
    if (key == 'S') {
        this->event |= E_DOWN;
    } else {
        this->event &= ~E_DOWN;
    }

    // E_LEFTイベント判定
    if (key == 'A') {
        this->event |= E_LEFT;
    } else {
        this->event &= ~E_LEFT;
    }

    // E_RIGHTイベント判定
    if (key == 'D') {
        this->event |= E_RIGHT;
    } else {
        this->event &= ~E_RIGHT;
    }
    key = -1;

    if (absDistanceDiff > 0.005) {
        this->event |= E_CHANGE_DISTANCE;
    } else {
        this->event &= ~E_CHANGE_DISTANCE;
    }

    if (absAngleDiff > 0.01) {
        this->event |= E_CHANGE_ANGLE;
    } else {
        this->event &= ~E_CHANGE_ANGLE;
    }

    this->distanceOld = distance;
    this->angleOld = angle;
    this->rangeDistanceOld = rangeDistance;

    printf("distance=%f,angle=%f\n", distance, angle);
    printf("range=%f\n", rangeDistance);

    return 0;
}

unsigned long Event::getEvent() {
    return this->event;
}
