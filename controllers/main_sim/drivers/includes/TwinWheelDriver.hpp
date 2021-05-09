#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

#ifndef __TWINWHEELDRIVER__
#define __TWINWHEELDRIVER__

using namespace webots;

#define MAX_SPEED 10

typedef enum {
  STOP, FORWARD, BACKWARD, CW, CCW,BRAKE
} Mode;

class TwinWheelDriver {
private:
    static TwinWheelDriver* _instance;
    Motor* motorL;
    Motor* motorR;
protected:
    TwinWheelDriver(Robot* robot, std::string motor_nameL, std::string motor_nameR);
public:
    ~TwinWheelDriver();

    static TwinWheelDriver* getInstance(Robot* robot, std::string motor_nameL, std::string motor_nameR);
    void changeDriveMode(Mode mode, int voltage_level);

};

#endif
