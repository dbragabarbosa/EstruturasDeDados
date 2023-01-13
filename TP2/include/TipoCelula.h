#ifndef TIPOCELULA_H
#define TIPOCELULA_H

#include <iostream>

#include "TipoUnidade.h"

using namespace std;


class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoUnidade item;
        TipoCelula *prox;

    friend class PilhaEncadeada;
};

#endif