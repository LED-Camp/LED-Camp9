#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include "TwinWheelDriver.hpp"
#include <webots/Robot.hpp>

using namespace webots;

class Controller {
private:
    TwinWheelDriver* twinWheelDriver;
    Robot* robot;
protected:
    Controller(Robot* robot);
    ~Controller(void);

public:
    static Controller* _instance;

    static Controller* getInstance(Robot* robot);
    // twinWheelDriver系
    void changeDriveMode(Mode mode, int voltage_level);
};

#endif
