#ifndef TIPOUNIDADE_H
#define TIPOUNIDADE_H

#include <iostream>

using namespace std;

// typedef int TipoChave;  // TipoChave é um inteiro

class TipoUnidade
{
    public:
        TipoUnidade();
        TipoUnidade(int c);
        void SetChave(int c);
        int GetChave();
        void Imprime();

        int chave;
        int dir;
        int esq;
};

#endif