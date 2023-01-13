#ifndef TIPOITEM_H
#define TIPOITEM_H

#include <iostream>
#include <string>

#include "Verbete.h"

using namespace std;

typedef string TipoChave; // TipoChave é uma string


class TipoItem
{
    public:
        TipoItem();

        void SetChave(string c);

        void SetTipoDeVerbete(string t);   

        TipoChave GetChave();

        bool GetTemSignificado();

        void Imprime();
        void ImprimeMensagem(string nomeArquivoDeSaida);

        Verbete chave; 
};

#endif