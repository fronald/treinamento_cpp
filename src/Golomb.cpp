#include <Golomb.h>
#include <vector>
#include <sstream>

Golomb::Golomb(int inicio, unsigned int tamanho, Interceptador *interceptador) :
    Calculo(inicio, tamanho, interceptador)
{
    this->resultados.reserve(tamanho);
}

#include <iostream>
void Golomb::calcula()
{
    std::stringstream ss;
    unsigned int gV;
    for (int i = inicio; i < (int)(inicio + tamanho); ++i) {
        gV = this->golombValue(i);

        for (unsigned int j = 0; j < gV; ++j) {
            ss << i;
        }
        this->resultados.push_back(ss.str());
        ss.str("");
    }
}

unsigned int Golomb::golombValue(const unsigned int n)
{
    if (n < 1) return 0;

    std::vector<unsigned int> g;
    g.push_back(0);
    for (unsigned int i = 1; i <= n; ++i) {
        if (i == 1) {
            g.push_back(1);
            continue;
        }
        g.push_back(1 + g[(i - 1) + 1 - g[g[i-1]]]);
    }
    return g[n];
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
