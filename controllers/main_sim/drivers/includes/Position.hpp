#include <webots/PositionSensor.hpp>
#include <webots/Robot.hpp>

#ifndef __POSITION_H__
#define __POSITION_H__
#define RADIUS 0.015
#define TREAD 0.12
#define PI 3.1415926535897932384626433F
using namespace webots;

class Position {
  protected:
    Position(Robot *robot, std::string psNameL, std::string psNameR);

  public:
    static Position *_instance;
    PositionSensor *positionSensorL;
    PositionSensor *positionSensorR;
    static Position *getInstance(Robot *robot, std::string psNameL,
                                 std::string psNameR);
    void reset(void);
    void getPosition(float *distance, float *angle);
};

#endif
