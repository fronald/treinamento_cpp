#include <gtest/gtest.h>
#include <hippomocks.h>

#include "Golomb.h"

class TestGolomb: public ::testing::Test {

protected:
    Calculo* golomb;

    virtual void SetUp()
    {
        golomb = new Golomb(0, 10);
        //mocks.ExpectCall(golomb, Golomb::calcula)
        golomb->calcula();
    }

    virtual void TearDown()
    {
        //mocks->ExpectCall(golomb, Golomb::calcula);
        golomb->limpaCalculo();
        delete golomb;
    }
};

class
TestGolombInterceptator: public ::testing::Test {
protected:
    Calculo* golomb;
    MockRepository* mocks;
    Interceptador* interceptador;

    virtual void SetUp()
    {
        mocks = new MockRepository();
        interceptador = mocks->Mock<Interceptador>();
        golomb = new Golomb(0, 10, interceptador);
        golomb->calcula();
    }

    virtual void TearDown()
    {
        mocks->OnCallDestructor(interceptador);
        delete golomb;
    }
};

TEST_F(TestGolomb, TesteDeTamanho)
{
    EXPECT_TRUE(golomb->numeroResultados() == 10);
}

TEST_F(TestGolomb, TesteDeResultado)
{
    std::string value;
    golomb->resultado(0, value);
    EXPECT_TRUE(value == "");
    golomb->resultado(1, value);
    EXPECT_TRUE(value == "1");
    golomb->resultado(2, value);
    EXPECT_TRUE(value == "22");
    golomb->resultado(3, value);
    EXPECT_TRUE(value == "333");
    golomb->resultado(4, value);
    EXPECT_TRUE(value == "4444");
    golomb->resultado(5, value);
    EXPECT_TRUE(value == "55555");
    golomb->resultado(6, value);
    EXPECT_TRUE(value == "666666");
    golomb->resultado(7, value);
    EXPECT_TRUE(value == "7777777");
    golomb->resultado(8, value);
    EXPECT_TRUE(value == "88888888");
    golomb->resultado(9, value);
    EXPECT_TRUE(value == "999999999");
    golomb->resultado(1, value);
    EXPECT_FALSE(value == "7777777");

    EXPECT_TRUE(golomb->resultado(golomb->numeroResultados()) == 0);
    EXPECT_TRUE(golomb->resultado(golomb->numeroResultados(), value) == 0);
}

TEST_F(TestGolomb, TestDeNome)
{
    EXPECT_STREQ(golomb->nome().c_str(), "Golomb");
}

TEST_F(TestGolomb, TesteToString)
{
    EXPECT_STREQ(golomb->toString(',').c_str(), ",1,22,333,4444,55555,666666,7777777,88888888,999999999");
    EXPECT_STREQ(golomb->toString(';').c_str(), ";1;22;333;4444;55555;666666;7777777;88888888;999999999");
}

TEST_F(TestGolombInterceptator, TesteDeResultadoZero)
{
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(333).Return(15);
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(4444).Return(66);
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(666666).Return(44);
    EXPECT_TRUE(golomb->resultado(3) == 15);
    EXPECT_FALSE(golomb->resultado(4) == 99);
    EXPECT_TRUE(golomb->resultado(6) == 44);
}
