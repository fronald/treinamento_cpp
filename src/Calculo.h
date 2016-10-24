/* 
 * File:   Calculo.h
 * Author: fronald
 *
 * Created on 21 de Outubro de 2016, 11:02
 */

#ifndef CALCULO_H
#define CALCULO_H

#include <string>

using namespace std;

/**
 * Declaração da classe Calculo.
 */
class Calculo {
public:
    
    /**
     * Construtor
     * @param inicio Início do cálculo
     */
    Calculo(int inicio = 0, unsigned int tamanho = 0);
    
    /**
     * Calcula Fibonacci
     */
    virtual void calcula();
    
    /**
     * Limpa calculo
     */
    virtual void limpaCalculo();
    
    /**
     * Resultados
     * @return 
     */
    virtual unsigned int numeroResultados();
    
    /**
     * Retorna o resultado em uma determinada posição
     * @param indice
     * @return 
     */
    virtual int resultado(unsigned int indice);
    
    /**
     * Nome do cálculo
     * @return 
     */
    virtual string nome() const;
    
    /**
     * Destrutor
     */
    virtual ~Calculo();
    
protected:
    
    /**
     * Início
     */
    int inicio;
    
    /**
     * Tamanho do cálculo que será realizado
     */
    unsigned int tamanho;
    
};

#endif /* CALCULO_H */

