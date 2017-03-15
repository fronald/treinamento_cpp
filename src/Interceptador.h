/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interceptador.h
 * Author: fronald
 *
 * Created on 31 de Outubro de 2016, 14:26
 */

#ifndef INTERCEPTADOR_H
#define INTERCEPTADOR_H

/**
 * Interceptador do calculo.
 */
class Interceptador {
public:
    
    /**
     * Construtor padrao
     */
    Interceptador();
    
    /**
     * Intercepta
     * @param i
     * @return 
     */
    virtual unsigned long intercepta(unsigned long i);
    
    /**
     * Destrutor
     */
    virtual ~Interceptador();
    
};

#endif /* INTERCEPTADOR_H */

