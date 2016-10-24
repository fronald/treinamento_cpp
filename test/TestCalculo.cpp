/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <gtest/gtest.h>

#include "Calculo.h"

class TestCalculo : public ::testing::Test {
    
    protected:
        Calculo* calculo;
        
        virtual void SetUp() {
            calculo = new Calculo();
            calculo->calcula();
            calculo->limpaCalculo();
        }
        
        virtual void TearDown() {
            delete calculo;
        }
    
};

TEST_F(TestCalculo, Test) {
    EXPECT_TRUE(calculo->resultado(0) == 0);
    EXPECT_TRUE(calculo->numeroResultados() == 0);
    EXPECT_STREQ(calculo->nome().c_str(), "Calculo vazio");
}