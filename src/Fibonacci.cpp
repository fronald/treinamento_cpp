/* 
 * File:   Fibonacci.cpp
 * Author: fronald
 * 
 * Created on 21 de Outubro de 2016, 11:19
 */

#include "Fibonacci.h"

Fibonacci::Fibonacci(int inicio, unsigned int tamanho): Calculo(inicio, tamanho) {
    this->resultados.reserve(tamanho);
}

void Fibonacci::calcula(){
    int nr = this->inicio;
    int last = nr;
    this->resultados.push_back(nr);
    while(this->resultados.size() < this->tamanho){
        if(last == nr){
            nr = nr + 1;
        }else{
            int lst = last;
            last = nr;
            nr = nr + lst;
        }
        this->resultados.push_back(nr);
    }
}

unsigned int Fibonacci::numeroResultados(){
    return this->resultados.size();
}

string Fibonacci::nome() const{
    return "Fibonacci";
}

int Fibonacci::resultado(unsigned int indice){
    if(indice + 1 <= this->resultados.size()){
        return this->resultados.at(indice);
    }else{
        return 0;
    }
}

void Fibonacci::limpaCalculo() {
    this->resultados.clear();
}

Fibonacci::~Fibonacci() {
    this->limpaCalculo();
}

