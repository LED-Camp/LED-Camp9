#include <cstdint>
#include <webots/DistanceSensor.hpp>
#include <webots/Robot.hpp>

#ifndef __RANGE_SENSOR__
#define __RANGE_SENSOR__

using namespace webots;

class RangeSensor {
  private:
    DistanceSensor *sensorElement;

  public:
    RangeSensor(Robot *robot, std::string sensorName, int timeStep);
    ~RangeSensor();
    static RangeSensor *_instance;
    static RangeSensor *getInstance(Robot *robot, std::string sensorName,
                                    int timeStep);
    float getRange();
};

#endif //__RANGE_SENSOR__
