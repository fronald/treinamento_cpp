/* 
 * File:   Goulomb.h
 * Author: Diogo Dias
 *
 * Created on 14 de Marco de 2017, 09:40
 */

#ifndef GOULOMB_H
#define GOULOMB_H

#include <vector>
#include "Calculo.h"

using namespace std;

/**
 * Implementa o calculo de Fibonacci.
 */
class Goulomb: public Calculo {
    
public:
    /**
     * Constructor
     * @param inicio Inicio do calculo
     * @params tamanho Numero de resultados para calcular
     */
    Goulomb(int inicio = 0, unsigned int tamanho = 10, Interceptador *interceptador = 0);
    
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
    virtual unsigned long resultado(unsigned int indice);
    
    /**
     * Retorna o nome do calculo
     * @return 
     */
    virtual string nome() const;
    
    /**
     * Transforma o resultado em string.
     * @param sep Separador
     * @return 
     */
    virtual string toString(char sep);
    
    /**
     * Destructor
     */
    virtual ~Goulomb();
private:
    
    /**
     * Lista de resultados
     */
    vector<int> resultados;
    
};

#endif /* GOULOMB_H */

