SRC_DIR := .

CXX_SOURCES += main_sim.cpp
CXX_SOURCES += Event.cpp
CXX_SOURCES += Controller.cpp
CXX_SOURCES += LEDTank.cpp
CXX_SOURCES += drivers/TwinWheelDriver.cpp
# TODO 実験モードと本番モードで切り替える方法
#CFLAGS := -Wall -O0
CFLAGS := -Wall -O0 -D 'EXPERIMENTAL_USE' -D 'SIM_USE'

null :=
space := $(null) $(null)
WEBOTS_HOME_PATH=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))
include $(WEBOTS_HOME_PATH)/resources/Makefile.include
