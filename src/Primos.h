/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Primos.h
 * Author: devlopment
 *
 * Created on 24 de Outubro de 2016, 15:05
 */

#ifndef PRIMOS_H
#define PRIMOS_H

#include <vector>
#include "Calculo.h"

using namespace std;

class Primos: public Calculo{
public:
    Primos(int inicio = 0, unsigned int tamanho = 10);
    
    virtual void calcula();
    
    virtual void limpaCalculo();
    
    virtual unsigned int numeroResultados();
    
    virtual int resultado(unsigned int indice);
    
    virtual string nome() const;
    
    virtual ~Primos();

private:
    vector<int> resultados;
};

#endif /* PRIMOS_H */

