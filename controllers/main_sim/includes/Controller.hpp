#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include "drivers/includes/TwinWheelDriver.hpp"
#include "drivers/includes/RangeSensor.hpp"
#include "drivers/includes/Position.hpp"
#include "drivers/includes/ColorSensor.hpp"
#include "drivers/includes/LineSensor.hpp"
#include <webots/Camera.hpp>
#include "ColorValue.hpp"
#include "LineValue.hpp"
#include "PositionValue.hpp"

using namespace webots;
class Controller {
private:
    Supervisor* supervisor;
    RangeSensor* rangeSensor;
    TwinWheelDriver* twinWheelDriver;
    ColorSensor* colorSensor;
    LineSensor* lineSensor;
protected:
    Controller();
    ~Controller(void);
public:
    static Controller* _instance;
    static Controller* getInstance();

    // 共通
    bool clockForward();
    void stopSimuration();
    bool timeUp(double limitTime);
    // twinWheelDriver系
    void changeDriveMode(Mode mode, int voltage_level);
    //  Range系
    float getRange();
    // Position系
    Position *position;
    void positionReset(void);
    PositionValue getPosition();
    // Color系
    ColorValue getColorValue();
    //LineSensor系
    LineValue getLineValue();

    void tankSleep(int msec);
};

#endif
