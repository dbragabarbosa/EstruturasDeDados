#ifndef TIPOITEM_H
#define TIPOITEM_H

#include <iostream>

using namespace std;

typedef int TipoChave; // TipoChave é um inteiro


class TipoItem
{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();
        void ImprimeMensagem();
        TipoChave chave;
        int prioridade;
        string mensagem;
};

#endif