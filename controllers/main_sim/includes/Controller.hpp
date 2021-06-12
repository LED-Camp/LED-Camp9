#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include "drivers/includes/TwinWheelDriver.hpp"
#include "drivers/includes/Position.hpp"
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>

using namespace webots;
class Controller {
private:
    TwinWheelDriver* twinWheelDriver;
    Robot* robot;
    DistanceSensor* rangeSensor;
    DistanceSensor* colorSensor;
    DistanceSensor* lineSensorCenter; 
    DistanceSensor* lineSensorRight;
    DistanceSensor* lineSensorLeft;
protected:
    Controller();
    ~Controller(void);
public:
    static Controller* _instance;
    static Controller* getInstance();
    // twinWheelDriver系
    void changeDriveMode(Mode mode, int voltage_level);
    bool clockForward();
    
    Position *position;
    // Position系
    void positionReset(void);
    void getPosition(float* distance, float* angle);
    
    void outputSensorValues(); // センサ値出力(開発用)
    };
#endif
