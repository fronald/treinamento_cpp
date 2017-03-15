#include <gtest/gtest.h>
#include <hippomocks.h>
#include <stdio.h>
#include <stdlib.h>
#include <Interceptador.h>
#include "Goulomb.h"

class TestGoulomb : public ::testing::Test { 

protected:

   Calculo* goulomb;
   
   virtual void SetUp( ) {
       goulomb = new Goulomb(0, 10);
       goulomb->calcula();
   }
 
   virtual void TearDown( ) { 
       goulomb->limpaCalculo();
       delete goulomb;
   }
   
};

class TestGoulombInterceptador : public ::testing::Test { 

protected:
   Calculo* goulomb;
   MockRepository *mocks;
   Interceptador *interceptador;
 
   virtual void SetUp( ) {
       mocks = new MockRepository();
       interceptador = mocks->Mock<Interceptador>();
       goulomb = new Goulomb(0, 10, interceptador);
       goulomb->calcula();
   }
 
   virtual void TearDown( ) {
       mocks->OnCallDestructor(interceptador);
       delete goulomb;
   }
   
};

TEST_F(TestGoulomb, TesteDeTamanho){
    EXPECT_TRUE(goulomb->numeroResultados() == 10);
}

TEST_F(TestGoulomb, TesteDeResultado){
    EXPECT_TRUE(goulomb->resultado(0) == 1);
    EXPECT_TRUE(goulomb->resultado(1) == 1);
    EXPECT_TRUE(goulomb->resultado(2) == 2);
    EXPECT_TRUE(goulomb->resultado(3) == 2);
    EXPECT_TRUE(goulomb->resultado(4) == 3);
    EXPECT_TRUE(goulomb->resultado(5) == 3);
    EXPECT_TRUE(goulomb->resultado(6) == 4);
    EXPECT_TRUE(goulomb->resultado(7) == 4);
    EXPECT_TRUE(goulomb->resultado(8) == 4);
    EXPECT_TRUE(goulomb->resultado(9) == 5);
    EXPECT_FALSE(goulomb->resultado(9) == 6);
}

TEST_F(TestGoulomb, TesteDeNome) {
    EXPECT_STREQ(goulomb->nome().c_str(), "Goulomb");
}

TEST_F(TestGoulomb, TesteToString) {
    EXPECT_STREQ(goulomb->toString(',').c_str(), "1,1,2,2,3,3,4,4,4,5");
    EXPECT_STREQ(goulomb->toString(';').c_str(), "1;1;2;2;3;3;4;4;4;5");
}

TEST_F(TestGoulombInterceptador, TesteDeResultadoZero) {
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(2).Return(2);
    //EXPECT_FALSE(goulomb->resultado(2) == 99);
    EXPECT_TRUE(goulomb->resultado(2) == 2);
//    printf("expect goulomb1 %d", goulomb->resultado(2));

}
