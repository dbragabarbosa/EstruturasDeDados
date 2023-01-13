#include "TipoUnidade.h"

TipoUnidade::TipoUnidade()
{
    chave = -1;  // indica um item vazio
}

TipoUnidade::TipoUnidade(int c)
{
    chave = c;
}

void TipoUnidade::SetChave(int c)
{
    chave = c;
}

int TipoUnidade::GetChave()
{
    return chave;
}

void TipoUnidade::Imprime()
{
    cout << chave << endl;
}

