/* 
 * File:   Fibonacci.cpp
 * Author: fronald
 * 
 * Created on 21 de Outubro de 2016, 11:02
 */

#include "Calculo.h"
#include <vector>

Calculo::Calculo(int inicio, unsigned int tamanho, Interceptador *interceptador) {
    this->inicio = inicio;
    this->tamanho = tamanho;
    if(interceptador == 0){
        this->interceptador = new Interceptador();
    }else{
        this->interceptador = interceptador;
    }
}

void Calculo::calcula() {
    // TODO: Implementar
}

void Calculo::limpaCalculo(){
    //
}

unsigned int Calculo::numeroResultados(){
   // TODO: Implementar
    return 0;
}

int Calculo::resultado(unsigned int indice){
   // TODO: Implementar
    return 0;
}

bool Calculo::resultado(unsigned int id, std::string& value){
    return false;
   // TODO: Implementar
}

string Calculo::toString(char sep){
    // TODO: Implementar
    return "";
}

string Calculo::nome() const{
    return "Calculo vazio";
}

Calculo::~Calculo() {
    this->inicio = 0;
    if(interceptador != 0){
        delete interceptador;
    }
}
