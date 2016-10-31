/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <hippomocks.h>
#include <gtest/gtest.h>

#include "Calculo.h"

MockRepository mocks;

class TestCalculo : public ::testing::Test {
    
    protected:
        
        Calculo* calculo;
        
        virtual void SetUp() {
            calculo = mocks.Mock<Calculo>();
            mocks.ExpectCall(calculo, Calculo::calcula);
            mocks.ExpectCall(calculo, Calculo::limpaCalculo);
            calculo->calcula();
        }
        
        virtual void TearDown() {
            calculo->limpaCalculo();
            delete calculo;
        }
    
};

TEST_F(TestCalculo, Test) {
    EXPECT_TRUE(calculo->resultado(0) == 0);
    EXPECT_TRUE(calculo->numeroResultados() == 0);
    EXPECT_STREQ(calculo->nome().c_str(), "Calculo vazio");
}

TEST_F(TestCalculo, TestInterface) {
    mocks.ExpectCall(calculo, Calculo::toString).Return("");
    mocks.ExpectCall(calculo, Calculo::numeroResultados);
    mocks.ExpectCall(calculo, Calculo::nome);
    EXPECT_TRUE(calculo->resultado(0) == 0);
    EXPECT_TRUE(calculo->numeroResultados() == 0);
    EXPECT_STREQ(calculo->nome().c_str(), "Calculo vazio");
    EXPECT_STREQ(calculo->nome().c_str(), "Calculo vazio");
}
