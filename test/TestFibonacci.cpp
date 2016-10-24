#include <gtest/gtest.h>

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

class TestFibonacciFail : public ::testing::Test { 

protected:
   Calculo* fibonacci;
 
   virtual void SetUp( ) {
       fibonacci = new Fibonacci(0, 0);
   }
 
   virtual void TearDown( ) { 
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

TEST_F(TestFibonacciFail, TesteDeResultadoZero) {
    EXPECT_TRUE(fibonacci->resultado(0) == 0);
}