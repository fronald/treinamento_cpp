/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <gtest/gtest.h>

#include "Primos.h"

class TestPrimos : public ::testing::Test {
    
    protected:
        Calculo* primos;
        
        virtual void SetUp() {
            primos = new Primos();
        }
        
        virtual void TearDown() {
            delete primos;
        }
    
};

TEST_F(TestPrimos, Teste) {
    EXPECT_TRUE(primos->resultado(0) == 0);
    EXPECT_TRUE(primos->numeroResultados() == 0);
}


////////////////////


class TestPrimosInitialize : public ::testing::Test { 

protected:
   Calculo* primos;
 
   virtual void SetUp( ) {
       primos = new Primos(0, 10);
       primos->calcula();
   }
 
   virtual void TearDown( ) { 
       primos->limpaCalculo();
       delete primos;
   }
   
};

TEST_F(TestPrimosInitialize, TesteDeTamanho){
    EXPECT_TRUE(primos->numeroResultados() == 10);
}

TEST_F(TestPrimosInitialize, TesteDeResultado){
    EXPECT_TRUE(primos->resultado(0) == 2);
    EXPECT_TRUE(primos->resultado(1) == 3);
    EXPECT_TRUE(primos->resultado(2) == 5);
    EXPECT_TRUE(primos->resultado(3) == 7);
    EXPECT_TRUE(primos->resultado(4) == 11);
    EXPECT_TRUE(primos->resultado(5) == 13);
    EXPECT_TRUE(primos->resultado(6) == 17);
    EXPECT_TRUE(primos->resultado(7) == 19);
    EXPECT_TRUE(primos->resultado(8) == 23);
    EXPECT_TRUE(primos->resultado(9) == 29);
    EXPECT_FALSE(primos->resultado(9) == 30);
}

TEST_F(TestPrimosInitialize, TesteDeNome) {
    EXPECT_STREQ(primos->nome().c_str(), "Primos");
}

TEST_F(TestPrimosInitialize, TesteToString) {
    EXPECT_STREQ(primos->toString(',').c_str(), "2,3,5,7,11,13,17,19,23,29");
    EXPECT_STREQ(primos->toString(';').c_str(), "2;3;5;7;11;13;17;19;23;29");
}
