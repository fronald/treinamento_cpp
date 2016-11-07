#include <Golomb.h>
#include <vector>
#include <sstream>

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
#include <iostream>
int Golomb::resultado(unsigned int indice)
{
    int rtn;
    std::stringstream ss;

    if (indice >= this->resultados.size()) {
        return 0; //?
    }
    ss << this->resultados[indice];
    ss >> rtn;

    return this->interceptador->intercepta(rtn);
}

bool Golomb::resultado(unsigned int id, std::string& value)
{
    int rtn;
    std::stringstream ss;

    if (id >= this->resultados.size()) {
        return false;
    }
    value = this->resultados[id];
    ss << value;
    ss >> rtn;

    this->interceptador->intercepta(rtn);
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
