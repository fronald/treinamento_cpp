#include <gtest/gtest.h>

#include "Primes.h"

class TestPrimes: public ::testing::Test { 

protected:

   Calculo* primes;
 
   virtual void SetUp( ) {
       primes = new Primes(0, 10);
       primes->calcula();
   }
 
   virtual void TearDown( ) { 
       primes->limpaCalculo();
       delete primes;
   }

};

TEST_F(TestPrimes, TesteDeTamanho) {
    EXPECT_TRUE(primes->numeroResultados() == 10);
}

TEST_F(TestPrimes, TesteDeResultado){
    EXPECT_TRUE(primes->resultado(0) == 2);
    EXPECT_TRUE(primes->resultado(1) == 3);
    EXPECT_TRUE(primes->resultado(2) == 5);
    EXPECT_TRUE(primes->resultado(3) == 7);
    EXPECT_TRUE(primes->resultado(4) == 11);
    EXPECT_TRUE(primes->resultado(5) == 13);
    EXPECT_TRUE(primes->resultado(6) == 17);
    EXPECT_TRUE(primes->resultado(7) == 19);
    EXPECT_TRUE(primes->resultado(8) == 23);
    EXPECT_TRUE(primes->resultado(9) == 29);
    EXPECT_FALSE(primes->resultado(9) == 35);
}
