/* 
 * File:   Fibonacci.cpp
 * Author: fronald
 * 
 * Created on 21 de Outubro de 2016, 11:19
 */

#include "Fibonacci.h"
#include <sstream>
#include <stdio.h>
#include <string.h>

Fibonacci::Fibonacci(int inicio, unsigned int tamanho, Interceptador *interceptador): Calculo(inicio, tamanho, interceptador) {
    this->resultados.reserve(tamanho);
}

void Fibonacci::calcula(){
    unsigned long nr = this->inicio;
    unsigned long last = nr;

    this->resultados.push_back(nr);
    while(this->resultados.size() < this->tamanho){
        if(last == nr){
            nr = nr + 1;
        }else{
            unsigned long long lst = last;
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

unsigned long Fibonacci::resultado(unsigned int indice){
    unsigned long rtn = 0;
    if(indice + 1 <= this->resultados.size()) {
        rtn = this->resultados.at(indice);

    }
    //printf("\n index %d result %d\n", indice, rtn);
    return this->interceptador->intercepta(rtn);

}

string Fibonacci::toString(char sep){
    stringstream ss;
    unsigned long i = 0;
    for(vector<unsigned long>::iterator it = this->resultados.begin(); it != this->resultados.end(); it++){
        ss << *it;
        if(i < (this->resultados.size() - 1)){

            ss << sep;
        }
        i++;
    }
    return ss.str();
}

void Fibonacci::limpaCalculo() {
    this->resultados.clear();
}

Fibonacci::~Fibonacci() {
    this->limpaCalculo();
}

