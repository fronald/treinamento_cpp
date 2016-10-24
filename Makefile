CXX=g++
CXX_FLAGS=-g -O0 -Wall
UNAME=$(shell uname)
LDFLAGS=-Lext/lib/$(UNAME) -lgtest
INCLUDES=-Isrc
TEST_INCLUDES=-Isrc -Iext/include -Iext/include/gtest
APP=dist/calculo
APP_TEST=dist/unit_test

all: $(APP)

test: $(APP_TEST)

$(APP):
	mkdir -p output
	mkdir -p dist
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/main.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/Calculo.o src/Calculo.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/Fibonacci.o src/Fibonacci.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c -o output/SalvaCalculo.o src/SalvaCalculo.cpp
	$(CXX) -o $(APP) output/main.o output/Calculo.o output/Fibonacci.o output/SalvaCalculo.o

$(APP_TEST): $(APP)
	mkdir -p output
	mkdir -p dist
	$(CXX) $(CXX_FLAGS) $(TEST_INCLUDES) -c -o output/MainTest.o test/MainTest.cpp
	$(CXX) $(CXX_FLAGS) $(TEST_INCLUDES) -c -o output/TestFibonacci.o test/TestFibonacci.cpp
	$(CXX) -o $(APP_TEST) $(LDFLAGS) output/MainTest.o output/Calculo.o output/Fibonacci.o output/SalvaCalculo.o output/TestFibonacci.o
	

clean:
	rm -Rf output
	rm -Rf dist


