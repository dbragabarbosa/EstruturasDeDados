#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>

using namespace std;

class Fila
{
    public:
        Fila() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual void Enfileira(string sig, string chave) = 0;
        virtual string Desenfileira() = 0;
        virtual void Limpa() = 0;

        int tamanho;
};

#endif