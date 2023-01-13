#ifndef TIPOCELULA_H
#define TIPOCELULA_H

#include <iostream>
#include <string>

using namespace std;

class TipoCelula
{
    public:
        TipoCelula();

        string item;
        string chaveVerbete;

        TipoCelula *prox;

    friend class FilaDeSignificados;
};

#endif