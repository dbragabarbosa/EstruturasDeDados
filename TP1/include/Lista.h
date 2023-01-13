#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "TipoItem.h"
#include "TipoCelula.h"

using namespace std;


class Lista
{
    public:
        Lista() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;
        virtual void InsereInicio(TipoItem item) = 0;
        virtual void InsereFinal(TipoItem item) = 0;
        virtual void InserePosicao(TipoItem item, int pos) = 0;
        virtual TipoItem RemoveInicio() = 0;
        virtual TipoItem RemoveFinal() = 0;
        virtual void RemovePosicao(TipoItem item) = 0;
        virtual void Remove(TipoItem item) = 0;
        virtual bool Pesquisa(TipoChave c) = 0;
        virtual void InsereComPrioridade(TipoItem item, int prioridade, string mensagem) = 0;
        virtual void Imprime() = 0;
        virtual void ImprimeMensagem(TipoItem item) = 0;
        virtual void Limpa() = 0;

    protected:
        int tamanho;

};

#endif