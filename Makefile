CXX=g++
CXX_FLAGS=-g -O0 -std=c++11 -Wall -fexceptions 
UNAME=$(shell uname)
LDFLAGS= -Lext/lib/$(UNAME) -lgtest -lpthread
PWD=$(shell pwd)
INCLUDES=-Isrc
TEST_INCLUDES=-Isrc -Iext/include -Iext/include/gtest
APP=dist/calculo
APP_TEST=dist/unit_test
COVERAGE_DIR=dist/coverage

all: $(APP)

test: $(APP_TEST)

$(APP):
	mkdir -p output
	mkdir -p dist
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/Main.o src/Main.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/Calculo.o src/Calculo.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/Fibonacci.o src/Fibonacci.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/SalvaCalculo.o src/SalvaCalculo.cpp
	$(CXX) -o $(APP) output/Main.o output/Calculo.o output/Fibonacci.o output/SalvaCalculo.o

$(APP_TEST): $(APP)
	mkdir -p output
	mkdir -p dist
	$(CXX) $(CXX_FLAGS) $(TEST_INCLUDES) -c -o output/MainTest.o test/MainTest.cpp
	$(CXX) $(CXX_FLAGS) $(TEST_INCLUDES) -c -o output/TestFibonacci.o test/TestFibonacci.cpp
	$(CXX) -o $(APP_TEST) output/MainTest.o output/Calculo.o output/Fibonacci.o output/SalvaCalculo.o output/TestFibonacci.o $(LDFLAGS)
	

$(COVERAGE_DIR): test
	mkdir -p $(COVERAGE_DIR)
	kcov --skip-solibs --include-path=$(PWD)/src $(COVERAGE_DIR) $(APP_TEST)

kcov: $(COVERAGE_DIR)

clean:
	rm -Rf output
	rm -Rf dist
	rm -Rf $(COVERAGE_DIR)


