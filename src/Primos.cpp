/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Primos.h"
#include <math.h>
#include <iostream>

Primos::Primos(int inicio, unsigned int tamanho) : Calculo(inicio, tamanho) {
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
        std::cout << ini << " ";
    }
}

unsigned int Primos::numeroResultados() {
    return this->resultados.size();
}

int Primos::resultado(unsigned int indice) {
    if(indice + 1 <= this->resultados.size()) {
        return this->resultados.at(indice);
    } else {
        return 0;
    }
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
