/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <gtest/gtest.h>

#include "SalvaCalculo.h"
#include "Primos.h"

class TestSalvaCalculo : public ::testing::Test {
    
protected:
    
    Primos* primos;
    SalvaCalculo* salvaCalculo;
    
    bool f;
    
    virtual void SetUp() {
        primos = new Primos;
        salvaCalculo = new SalvaCalculo(primos);
        
        salvaCalculo->salva("./" + primos->nome());
        f = fopen(("./" + primos->nome()).c_str(), "r");
    }
    virtual void TearDown() {
        remove(("./" + primos->nome()).c_str());
        delete salvaCalculo;
    }
};

TEST_F(TestSalvaCalculo, Teste) {  
    EXPECT_TRUE(f);
}