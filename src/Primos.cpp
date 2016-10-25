/* 
 * File:   Primos.cpp
 * Author: Wilner
 * 
 * Created on 24 de Outubro de 2016, 15:05
 */
#include <string>
#include "Primos.h"

Primos::Primos(int inicio, unsigned int tamanho ): Calculo (inicio, tamanho) {
    this->resultados.reserve(tamanho);
}

void Primos::calcula(){
    this->resultados.push_back (1);
    this->resultados.push_back (2);
    this->resultados.push_back (3);
    this->resultados.push_back (5);
    this->resultados.push_back (7);
    this->resultados.push_back (11);
    this->resultados.push_back (13);
    this->resultados.push_back (17);
    this->resultados.push_back (19);
    this->resultados.push_back (23);
}
    
void Primos::limpaCalculo(){
    this->resultados.clear();
}

unsigned int Primos::numeroResultados(){
    return this->resultados.size();
}

int Primos::resultado(unsigned int indice){
    return this->resultados[indice];
}

string Primos::nome() const{
    return "Primos";
}

Primos::~Primos() {
    this->limpaCalculo();
}