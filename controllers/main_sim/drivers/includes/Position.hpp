#include <webots/PositionSensor.hpp>
#include <webots/Supervisor.hpp>
#include "PositionValue.hpp"


#ifndef __POSITION_H__
#define __POSITION_H__
#define RADIUS 0.015
#define TREAD 12.0
#define PI 3.1415926535897932384626433F
using namespace webots;

class Position {
protected:
  Position(Supervisor* supervisor, std::string psNameL, std::string psNameR);

public:
    static Position* _instance;
    PositionSensor* positionSensorL;
    PositionSensor* positionSensorR;
    static Position* getInstance(Supervisor* supervisor, std::string psNameL, std::string psNameR);
    void reset(void);
    PositionValue getPosition();
};

#endif
