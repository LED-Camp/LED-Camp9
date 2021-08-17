SRC_DIR := .

CXX_SOURCES += $(SRC_DIR)/main_sim.cpp
CXX_SOURCES += $(SRC_DIR)/Event.cpp
CXX_SOURCES += $(SRC_DIR)/Controller.cpp
CXX_SOURCES += $(SRC_DIR)/LEDTank.cpp
CXX_SOURCES += $(SRC_DIR)/drivers/TwinWheelDriver.cpp
CXX_SOURCES += $(SRC_DIR)/drivers/Position.cpp
CXX_SOURCES += $(SRC_DIR)/drivers/RangeSensor.cpp
CXX_SOURCES += $(SRC_DIR)/drivers/ColorSensor.cpp
CXX_SOURCES += $(SRC_DIR)/drivers/LineSensor.cpp
#CFLAGS := -Wall -O0
CFLAGS := -Wall -O0 

null :=
space := $(null) $(null)
WEBOTS_HOME_PATH=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))
include $(WEBOTS_HOME_PATH)/resources/Makefile.include
