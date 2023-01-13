#include "ListaEncadeada.h"
#include <iostream>
using namespace std;

ListaEncadeada::ListaEncadeada() : Lista() 
{
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada() 
{
    Limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false)
{
    TipoCelula *p;
    int i;

    if( (pos > tamanho) || (pos <= 0) )
    {
        throw "ERRO: Posicao Invalida!";
    }

    // Posiciona na célula anterior a desejada
    p = primeiro ;
    for(i=1; i<pos; i++)
    {
        p = p->prox;
    }

    // Vai para a próxima se antes for false
    if(!antes)
    {
        p = p->prox;
    }

    return p;
}

TipoItem ListaEncadeada::GetItem(int pos)
{
    TipoCelula *p;

    p = Posiciona(pos);
    return p->item;
}

void ListaEncadeada::SetItem(TipoItem item, int pos)
{
    TipoCelula *p;

    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item)
{
    if(Pesquisa(item.GetChave())) {
        cout << "ERRO: CONTA " << item.GetChave() << " JÁ EXISTENTE" << endl;
    }
    else{
        TipoCelula *nova = new TipoCelula();
        nova->item = item;
        nova->prox = primeiro->prox;
        primeiro->prox = nova;
        tamanho++;

        if(nova->prox == NULL){
            ultimo = nova;
        }
        cout << "OK: CONTA " << item.GetChave() << " CADASTRADA" << endl;
    }
}

void ListaEncadeada::InsereFinal(TipoItem item)
{
    if(Pesquisa(item.GetChave())) {
        cout << "ERRO: CONTA " << item.GetChave() << " JA EXISTENTE" << endl;
    }
    else{
        TipoCelula *nova;

        nova = new TipoCelula();
        nova->item = item;
        ultimo->prox = nova;
        ultimo = nova;
        tamanho++;
        cout << "OK: CONTA " << item.GetChave() << " CADASTRADA" << endl;
    }
}

void ListaEncadeada::InserePosicao(TipoItem item, int pos)
{
    TipoCelula *p, *nova;

    p = Posiciona(pos, true);  // posiciona na célula anterior

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if(nova->prox == NULL)
    {
        ultimo = nova;
    }
}

TipoItem ListaEncadeada::RemoveInicio()
{
    TipoItem aux;
    TipoCelula *p;

    if(tamanho == 0)
    {
        throw "ERRO: Lista vazia!";
    }

    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == NULL)
    {
        ultimo = primeiro;
    }
    aux = p->item;
    delete p;

    return aux;
}

TipoItem ListaEncadeada::RemoveFinal()
{
    TipoItem aux;
    TipoCelula *p;

    if(tamanho == 0)
    {
        throw "ERRO: Lista vazia!";
    }

    // posiciona p na celula anterior à ultima 
    p = Posiciona(tamanho, true);

    p->prox = NULL;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;

    return aux;
}

void ListaEncadeada::RemovePosicao(TipoItem item)
{
    if(tamanho == 0){
        cout << "ERRO: CONTA " << item.GetChave() << " NÃO EXISTE" << endl;
    }

    if(!(Pesquisa(item.GetChave()))) {
        cout << "ERRO: CONTA " << item.GetChave() << " NÃO EXISTE" << endl;
    }
    else
    {
        TipoCelula *q;
        TipoCelula *p = nullptr;
        int aux = 0;

        TipoCelula *x;

        x = primeiro->prox;
        while(x!=NULL)
        {
            aux++;
            if(x->item.GetChave() == item.GetChave())
            {
                break;
            }
            x = x->prox;
        }

        // posiciona p na celula anterior à pos
        p = Posiciona(aux, true);
        q = p->prox;
        p->prox = q->prox;
        tamanho--;
        // aux = q->item;
        delete q;
        if(p->prox == NULL)
        {
            ultimo = p;
        }

        cout << "OK: CONTA " << item.GetChave() << " REMOVIDA" << endl;
    }
}

void ListaEncadeada::Remove(TipoItem item)
{
    if(!(Pesquisa(item.GetChave()))) {
        cout << "ERRO: CONTA " << item.GetChave() << " NÃO EXISTE" << endl;
    }
    else{
        cout << "OK: CONTA " << item.GetChave() << " REMOVIDA" << endl;
    }
}

bool ListaEncadeada::Pesquisa(TipoChave c)
{
    TipoCelula *p;

    if(tamanho == 0)
    {
        return false;
    }

    p = primeiro->prox;
    while(p!=NULL)
    {
        if(p->item.GetChave() == c)
        {
            return true;
        }
        p = p->prox;
    }
    return false;
}

void ListaEncadeada::InsereComPrioridade(TipoItem item, int prioridade, string mensagem)
{
        TipoCelula *nova;

        nova = new TipoCelula();
        nova->item = item;
        nova->prioridade = prioridade;
        nova->mensagem = mensagem;
        ultimo->prox = nova;
        ultimo = nova;
        tamanho++;
        cout << "OK: MENSAGEM PARA " << item.GetChave() << " ENTREGUE" << endl;
}

void ListaEncadeada::Imprime()
{
    TipoCelula *p;

    p = primeiro->prox;
    while(p!=NULL)
    {
        p->item.Imprime();
        p = p->prox;
    }

    printf("\n");
}

void ListaEncadeada::ImprimeMensagem(TipoItem item)
{
    if(tamanho == 0)
    {
        cout << "CONSULTA " << item.GetChave() << ": CAIXA DE ENTRADA VAZIA" << endl;
    }
    else
    {
        TipoCelula *p;
        TipoCelula *aux; 
        int prioridadeAuxiliar = 0;
        p = primeiro->prox;
        while(p!=NULL)
        {
            if(p->prioridade > prioridadeAuxiliar)
            {
                prioridadeAuxiliar = p->prioridade;
                aux = p;
            }
            p = p->prox;
        }
        cout << "CONSULTA " << item.GetChave() << ": " << aux->mensagem << endl;
        TipoCelula *q;
        q = primeiro;
        while(q->prox != aux)
        {
            q = q->prox;
        }
        q->prox = aux->prox;
        delete aux;
        tamanho--;
    }
}

void ListaEncadeada::Limpa()
{
    TipoCelula *p;

    p = primeiro->prox;
    while(p!=NULL)
    {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}