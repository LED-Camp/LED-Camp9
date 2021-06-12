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
    this->rangeDistanceOld = 0;
    keyboard.enable(100);
}

int Event::updateEvent() {
    int key = keyboard.getKey();
    float rangeDistance;

    rangeDistance = controller->getRange();
    if(key == 'Q'){
        return -1;
    }

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

    this->rangeDistanceOld = rangeDistance;
    printf("range=%f\n", rangeDistance);

    return 0;
}

unsigned long Event::getEvent() {
    return this->event;
}
