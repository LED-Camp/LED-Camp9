SRC_DIR := .
CXX_SOURCES=$(shell find $(SRC_DIR) -name "*.cpp")
CFLAGS := -Wall -O0

null :=
space := $(null) $(null)
WEBOTS_HOME_PATH=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))
include $(WEBOTS_HOME_PATH)/resources/Makefile.include
