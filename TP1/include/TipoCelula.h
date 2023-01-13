#ifndef TIPOCELULA_H
#define TIPOCELULA_H

#include <iostream>

#include "TipoItem.h"

using namespace std;


class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

        int prioridade;
        string mensagem;

    friend class ListaEncadeada;
    friend class FilaEncadeada;
};

#endif