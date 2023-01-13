#include "TipoItem.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TipoItem::TipoItem()
{
    chave.palavra = "EMPTY";  // indica um item vazio
}

void TipoItem::SetChave(string c)
{
    chave.palavra = c;
}

void TipoItem::SetTipoDeVerbete(string t)   
{ 
    chave.tipo = t;
}

TipoChave TipoItem::GetChave()
{
    return chave.palavra;
}

bool TipoItem::GetTemSignificado()
{
    return chave.temSignificado;
}

void TipoItem::Imprime()
{
    cout << chave.palavra << " (" << chave.tipo << ")" << endl;
}

void TipoItem::ImprimeMensagem(string nomeArquivoDeSaida)
{
    ofstream arquivoDeSaida;
    arquivoDeSaida.open(nomeArquivoDeSaida, ios::app);

    arquivoDeSaida << chave.palavra << " (" << chave.tipo << ")" << endl;

    chave.significados.ImprimeSignificados(nomeArquivoDeSaida, chave.palavra);
}