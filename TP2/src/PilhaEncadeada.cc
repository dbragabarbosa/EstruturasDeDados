#include "PilhaEncadeada.h"

#include <iostream>
using namespace std;

PilhaEncadeada::PilhaEncadeada() : Pilha()
{
    topo = NULL;
}

PilhaEncadeada::~PilhaEncadeada()
{
    Limpa();
}

void PilhaEncadeada::Inicializa()
{
    Limpa();
}

void PilhaEncadeada::Empilha(TipoUnidade item)
{
    TipoCelula *novaCelula = new TipoCelula;
    novaCelula->item = item;
    novaCelula->prox = topo;
    topo = novaCelula;
    tamanho++;
}

void PilhaEncadeada::Desempilha()
{
    TipoCelula *p;

    if (tamanho == 0)
    {
        // throw "Pilha vazia!";
        cout << "Pilha vazia!" << endl;
        return;
    }

    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;
}

TipoUnidade PilhaEncadeada::DesempilhaComRetorno()
{
    TipoUnidade aux;
    TipoCelula *p;

    if (tamanho == 0)
    {
        // throw "Pilha vazia!";
        cout << "Pilha vazia!" << endl;
        return aux;
    }

    // coloco em aux o que vou desempilhar
    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
}


void PilhaEncadeada::Limpa()
{
    TipoCelula *p;

    while (topo != NULL)
    {
        p = topo;
        topo = topo->prox;
        delete p;
    }
    tamanho = 0;
}