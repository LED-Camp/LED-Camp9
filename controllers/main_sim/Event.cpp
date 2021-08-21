#include "includes/Event.hpp"
#include "includes/Controller.hpp"
#include "drivers/includes/ColorSensor.hpp"
#include "drivers/includes/LineSensor.hpp"
#include "drivers/includes/Position.hpp"
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
    this->positionOld = (PositionValue){0.0F, 0.0F};
    this->colorOld = (ColorValue){0,0,0};
    this->lineValueOld = (LineValue){0,0,0};
}

int Event::updateEvent() {
    int key = keyboard.getKey();

    float absDistanceDiff;
    float absAngleDiff;

    float rangeDistance;

    ColorValue color;
    PositionValue position;

    LineValue lineValue;
    
    rangeDistance = controller->getRange();
    color = controller->getColorValue();
    lineValue = controller->getLineValue();
    bool lineSensorChanged =
        (lineValue.left != this->lineValueOld.left) ||
        (lineValue.center != this->lineValueOld.center) ||
        (lineValue.right != this->lineValueOld.right);

    if(key == 'Q'){
        return -1;
    }

    position = controller->getPosition();
    absDistanceDiff = ABS_FLOAT(this->positionOld.distance - position.distance);
    absAngleDiff = ABS_FLOAT(this->positionOld.angle - position.angle);

    // TODO 測距センサの誤差で実質ここ常に発火してしまう
    if(rangeDistance != this->rangeDistanceOld){
        this->event |= E_CHANGE_RANGING;
    }else{
        this->event &= ~E_CHANGE_RANGING;
    }

    if(color.red != this->colorOld.red
        || color.green != this->colorOld.green
        || color.blue != this->colorOld.blue){
        this->event |= E_CHANGE_COLOR;
    }else{

        this->event &= ~E_CHANGE_COLOR;
    }

    if(lineSensorChanged){
        this->event |= E_CHANGE_AREA;
    }else{
        this->event &= ~E_CHANGE_AREA;
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

<<<<<<< HEAD
    if (absDistanceDiff > 0.001) {
=======
    if (absDistanceDiff > 0.00005) {
>>>>>>> fix: 距離エンコーダの変化を検出するイベントが発火しない現象を解消
        this->event |= E_CHANGE_DISTANCE;
    } else {
        this->event &= ~E_CHANGE_DISTANCE;
    }

    if (absAngleDiff > 0.01) {
        this->event |= E_CHANGE_ANGLE;
    } else {
        this->event &= ~E_CHANGE_ANGLE;
    }

    this->positionOld = position;
    this->rangeDistanceOld = rangeDistance;
    this->colorOld = color;
    this->lineValueOld = lineValue;
    printf("distance=%f, angle=%f \n", position.distance, position.angle);
    printf("range=%f \n", rangeDistance);
    printf("color: R=%d, G=%d, B=%d \n", color.red, color.green, color.blue);
    printf("line: l=%d, c=%d, r=%d \n", lineValue.left, lineValue.center, lineValue.right);
    return 0;
}

unsigned long Event::getEvent() {
    return this->event;
}
