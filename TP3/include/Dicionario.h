#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <iostream>

#include "TipoItem.h"
#include "TipoNo.h"

using namespace std;

class Dicionario
{
    public:
        Dicionario();
        ~Dicionario();

        void SetNumMaximoDeVerbetes(int n);

        void Insere(TipoItem item);
        void Caminha(int tipo);

        TipoItem Pesquisa(TipoChave chave);   
        void Remove(TipoChave chave);   

        void Limpa();

        void InsereRecursivo(TipoNo* &p, TipoItem item);
        void ApagaRecursivo(TipoNo* &p);

        TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave); 
        void RemoveRecursivo(TipoNo* &p, TipoChave chave);  
        void Antecessor(TipoNo* q, TipoNo* &r); 

        void PorNivel();
        void PreOrdem(TipoNo* p);
        void InOrdem(TipoNo* p, string nomeArquivoDeSaida);

        void RemoveVerbetesComSignificado(TipoNo* &p);  

        void PosOrdem(TipoNo* p);

        TipoNo* raiz;

        int numMaximoDeVerbetes;
};

#endif