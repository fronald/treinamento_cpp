/* 
 * File:   Fibonacci.h
 * Author: fronald
 *
 * Created on 21 de Outubro de 2016, 11:19
 */

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <vector>
#include "Calculo.h"

using namespace std;

/**
 * Implementa o calculo de Fibonacci.
 */
class Fibonacci: public Calculo {

public:
    /**
     * Constructor
     * @param inicio Inicio do calculo
     * @params tamanho Numero de resultados para calcular
     */
    Fibonacci(int inicio = 0, unsigned int tamanho = 10, Interceptador *interceptador = 0);

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
     * Transforma o resultado em string.
     * @param sep Separador
     * @return 
     */
    virtual string toString(char sep);

    /**
     * Destructor
     */
    virtual ~Fibonacci();
private:

    /**
     * Lista de resultados
     */
    vector<int> resultados;

};

#endif /* FIBONACCI_H */

