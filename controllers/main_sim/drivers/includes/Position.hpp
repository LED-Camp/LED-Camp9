#include <webots/PositionSensor.hpp>
#include <webots/Robot.hpp>

#ifndef __POSITION_H__
#define __POSITION_H__
#define L 0.03F * 3.1415926535897932384626433F
#define DEPTH 0.12
#define DOUBLE_PI 3.1415926535897932384626433F * 2
using namespace webots;

class Position {
private:    
    float angle;
    float distance;
    
protected:
  Position(Robot* robot, std::string ps_nameL, std::string ps_nameR);

public:
    static Position* _instance;
    PositionSensor* psL;
    PositionSensor* psR;
    static Position* getInstance(Robot* robot, std::string ps_nameL, std::string ps_nameR);
    void reset(void);
    void getPosition(float* distance, float* angle);
};

#endif
