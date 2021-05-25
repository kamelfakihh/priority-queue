# make all
# make clean
# make program
# make build
# make release
# make debug
# make test
# make info
# make run

CC = g++
INCLUDE = -I./include
CPPFLAGS = -Wall -fexceptions
RELEASE_FLAGS = -O2
DEBUG_FLAGS = -pedantic-errors -Wextra -Weffc++ -g
LDFLAGS = 
BUILD = ./build
OBJ_DIR = ${BUILD}/objs
BIN_DIR = ${BUILD}/bin
TARGET = program

SRC = $(wildcard src/*.cpp) src/PriorityQueue/MaxPQ.cpp	src/PriorityQueue/MinPQ.cpp src/test/testmain.cpp 	
# FILES = $(notdir ${SRC})
# OBJECTS = $(patsubst %.cpp,%.o, ${SRC})
OBJECTS  = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d) 	

all: build $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

# tells make that these commands are special targets (not associated with actual files)
.PHONY: all build clean debug release info test run

build:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CPPFLAGS += ${DEBUG_FLAGS}
debug: all

release: CPPFLAGS += ${RELEASE_FLAGS}
release: all

# run the executable
run:  
	$(BIN_DIR)/$(TARGET)

# predefine TEST as a macro to compile test code only
test:  CPPFLAGS += -DTEST
test:  debug
test:  run				# execute program after compilation (can be execluded)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(BIN_DIR)/*

info:
	@echo "[*] Application dir: ${BIN_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
