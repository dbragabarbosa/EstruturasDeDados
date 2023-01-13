#ifndef PILHA_H
#define PILHA_H

#include <iostream>

#include "TipoUnidade.h"
#include "TipoCelula.h"

using namespace std;

class Pilha
{
    public: 
        Pilha() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual void Empilha(TipoUnidade unidade) = 0;
        // virtual TipoUnidade Desempilha() = 0;
        virtual void Desempilha() = 0;
        virtual void Limpa() = 0;

    protected:
        int tamanho;
};

#endif