#include <cstdint>
#include <webots/DistanceSensor.hpp>
#include <webots/Robot.hpp>

#ifndef __COLOER_SENSOR__
#define __COLOER_SENSOR__

using namespace webots;

class ColorSensor {
  private:
    DistanceSensor *sensorElement;

  public:
    ColorSensor(Robot *robot, std::string sensorName, int timeStep);
    ~ColorSensor();
    static ColorSensor *_instance;
    static ColorSensor *getInstance(Robot *robot, std::string sensorName,
                                    int timeStep);
    void Initialize();
    float getColorValue();
};

#endif //__COLOR_SENSOR__
