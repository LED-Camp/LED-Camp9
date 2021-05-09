#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include "drivers/includes/TwinWheelDriver.hpp"
#include <webots/Robot.hpp>

using namespace webots;
class Controller {
private:
    TwinWheelDriver* twinWheelDriver;
    Robot* robot;
protected:
    Controller();
    ~Controller(void);
public:
    static Controller* _instance;
    static Controller* getInstance();
    // twinWheelDriver系
    void changeDriveMode(Mode mode, int voltage_level);
    bool clockForward();
};

#endif
