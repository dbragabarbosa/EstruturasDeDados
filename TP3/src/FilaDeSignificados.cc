#include "FilaDeSignificados.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

FilaDeSignificados::FilaDeSignificados() : Fila()
{
    frente = new TipoCelula();
    tras = frente;
}

FilaDeSignificados::~FilaDeSignificados()
{
    // Limpa();
    // delete frente;
}

void FilaDeSignificados::Enfileira(string sig, string chave)
{
    if (sig == "")
    {
        return;
    }

    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = sig;
    nova->chaveVerbete = chave;
    tras->prox = nova;
    tras = nova;
    tamanho++;
}

void FilaDeSignificados::Imprime()
{
    TipoCelula *aux;

    aux = frente->prox;
    while (aux != NULL)
    {
        cout << aux->item << endl;
        aux = aux->prox;
    }
}

void FilaDeSignificados::ImprimeSignificados(string nomeArquivoDeSaida, string palavra)
{
    TipoCelula *aux;

    ofstream arquivoDeSaida;
    arquivoDeSaida.open(nomeArquivoDeSaida, ios::app);

    aux = frente->prox;

    int i = 1;

    while (aux != NULL)
    {
        if(palavra == aux->chaveVerbete)
        {
            arquivoDeSaida << i << "." << aux->item << endl;
            i++;
        }
        aux = aux->prox;
    }
}

string FilaDeSignificados::Desenfileira()
{
    string aux;
    TipoCelula *p;

    if (tamanho == 0)
    {
        cout << "Fila vazia" << endl;
        return "EMPTY";
    }

    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;
    delete p;
    tamanho--;
    return aux;
}

void FilaDeSignificados::Limpa()
{
    TipoCelula *p;

    p = frente->prox;
    while (p != NULL)
    {
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }
    tamanho = 0;
    tras = frente;
}