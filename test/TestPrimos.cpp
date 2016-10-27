/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <gtest/gtest.h>

#include "Primos.h"

class TestPrimos: public ::testing::Test { 

protected:
   Primos* primos;
 
   virtual void SetUp( ) {
       primos = new Primos(0, 10);
       primos->calcula();
   }
 
   virtual void TearDown( ) { 
       primos->limpaCalculo();
       delete primos;
   }
   
};


TEST_F(TestPrimos, TesteDeTamanho){
    EXPECT_TRUE(primos->numeroResultados() == 10);
}




TEST_F(TestPrimos, TesteDeResultado){
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
    EXPECT_TRUE(primos->resultado(10) == 0);
    EXPECT_FALSE(primos->resultado(9) == 20);
}



TEST_F(TestPrimos, TesteDeNome){
    EXPECT_TRUE(primos->nome() == "Primos");
}