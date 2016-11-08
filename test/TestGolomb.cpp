#include <gtest/gtest.h>
#include <hippomocks.h>

#include "Golomb.h"

class TestGolomb: public ::testing::Test {

protected:
    Calculo* golomb;

    virtual void SetUp()
    {
        golomb = new Golomb(0, 10);
        golomb->calcula();
    }

    virtual void TearDown()
    {
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
    EXPECT_TRUE(value == "33");
    golomb->resultado(4, value);
    EXPECT_TRUE(value == "444");
    golomb->resultado(5, value);
    EXPECT_TRUE(value == "555");
    golomb->resultado(6, value);
    EXPECT_TRUE(value == "6666");
    golomb->resultado(7, value);
    EXPECT_TRUE(value == "7777");
    golomb->resultado(8, value);
    EXPECT_TRUE(value == "8888");
    golomb->resultado(9, value);
    EXPECT_TRUE(value == "99999");
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
    EXPECT_STREQ(golomb->toString(',').c_str(), ",1,22,33,444,555,6666,7777,8888,99999");
    EXPECT_STREQ(golomb->toString(';').c_str(), ";1;22;33;444;555;6666;7777;8888;99999");
}

TEST_F(TestGolombInterceptator, TesteDeResultadoZero)
{
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(33).Return(15);
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(444).Return(66);
    mocks->ExpectCall(this->interceptador, Interceptador::intercepta).With(6666).Return(44);
    EXPECT_TRUE(golomb->resultado(3) == 15);
    EXPECT_FALSE(golomb->resultado(4) == 99);
    EXPECT_TRUE(golomb->resultado(6) == 44);
}
