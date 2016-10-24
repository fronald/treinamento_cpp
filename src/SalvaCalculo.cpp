/* 
 * File:   SalvaCalculo.cpp
 * Author: fronald
 * 
 * Created on 21 de Outubro de 2016, 13:16
 */

#include "SalvaCalculo.h"
#include <fstream>

SalvaCalculo::SalvaCalculo(Calculo *calculo) {
    // Cria a instancia baseado no template
    this->calculo = calculo;
}

void SalvaCalculo::salva(string filePath){
    ofstream ofs(filePath);
    ofs << "Calculo: " << this->calculo->nome() << endl;
    printf("%s\t\t%s\n", "Indice", "Valor");
    this->calculo->calcula();
    for(unsigned int i = 0; i < this->calculo->numeroResultados(); i++){
        printf("%d\t\t%d\n", i, this->calculo->resultado(i));
    }
}

SalvaCalculo::~SalvaCalculo() {
    delete this->calculo;
}

