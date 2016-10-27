/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <gtest/gtest.h>

#include "Calculo.h"

class TestCalculo: public ::testing::Test { 

protected:
   Calculo* calculo;
 
   virtual void SetUp( ) {
       calculo = new Calculo(0, 10);
       calculo->calcula();
    }
 
   virtual void TearDown( ) { 
       calculo->limpaCalculo();
       delete calculo;
    }
   
};

TEST_F(TestCalculo, TesteDeTamanho){
    EXPECT_TRUE(calculo->numeroResultados() == 10);
}

TEST_F(TestCalculo, TesteDeResultado){
    EXPECT_TRUE(calculo->resultado(0) == 0);
    
}

TEST_F(TestCalculo, TesteDeNome){
    EXPECT_TRUE(calculo->nome() == "Calculo vazio");
}