#ifndef GOLOMB_H
#define GOLOMB_H

#include <vector>
#include <Calculo.h>

using namespace std;

/**
 * Implementa o calculo da serie de Golomb
 */
class Golomb: public Calculo {

public:
    /**
     * Constructor
     * @param inicio Inicio do calculo
     * @params tamanho Numero de resultados para calcular
     */
    Golomb(int inicio = 0, unsigned int tamanho = 10, Interceptador *interceptador = 0);

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
     * @param valor
     * @return 
     */
    virtual bool resultado(unsigned int id, std::string& value);

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
    virtual std::string nome() const;

    /**
     * Transforma o resultado em string.
     * @param sep Separador
     * @return 
     */
    virtual std::string toString(char sep);

    /**
     * Destructor
     */
    virtual ~Golomb();
private:

    /**
     * Lista de resultados
     */
    std::vector<std::string> resultados;

};

#endif /* GOLOMB_H */

