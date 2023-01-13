#include "TipoNo.h"

TipoNo::TipoNo()
{
    string s = "NULL";
    item.SetChave(s);
    esq = NULL;
    dir = NULL;
    altura = 1;  
}

int TipoNo::max(int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}

int TipoNo::height(TipoNo* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->esq), height(node->dir));
}

int TipoNo::balanceFactor(TipoNo* node)
{
    if(node == NULL)
    {
        return 0;
    }

    int balance = node->dir->altura - node->esq->altura;

    return balance;
}