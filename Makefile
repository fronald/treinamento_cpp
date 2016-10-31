CXX=g++
IS_TEST=$(filter test,$(MAKECMDGOALS))
UNAME=$(shell uname)
CXX_FLAGS=-g -O0 -std=c++11 -Wall -fexceptions $(if $(IS_TEST),-DWITH_UNIT_TEST,-DNO_UNIT_TEST) -DOS_$(UNAME)
PWD=$(shell pwd)
INCLUDES=-Isrc
TEST_INCLUDES=-Iext/include -Iext/include/gtest -Iext/include/HippoMocks
LDFLAGS= $(if $(IS_TEST),-Lext/lib/$(UNAME) -lgtest -lpthread,)
DIST_DIR=dist
APP=$(DIST_DIR)/calculo
APP_TEST=$(DIST_DIR)/unit_test
COVERAGE_DIR=$(DIST_DIR)/coverage

SRC_DIR=src
SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_DIR=output
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

TEST_DIR=test
TEST_SRCS=$(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_DIR=$(OBJ_DIR)_tests
TEST_OBJS=$(patsubst $(TEST_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_SRCS))

all: $(APP)

test: $(APP_TEST)

$(APP): setup $(OBJS)
	$(CXX) -o $(APP) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< $(CXX_FLAGS) $(TEST_CXX_FLAGS) $(INCLUDES) -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) -c $< $(CXX_FLAGS) $(TEST_CXX_FLAGS) $(INCLUDES) $(TEST_INCLUDES) -o $@

setup: $(OBJ_DIR) $(DIST_DIR)
	
setup-test: setup $(TEST_OBJ_DIR)

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

$(APP_TEST): setup-test $(APP) $(TEST_OBJS)
	$(CXX) -o $(APP_TEST) $(OBJS) $(TEST_OBJS) $(LDFLAGS)
	

$(COVERAGE_DIR): test
	mkdir -p $(COVERAGE_DIR)
	kcov --skip-solibs --include-path=$(PWD)/src $(COVERAGE_DIR) $(APP_TEST)

kcov: $(COVERAGE_DIR)

clean:
	rm -Rf $(TEST_OBJ_DIR)
	rm -Rf $(OBJ_DIR)
	rm -Rf $(DIST_DIR)
	rm -Rf $(COVERAGE_DIR)


