/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Primos.h
 * Author: development
 *
 * Created on 25 de Outubro de 2016, 11:44
 */

#ifndef PRIMOS_H
#define PRIMOS_H

#include <vector>
#include "Calculo.h"

using namespace std;

/**
 * Devolve os n primeiros números primos.
 */
class Primos: public Calculo {
    
public:
    /**
     * Constructor
     * @param inicio Inicio do calculo
     * @params tamanho Numero de resultados para calcular
     */
    Primos(int inicio = 0, unsigned int tamanho = 10);
    
    /**
     * Calcula
     */
    void calcula();
    
    /**
     * Resultados
     * @return 
     */
    virtual unsigned int numeroResultados();
    
    /**
     * Limpa o calculo
     */
    virtual void limpaCalculo();
    
    /**
     * Retorna o resultado em uma determinada posição
     * @param indice
     * @return 
     */
    virtual int resultado(unsigned int indice);
    
    /**
     * Retorna o nome do calculo
     * @return 
     */
    virtual string nome() const;
    
    /**
     * Destructor
     */
    virtual ~Primos();
private:
    
    /**
     * Lista de resultados
     */
    vector<int> resultados;
    
};

#endif /* PRIMOS_H */

