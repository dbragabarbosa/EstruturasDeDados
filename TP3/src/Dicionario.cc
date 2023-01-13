#include "Dicionario.h"
#include <iostream>
using namespace std;

Dicionario::Dicionario()
{
    raiz = NULL;
}

Dicionario::~Dicionario()
{
    Limpa();
}

void Dicionario::SetNumMaximoDeVerbetes(int n)
{
    numMaximoDeVerbetes = n;
}

void Dicionario::Insere(TipoItem item)
{
    // se a chave já existe, não insere
    if(Pesquisa(item.GetChave()).GetChave() != "NULL")
    {
        // cout << "Chave ja existe!" << endl;
        return;
    }
    else
    {
        // se a chave não existe, insere
        InsereRecursivo(raiz, item);
    }
}

void Dicionario::Caminha(int tipo)
{
    cout << "Tipo de caminhamento invalido!" << endl;
}

TipoItem Dicionario::Pesquisa(TipoChave chave)
{
    return PesquisaRecursivo(raiz, chave);
}

TipoItem Dicionario::PesquisaRecursivo(TipoNo *no, TipoChave chave)
{
    TipoItem aux;

    if(no == NULL)
    {
        string s = "NULL";  // Flag para item não presente
        aux.SetChave(s);
        return aux;
    }

    if(chave < no->item.GetChave())
    {
        return PesquisaRecursivo(no->esq, chave);
    }
    else if(chave > no->item.GetChave())
    {
        return PesquisaRecursivo(no->dir, chave);
    }
    else
    {
        return no->item;
    }
}

void Dicionario::InsereRecursivo(TipoNo* &p, TipoItem item)
{
    if (p == NULL)
    {
        p = new TipoNo;
        p->item = item;
        p->esq = NULL;
        p->dir = NULL;
        
    }
    else
    {
        if (item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void Dicionario::Remove(TipoChave chave)
{
    RemoveRecursivo(raiz, chave);
}

void Dicionario::Antecessor(TipoNo *q, TipoNo* &r)
{
    if(r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }

    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}

void Dicionario::RemoveRecursivo(TipoNo* &no, TipoChave chave)
{
    TipoNo *aux;

    if(no == NULL)
    {
        // throw("Item não está presente");
        return;
    }

    if(chave < no->item.GetChave())
    {
        return RemoveRecursivo(no->esq, chave);
    }
    else if(chave > no->item.GetChave())
    {
        return RemoveRecursivo(no->dir, chave);
    }
    else
    {
        if(no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
        {
            Antecessor(no, no->esq);
        }
    }
}

void Dicionario::PreOrdem(TipoNo* p)
{
    if (p != NULL)
    {
        p->item.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void Dicionario::InOrdem(TipoNo* p, string nomeArqDeSaida)
{
    if (p != NULL)
    {
        InOrdem(p->esq, nomeArqDeSaida);

        string nome = nomeArqDeSaida;
        p->item.ImprimeMensagem(nome);
        
        InOrdem(p->dir, nomeArqDeSaida);
    }
}

void Dicionario::RemoveVerbetesComSignificado(TipoNo* &p)
{
    if (p != NULL)
    {
        RemoveVerbetesComSignificado(p->esq);
        RemoveVerbetesComSignificado(p->dir);

        if(p->item.GetTemSignificado() == true)
        {
            Remove(p->item.GetChave());
        }
    }
}

void Dicionario::PosOrdem(TipoNo* p)
{
    if (p != NULL)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->item.Imprime();
    }
}

void Dicionario::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void Dicionario::ApagaRecursivo(TipoNo* &p)
{
    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}
