/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <gtest/gtest.h>
#include <fstream>
#include <unistd.h>

#include "SalvaCalculo.h"
#include "Calculo.h"

class TestSalvaCalculo: public ::testing::Test { 

protected:
   SalvaCalculo* sc_t;
   Calculo* calc;
   
 
   virtual void SetUp( ) {
       calc = new Calculo(0, 10);
       calc->calcula();
       sc_t = new SalvaCalculo(calc);
       sc_t->salva("nome");
    }
 
   virtual void TearDown( ) { 
      calc->limpaCalculo();
      //delete calc;
      delete sc_t;
   }
   
   bool file_exist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
            fclose(file);
            return true;
        } else {
            return false;
        } 
    }

};

TEST_F(TestSalvaCalculo, TesteDeArquivo){
   EXPECT_TRUE(file_exist("nome"));
}