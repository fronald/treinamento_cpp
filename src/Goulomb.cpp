/* 
 * File:   Goulomb.cpp
 * Author: Diogo Dias
 * 
 * Created on 14 de Marco de 2017, 09:50
 */

#include "Goulomb.h"
#include <sstream>

Goulomb::Goulomb(int inicio, unsigned int tamanho, Interceptador *interceptador): Calculo(inicio, tamanho, interceptador) {
    this->resultados.reserve(tamanho);
}

void Goulomb::calcula(){
    int nr = this->inicio;
    //int last = nr;
    unsigned int iter = 0;
    if(nr == 0){
	this->resultados.push_back(1);
	iter = 1;
	//resultados[iter-1] = nr;
	}else{
    	this->resultados.push_back(nr);
	iter = nr;
	//resultados[iter-1] = nr;
	}
//    iter = 1;
    while(iter < this->tamanho){

       if(iter != 0 && iter != 1){
	  
	//    resultados[iter] = 1;
      //  }else{
	resultados[iter] = 1 + resultados[iter - resultados[resultados[iter-1]]];
        }
	if(iter == 1){
		resultados[iter] = 1;
	}
	nr = resultados[iter];
	++iter;
        this->resultados.push_back(nr);
    }
}

unsigned int Goulomb::numeroResultados(){
    return this->resultados.size();
}

string Goulomb::nome() const{
    return "Goulomb";
}

unsigned long Goulomb::resultado(unsigned int indice){
    unsigned long rtn = 0;
    if(indice + 1 <= this->resultados.size()) {
        rtn = this->resultados.at(indice);
    }
    return this->interceptador->intercepta(rtn);
}

string Goulomb::toString(char sep){
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

void Goulomb::limpaCalculo() {
    this->resultados.clear();
}

Goulomb::~Goulomb() {
    this->limpaCalculo();
}

