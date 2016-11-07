#include "Primos.h"
#include <math.h>
#include <iostream>

Primos::Primos(int inicio, unsigned int tamanho, Interceptador *interceptador) : Calculo(inicio, tamanho, interceptador) {
    this->resultados.reserve(tamanho);
}

void Primos::calcula() {
    int ini = this->inicio;
    if (ini == 0 || ini == 1) {
        ini = 3;
        this->resultados.push_back(2);
    }
    while(this->resultados.size() < this->tamanho) {
        bool isPrimo = true;
        for(int i = 2; i <= sqrt(ini); i++) {
            if(ini%i == 0) {
                isPrimo = false;
                break;
            }
        }
        if(isPrimo) this->resultados.push_back(ini);
        ini++;
    }
}

unsigned int Primos::numeroResultados() {
    return this->resultados.size();
}

int Primos::resultado(unsigned int indice) {
    int rtn = 0;
    if(indice + 1 <= this->resultados.size()) {
        rtn = this->resultados.at(indice);
    }
    return this->interceptador->intercepta(rtn);
}

string Primos::toString(char sep){
    // TODO: Implementar
    stringstream ss;
    unsigned int i = 0;
    for(vector<int>::iterator it = this->resultados.begin(); it != this->resultados.end(); it++){
        ss << *it;
        if(i < (this->resultados.size() - 1)){
            ss << sep;
        }
        i++;
    }
    return ss.str();
}

void Primos::limpaCalculo() {
    this->resultados.clear();
}

string Primos::nome() const{
    return "Primos";
}

Primos::~Primos() {
    this->limpaCalculo();
}
