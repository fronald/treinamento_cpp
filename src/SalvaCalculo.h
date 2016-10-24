/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SalvaCalculo.h
 * Author: fronald
 *
 * Created on 21 de Outubro de 2016, 13:16
 */

#ifndef SALVACALCULO_H
#define SALVACALCULO_H

#include "Calculo.h"
#include <string>

using namespace std;

/**
 * Salva calculo
 */
class SalvaCalculo {
    
public:
    
    /**
     * Construtor
     * @param inicio
     * @param tamanho
     */
    SalvaCalculo(Calculo *calculo);
   
   /**
    * Salva o arquivo
    * @param filePath
    */
   void salva(string filePath);
   
   /**
    * Salva calculo
    */
    virtual ~SalvaCalculo();
    
private:
    
    /**
     * Calculo para efetuar
     */
    Calculo *calculo;
    
};

#endif /* SALVACALCULO_H */

