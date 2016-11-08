#include <hippomocks.h>
#include <gtest/gtest.h>

#include "Calculo.h"


class TestCalculoMock : public ::testing::Test {

protected:

    MockRepository *mocks;
    Calculo* calculo;

    virtual void SetUp() {
        mocks = new MockRepository();
        calculo = mocks->Mock<Calculo>();
        mocks->ExpectCall(calculo, Calculo::calcula);
        calculo->calcula();
    }

    virtual void TearDown() {
        mocks->ExpectCall(calculo, Calculo::limpaCalculo);
        calculo->limpaCalculo();
    }

};

class TestCalculo : public ::testing::Test {

protected:

    Calculo* calculo;

    virtual void SetUp() {
        calculo = new Calculo();
        calculo->calcula();
    }

    virtual void TearDown() {
        calculo->limpaCalculo();
        delete calculo;
    }

};


TEST_F(TestCalculoMock, Test) {
    std::string value;
    mocks->ExpectCallOverload(calculo, static_cast<bool(Calculo::*)(unsigned int, std::string&)>(&Calculo::resultado)).With(1, _).Return(true);
    mocks->ExpectCall(calculo, Calculo::numeroResultados).Return(0);
    mocks->ExpectCall(calculo, Calculo::nome).Return("Calcula nada");

    mocks->OnCall(calculo, Calculo::toString).With(',').Return("1,2,3");

    EXPECT_TRUE(calculo->resultado(1, value));
    EXPECT_TRUE(calculo->numeroResultados() == 0);
    EXPECT_STREQ(calculo->nome().c_str(), "Calcula nada");
    EXPECT_STREQ(calculo->toString(',').c_str(), "1,2,3");
}

TEST_F(TestCalculo, Test) {
    std::string value;
    EXPECT_TRUE(calculo->resultado(0) == 0);
    EXPECT_TRUE(calculo->resultado(0, value) == 0);
    EXPECT_TRUE(calculo->numeroResultados() == 0);
    EXPECT_STREQ(calculo->nome().c_str(), "Calculo vazio");
    EXPECT_STREQ(calculo->toString(',').c_str(), "");
}
