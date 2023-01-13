#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <iostream>

#include "Lista.h"

using namespace std;


class ListaEncadeada : public Lista 
{
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        void RemovePosicao(TipoItem item);
        void Remove(TipoItem item);
        bool Pesquisa(TipoChave c);
        void InsereComPrioridade(TipoItem item, int prioridade, string mensagem);
        void Imprime();
        void ImprimeMensagem(TipoItem item);
        void Limpa();

    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);  
};

#endif