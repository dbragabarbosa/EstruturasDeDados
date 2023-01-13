#ifndef FILADESIGNIFICADOS_H
#define FILADESIGNIFICADOS_H

#include <iostream>
#include <string>

#include "Fila.h"
#include "TipoCelula.h"

using namespace std;

class FilaDeSignificados : public Fila
{
    public:
        FilaDeSignificados();
        virtual ~FilaDeSignificados();

        void Enfileira(string sig, string chave);
        void Imprime();
        void ImprimeSignificados(string nomeArquivoDeSaida, string palavra);
        string Desenfileira();
        void Limpa();

        TipoCelula *frente;
        TipoCelula *tras;

};

#endif