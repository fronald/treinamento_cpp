/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Primos.h"

Primos::Primos(int inicio, unsigned int tamanho): Calculo(inicio, tamanho) {
    this->resultados.reserve(tamanho);
}

void Primos::calcula(){
    //int nr = this->inicio;
    int next = 2; //primeiro primo
    this->resultados.push_back(next);
    int i;
    while(this->resultados.size() < this->tamanho){
        next++;
        int div = 0;
        for (i=1;i<=next; i++){
            if (next % i == 0){
                div++;
            }
        }
        if (div == 2){
           this->resultados.push_back(next);
        }
        
    }
}

unsigned int Primos::numeroResultados(){
    return this->resultados.size();
}

string Primos::nome() const{
    return "Primos";
}

int Primos::resultado(unsigned int indice){
    if(indice + 1 <= this->resultados.size()){
        return this->resultados.at(indice);
    }else{
        return 0;
    }
}

void Primos::limpaCalculo() {
    this->resultados.clear();
}

Primos::~Primos() {
    this->limpaCalculo();
}