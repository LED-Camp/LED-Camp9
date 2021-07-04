#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include "drivers/includes/TwinWheelDriver.hpp"
#include "drivers/includes/RangeSensor.hpp"
#include "drivers/includes/Position.hpp"
#include "drivers/includes/ColorSensor.hpp"
#include "drivers/includes/LineSensor.hpp"

using namespace webots;
class Controller {
private:
    Robot* robot;
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
    // twinWheelDriver系
    void changeDriveMode(Mode mode, int voltage_level);
    //  Range系
    float getRange();
    // Position系
    Position *position;
    void positionReset(void);
    void getPosition(float* distance, float* angle);
    // Color系
    float getColorValue();
    //LineSensor系
    void getLineValue(float* left, float* center, float* right);
};

#endif
