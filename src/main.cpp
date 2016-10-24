/* 
 * File:   Main.cpp
 * Author: fronald
 *
 * Created on 21 de Outubro de 2016, 10:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculo.h"
#include "Fibonacci.h"
#include "SalvaCalculo.h"
#include <map>

using namespace std;

void imprimeCalculo(Calculo *calculo) {
    printf("%s\n", calculo->nome().c_str());
    printf("%s\t\t%s\n", "Indice", "Valor");
    for (unsigned int i = 0; i < calculo->numeroResultados(); i++) {
        printf("%d\t\t%d\n", i, calculo->resultado(i));
    }
}

/*
 * Este é o ponto de início da aplicação.
 * @param argc Número de argumentos passados
 * @param argv Vetor com os parâmetros
 */
int main(int argc, char** argv) {
    if (argc < 3) {
        printf("%s", "Uso: ./calculo <inicio> <tamanho> [<nome_calculo>] [<arquivo para salvar>]\n");
        printf("%s", "Ex: ./calculo 1 100 fibonacci ./teste_fibonacci\n");
        return EXIT_SUCCESS;
    }

    int inicio = atoi(argv[1]);
    int tamanho = atoi(argv[2]);

    map<string, Calculo*> calculos;
    calculos.insert(pair<string, Calculo*>("fibonacci", new Fibonacci(inicio, tamanho)));

    // Retorna sucesso
    if (argc > 3) {
        if (calculos.count(argv[3]) > 0) {
            Calculo *calculo = calculos.at(argv[3]);
            calculo->calcula();
            if (argc > 4) {
                SalvaCalculo *sc = new SalvaCalculo(calculo);
                sc->salva(argv[4]);
            } else {
                imprimeCalculo(calculo);
            }
        }
    } else {
        for (map<string, Calculo*>::iterator it = calculos.begin(); it != calculos.end(); it++) {
            imprimeCalculo(it->second);
        }
    }

    return (EXIT_SUCCESS);
}

