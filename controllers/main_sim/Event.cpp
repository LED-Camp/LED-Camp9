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
    this->old_key = -1;
    keyboard.enable(100);
}

int Event::updateEvent() {
    int key = keyboard.getKey();
    if(key == 'Q'){
        return -1;
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
    return 0;
}

unsigned long Event::getEvent() {
    return this->event;
}
