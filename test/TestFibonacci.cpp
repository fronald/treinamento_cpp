#include <gtest/gtest.h>
#include <hippomocks.h>

#include "Fibonacci.h"

class TestFibonacci : public ::testing::Test { 

protected:

   Calculo* fibonacci;
   
   virtual void SetUp( ) {
       fibonacci = new Fibonacci(0, 10);
       fibonacci->calcula();
   }
 
   virtual void TearDown( ) { 
       fibonacci->limpaCalculo();
       delete fibonacci;
   }
   
};

class TestFibonacciInterceptador : public ::testing::Test { 

protected:
   Calculo* fibonacci;
   MockRepository *mocks;
   Interceptador *interceptador;
 
   virtual void SetUp( ) {
       mocks = new MockRepository();
       interceptador = mocks->Mock<Interceptador>();
       fibonacci = new Fibonacci(0, 10, interceptador);
       fibonacci->calcula();
   }
 
   virtual void TearDown( ) {
       mocks->OnCallDestructor(interceptador);
       delete fibonacci;
   }
   
};

TEST_F(TestFibonacci, TesteDeTamanho){
    EXPECT_TRUE(fibonacci->numeroResultados() == 10);
}

TEST_F(TestFibonacci, TesteDeResultado){
    EXPECT_TRUE(fibonacci->resultado(0) == 0);
    EXPECT_TRUE(fibonacci->resultado(1) == 1);
    EXPECT_TRUE(fibonacci->resultado(2) == 1);
    EXPECT_TRUE(fibonacci->resultado(3) == 2);
    EXPECT_TRUE(fibonacci->resultado(4) == 3);
    EXPECT_TRUE(fibonacci->resultado(5) == 5);
    EXPECT_TRUE(fibonacci->resultado(6) == 8);
    EXPECT_TRUE(fibonacci->resultado(7) == 13);
    EXPECT_TRUE(fibonacci->resultado(8) == 21);
    EXPECT_TRUE(fibonacci->resultado(9) == 34);
    EXPECT_FALSE(fibonacci->resultado(9) == 35);
}

TEST_F(TestFibonacci, TesteDeNome) {
    EXPECT_STREQ(fibonacci->nome().c_str(), "Fibonacci");
}

TEST_F(TestFibonacci, TesteToString) {
    EXPECT_STREQ(fibonacci->toString(',').c_str(), "0,1,1,2,3,5,8,13,21,34");
    EXPECT_STREQ(fibonacci->toString(';').c_str(), "0;1;1;2;3;5;8;13;21;34");
}

TEST_F(TestFibonacciInterceptador, TesteDeResultadoZero) {
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(2).Return(15);
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(3).Return(66);
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(8).Return(44);
    EXPECT_TRUE(fibonacci->resultado(3) == 15);
    EXPECT_FALSE(fibonacci->resultado(4) == 99);
    EXPECT_TRUE(fibonacci->resultado(6) == 44);
}