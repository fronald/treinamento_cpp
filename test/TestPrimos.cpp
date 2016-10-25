#include <gtest/gtest.h>

#include "Primos.h"
#include "Calculo.h"

class TestPrimos : public ::testing::Test {
    protected:
    Calculo* primos;
    
    virtual void SetUp() {
        primos = new Primos(0, 10);
        primos->calcula();
    }
    
    virtual void TearDown(){
        primos->limpaCalculo();
        delete primos;
    }
};

TEST_F(TestPrimos, TesteDeTamanho){
    EXPECT_TRUE(primos->numeroResultados() == 10);
}

TEST_F(TestPrimos, TesteDeResultados){
    EXPECT_TRUE(primos->resultado(0) == 1);
    EXPECT_TRUE(primos->resultado(1) == 2);
    EXPECT_TRUE(primos->resultado(2) == 3);
    EXPECT_TRUE(primos->resultado(3) == 5);
    EXPECT_TRUE(primos->resultado(4) == 7);
    EXPECT_TRUE(primos->resultado(5) == 11);
    EXPECT_TRUE(primos->resultado(6) == 13);
    EXPECT_TRUE(primos->resultado(7) == 17);
    EXPECT_TRUE(primos->resultado(8) == 19);
    EXPECT_TRUE(primos->resultado(9) == 23);
}

TEST_F(TestPrimos, TesteDeNome){
    EXPECT_TRUE(primos->nome() == "Primos");
}