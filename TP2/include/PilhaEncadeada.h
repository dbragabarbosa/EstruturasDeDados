#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

#include <iostream>

#include "Pilha.h"

using namespace std;

class PilhaEncadeada : public Pilha
{
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();

        void Inicializa();
        void Empilha(TipoUnidade item);
        void Desempilha();
        TipoUnidade DesempilhaComRetorno();
        void Limpa();

    private:
        TipoCelula *topo;
};

#endif