#include <Golomb.h>
#include <vector>
#include <sstream>
#include <iostream>

Golomb::Golomb(int inicio, unsigned int tamanho, Interceptador *interceptador) :
    Calculo(inicio, tamanho, interceptador)
{
    this->resultados.reserve(tamanho);
}

void Golomb::calcula()
{
    std::stringstream ss;
    for (int i = inicio; i < (int)(inicio + tamanho); ++i) {
        for (int j = 0; j < i; ++j) {
            ss << i;
        }
        this->resultados.push_back(ss.str());
        //std::cout << ss.str() << std::endl;
        ss.str("");
    }
}

void Golomb::limpaCalculo()
{
    this->resultados.clear();
}

unsigned int Golomb::numeroResultados()
{
    return this->resultados.size();
}

int Golomb::resultado(unsigned int indice)
{
    if (indice >= this->resultados.size()) {
        return 0; //?
    }

    return this->interceptador->intercepta(indice);
}

bool Golomb::resultado(unsigned int id, std::string& value)
{
    if (id >= this->resultados.size()) {
        return false;
    }
    value = this->resultados[id];
    this->interceptador->intercepta(id);
    return true;
}


string Golomb::toString(char sep)
{
    std::stringstream ss;
    unsigned int i = 0;
    for(vector<std::string>::iterator it = this->resultados.begin(); it != this->resultados.end(); it++){
        ss << *it;
        if(i < (this->resultados.size() - 1)){
            ss << sep;
        }
        i++;
    }
    return ss.str();
}

string Golomb::nome() const
{
    return "Golomb";
}

Golomb::~Golomb() {
    this->inicio = 0;
    if (interceptador != 0){
        delete interceptador;
        interceptador = 0;
    }
}
