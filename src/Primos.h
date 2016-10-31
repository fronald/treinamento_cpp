/* 
 * File:   Primos.h
 * Author: development
 *
 * Created on 24 de Outubro de 2016, 11:32
 */

#ifndef PRIMOS_H
#define PRIMOS_H

#include <vector>
#include "Calculo.h"

class Primos : public Calculo {
    
    public:
        
        Primos(int inicio = 0, unsigned int tamanho = 0, Interceptador *interceptador = 0);
        
        virtual unsigned int numeroResultados();
        
        virtual int resultado(unsigned int indice);
        
        virtual void limpaCalculo();
        
        virtual string nome() const;
        
        void calcula();
    
        virtual string toString(char sep);
        
        virtual ~Primos();
        
    private:
        
        vector<int> resultados;
            
    
};

#endif /* PRIMOS_H */

