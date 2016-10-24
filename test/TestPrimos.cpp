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
            primos = new Primos(0, 10);
        }
        
        virtual void TearDown() {
            delete primos;
        }
    
};

TEST_F(TestPrimos, Teste) {
    EXPECT_TRUE(primos->resultado(0) == 0);
    EXPECT_TRUE(primos->numeroResultados() == 0);
    EXPECT_STREQ(primos->nome().c_str(), "Calculo vazio");
}