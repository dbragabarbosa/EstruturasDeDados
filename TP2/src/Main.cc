#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/resource.h>
#include "Registro.h"
#include "Pilha.h"
#include "PilhaEncadeada.h"
#include "TipoUnidade.h"
#include "TipoCelula.h"

using namespace std;

// declara as variáveis globais para contar as comparações e cópias 
int numeroDeComparacoesDeChavesQuickSort = 0;
int numeroDeCopiasDeRegistrosQuickSort = 0;


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO QUICKSORT
void Particao(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x, w;   
    *i = Esq; *j = Dir;  

    x = A[(*i + *j) / 2]; // obtem o pivo x

    do
    {
        while (x.chave > A[*i].chave) // procura elemento maior que o pivo 
        {
            (*i)++; // incrementa i
            numeroDeComparacoesDeChavesQuickSort++;  // incrementa o contador de comparações
        }
        numeroDeComparacoesDeChavesQuickSort++;  // incrementa o contador de comparações pois o if deu false

        while (x.chave < A[*j].chave) // procura elemento menor que o pivo 
        {
            (*j)--;  // decrementa j
            numeroDeComparacoesDeChavesQuickSort++;  // incrementa o contador de comparações
        }
        numeroDeComparacoesDeChavesQuickSort++;  // incrementa o contador de comparações pois o if deu false

        if (*i <= *j)  
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);  // enquanto i e j não se cruzam
}

void Ordena (int Esq, int Dir, Item *A)
{
    int i;
    int j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) 
    { 
        Ordena(Esq, j, A);
    }
    if (i < Dir) 
    {
        Ordena(i, Dir, A);
    }
}

void QuickSort(Item *A, int n)
{
    Ordena(0, n-1, A);
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
//  ALGORITMO QUICKSORT MEDIANA DE 3
void ParticaoM3(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x, w;
    *i = Esq; *j = Dir;

    // escolhe o pivo para a particao como sendo a mediana de 3 elementos do vetor, aleatoriamente escolhidos
    int i1 = rand() % (Dir - Esq + 1) + Esq;
    int i2 = rand() % (Dir - Esq + 1) + Esq;
    int i3 = rand() % (Dir - Esq + 1) + Esq;

    if((A[i1].chave >= A[i2].chave && A[i1].chave <= A[i3].chave) || (A[i1].chave <= A[i2].chave && A[i1].chave >= A[i3].chave))
    {
        x = A[i1];
        numeroDeComparacoesDeChavesQuickSort += 4;
    }
    else if((A[i2].chave >= A[i1].chave && A[i2].chave <= A[i3].chave) || (A[i2].chave <= A[i1].chave && A[i2].chave >= A[i3].chave))
    {
        x = A[i2];
        numeroDeComparacoesDeChavesQuickSort += 4;
    }
    else
    {
        x = A[i3];
        numeroDeComparacoesDeChavesQuickSort += 8;
    }

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void OrdenaM3 (int Esq, int Dir, Item *A)
{
    int i;
    int j;
    ParticaoM3(Esq, Dir, &i, &j, A);
    if (Esq < j) 
    { 
        OrdenaM3(Esq, j, A);
    }
    if (i < Dir) 
    {
        OrdenaM3(i, Dir, A);
    }
}

void QuickSortM3(Item *A, int n)
{
    OrdenaM3(0, n-1, A);
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO QUICKSORT MEDIANA DE 5
void BolhaM5(Item *v, int n)
{
    int i, j, trocou;

    for(i = 0; i < n-1; i++)
    {
        trocou = 0;
        for(j = 1; j < n-1; j++)
        {
            if(v[j].chave < v[j-1].chave)
            {
                numeroDeComparacoesDeChavesQuickSort++;
                Item aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                trocou = 1;
                numeroDeCopiasDeRegistrosQuickSort += 3;
            }
            numeroDeComparacoesDeChavesQuickSort++;
            if(!trocou){
                break;
            }
        }
    }
}

void ParticaoM5(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x, w;
    *i = Esq; *j = Dir;

    // escolhe o pivo para a particao como sendo a mediana de 5 elementos do vetor, aleatoriamente escolhidos
    int i1 = rand() % (Dir - Esq + 1) + Esq;
    int i2 = rand() % (Dir - Esq + 1) + Esq;
    int i3 = rand() % (Dir - Esq + 1) + Esq;
    int i4 = rand() % (Dir - Esq + 1) + Esq;
    int i5 = rand() % (Dir - Esq + 1) + Esq;
    // adiociona os 5 elementos escolhidos em um vetor auxiliar
    Item y[5];
    y[0] = A[i1];
    y[1] = A[i2];
    y[2] = A[i3];
    y[3] = A[i4];
    y[4] = A[i5];
    // ordena o vetor auxiliar com o método Bolha
    BolhaM5(y, 5);

    // o pivo é o elemento do meio do vetor auxiliar
    x = y[2];

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void OrdenaM5 (int Esq, int Dir, Item *A)
{
    int i;
    int j;
    ParticaoM5(Esq, Dir, &i, &j, A);
    if (Esq < j) 
    { 
        OrdenaM5(Esq, j, A);
    }
    if (i < Dir) 
    {
        OrdenaM5(i, Dir, A);
    }
}

void QuickSortM5(Item *A, int n)
{
    OrdenaM5(0, n-1, A);
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO QUICKSORT MEDIANA DE 7
void BolhaM7(Item *v, int n)
{
    int i, j, trocou;

    for(i = 0; i < n-1; i++)
    {
        trocou = 0;
        for(j = 1; j < n-1; j++)
        {
            if(v[j].chave < v[j-1].chave)
            {
                numeroDeComparacoesDeChavesQuickSort++;
                Item aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                trocou = 1;
                numeroDeCopiasDeRegistrosQuickSort += 3;
            }
            numeroDeComparacoesDeChavesQuickSort++;
            if(!trocou){
                break;
            }
        }
    }
}

void ParticaoM7(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x, w;
    *i = Esq; *j = Dir;

    // escolhe o pivo para a particao como sendo a mediana de 7 elementos do vetor, aleatoriamente escolhidos
    int i1 = rand() % (Dir - Esq + 1) + Esq;
    int i2 = rand() % (Dir - Esq + 1) + Esq;
    int i3 = rand() % (Dir - Esq + 1) + Esq;
    int i4 = rand() % (Dir - Esq + 1) + Esq;
    int i5 = rand() % (Dir - Esq + 1) + Esq;
    int i6 = rand() % (Dir - Esq + 1) + Esq;
    int i7 = rand() % (Dir - Esq + 1) + Esq;
    // adiociona os 7 elementos escolhidos em um vetor auxiliar
    Item s[7];
    s[0] = A[i1];
    s[1] = A[i2];
    s[2] = A[i3];
    s[3] = A[i4];
    s[4] = A[i5];
    s[5] = A[i6];
    s[6] = A[i7];
    // ordena o vetor auxiliar com o método Bolha
    BolhaM7(s, 7);

    // o pivo é o elemento do meio do vetor auxiliar
    x = s[3];

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void OrdenaM7(int Esq, int Dir, Item *A)
{
    int i;
    int j;
    ParticaoM7(Esq, Dir, &i, &j, A);
    if (Esq < j) 
    { 
        OrdenaM7(Esq, j, A);
    }
    if (i < Dir) 
    {
        OrdenaM7(i, Dir, A);
    }
}

void QuickSortM7(Item *A, int n)
{
    OrdenaM7(0, n-1, A);
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO QUICKSORT SELECAO COM M = 10
void Selecao10(Item *v, int n)
{
    int i, j, Min;

    for(i = 0; i < n-1; i++)
    {
        Min = i;
        for( j = i+1; j < n; j++)
        {
            if(v[j].chave < v[Min].chave)
            {
                Min = j;
                numeroDeComparacoesDeChavesQuickSort++;
            }
            numeroDeComparacoesDeChavesQuickSort++;
            // troca v[i] com v[min]
            Item aux = v[i];
            v[i] = v[Min];
            v[Min] = aux;
            numeroDeCopiasDeRegistrosQuickSort += 3;
        }
    }
}

void ParticaoSelecao10(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x, w;
    *i = Esq; *j = Dir;

    x = A[(*i + *j) / 2]; // obtem o pivo x

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void OrdenaSelecao10(int Esq, int Dir, Item *A)
{
    int i;
    int j;
    ParticaoSelecao10(Esq, Dir, &i, &j, A);
    if (Esq < j) 
    { 
        if(j - Esq <= 10){
            Selecao10(A, j - Esq + 1);
        }
        else{
            OrdenaSelecao10(Esq, j, A);
        }
    }
    if (i < Dir) 
    {
        if(Dir - i <= 10){
            Selecao10(A, Dir - i + 1);
        }
        else{
            OrdenaSelecao10(i, Dir, A);
        }

    }
}

void QuickSortSelecao10(Item *A, int n)
{
    OrdenaSelecao10(0, n-1, A);
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO QUICKSORT SELECAO COM M = 100
void Selecao100(Item *v, int n)
{
    int i, j, Min;

    for(i = 0; i < n-1; i++)
    {
        Min = i;
        for( j = i+1; j < n; j++)
        {
            if(v[j].chave < v[Min].chave)
            {
                Min = j;
                numeroDeComparacoesDeChavesQuickSort++;
            }
            numeroDeComparacoesDeChavesQuickSort++;
            // troca v[i] com v[min]
            Item aux = v[i];
            v[i] = v[Min];
            v[Min] = aux;
            numeroDeCopiasDeRegistrosQuickSort += 3;
        }
    }
}

void ParticaoSelecao100(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x, w;
    *i = Esq; *j = Dir;

    x = A[(*i + *j) / 2]; // obtem o pivo x

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void OrdenaSelecao100(int Esq, int Dir, Item *A)
{
    int i;
    int j;
    ParticaoSelecao100(Esq, Dir, &i, &j, A);
    if (Esq < j) 
    { 
        if(j - Esq <= 100){
            Selecao100(A, j - Esq + 1);
        }
        else{
            OrdenaSelecao100(Esq, j, A);
        }
    }
    if (i < Dir) 
    {
        if(Dir - i <= 100){
            Selecao100(A, Dir - i + 1);
        }
        else{
            OrdenaSelecao100(i, Dir, A);
        }

    }
}

void QuickSortSelecao100(Item *A, int n)
{
    OrdenaSelecao100(0, n-1, A);
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
// ALGORITMO QUICKSORT NAO RECURSIVO
void ParticaoQuicksortNaoRecursivo(Item *A, int esq, int dir, int *i, int *j)
{
    Item x, w;
    *i = esq; *j = dir;

    x = A[(*i + *j) / 2]; // obtem o pivo x

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void QuickSortNaoRecursivo(Item *A, int n)
{
    // declara a pilha
    PilhaEncadeada pilha;

    TipoUnidade item;  // campos esq e dir       // guarda o intervalo do vetor sendo considerado

    int esq, dir, i, j;   // declara as variáveis que vão armazenar o intervalo sendo considerado a cada iteração(esq e dir) e que vão percorrer o vetor (i, j)

    // Inicializa a pilha como vazia
    pilha.Inicializa();

    esq = 0;    // inicializa o intervalo sendo considerado como o vetor inteiro
    dir = n-1;  // inicializa o intervalo sendo considerado como o vetor inteiro

    item.dir = dir;  // empilha o intervalo de todo o vetor
    item.esq = esq;  

    pilha.Empilha(item);

    do 
    {
        if(dir > esq)  // Se o intervalo ainda tem elementos a serem considerados 
        {
            ParticaoQuicksortNaoRecursivo(A, esq, dir, &i, &j);  // faz a partição 

            item.dir = j;           // empilha o lado esquerdo
            item.esq = esq;

            pilha.Empilha(item);

            esq = i;   // atualiza o índice da esquerda como sendo o primeiro elemento do lado direito
        }
        else // se não tiver mais elementos para serem tratados
        {
            item = pilha.DesempilhaComRetorno();  // desempilha o próximo intervalo a ser considerado

            dir = item.dir;   // atualiza os índices para considerar o intervalo desempilhado
            esq = item.esq;
        }
    } while(!pilha.Vazia());  // enquanto a pilha não estiver vazia
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
// ALGORITMO QUICKSORT EMPILHA INTELIGENTE
void ParticaoQuicksortEmpilhaInteligente(Item *A, int esq, int dir, int *i, int *j)
{
    Item x, w;
    *i = esq; *j = dir;

    x = A[(*i + *j) / 2]; // obtem o pivo x

    do
    {
        while (x.chave > A[*i].chave) 
        {
            (*i)++;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        while (x.chave < A[*j].chave) 
        {
            (*j)--;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        numeroDeComparacoesDeChavesQuickSort++;

        if (*i <= *j)
        {
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

            numeroDeCopiasDeRegistrosQuickSort += 3;

            (*i)++; 
            (*j)--;
        }

    } while (*i <= *j);
}

void QuickSortEmpilhaInteligente(Item *A, int n)
{
    // declara a pilha
    PilhaEncadeada pilha;

    TipoUnidade item;  // campos esq e dir       // guarda o intervalo do vetor sendo considerado

    int esq, dir, i, j;   // declara as variáveis que vão armazenar o intervalo sendo considerado a cada iteração(esq e dir) e que vão percorrer o vetor (i, j)

    // Inicializa a pilha como vazia
    pilha.Inicializa();

    esq = 0;    // inicializa o intervalo sendo considerado como o vetor inteiro
    dir = n-1;  // inicializa o intervalo sendo considerado como o vetor inteiro

    item.dir = dir;  // empilha o intervalo de todo o vetor
    item.esq = esq;  

    pilha.Empilha(item);

    do 
    {
        if(dir > esq)  // Se o intervalo ainda tem elementos a serem considerados 
        {
            ParticaoQuicksortEmpilhaInteligente(A, esq, dir, &i, &j);  // faz a partição 
            
            // verifica o maior lado
            if((j-esq)>(dir-i))  // se o lado esquerdo do vetor for maior que o lado direito
            {
                item.dir = j;           // empilha o lado esquerdo
                item.esq = esq;

                pilha.Empilha(item);

                esq = i;   // atualiza o índice da esquerda como sendo o primeiro elemento do lado direito
            }
            else   // se o lado direito do vetor for maior que o lado esquerdo
            {
                item.esq = i;   // empilha o lado direito
                item.dir = dir;

                pilha.Empilha(item);

                dir = j;  // atualiza o índice da direita como sendo o último elemento do lado esquerdo
            }
        }
        else // se não tiver mais elementos para serem tratados
        {
            pilha.Desempilha();  // desempilha o próximo intervalo a ser considerado


            dir = item.dir;   // atualiza os índices para considerar o intervalo desempilhado
            esq = item.esq;
        }
    } while(!pilha.Vazia());  // enquanto a pilha não estiver vazia
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO MERGESORT
void Merge(int Esq, int meio, int Dir, Item *A) 
{
   int *w;  
   w = (int *) malloc ((Dir-Esq) * sizeof (int));  
   int i = Esq, j = meio;  
   int k = 0;  

   while (i < meio && j < Dir) 
   {  
      if (A[i].chave <= A[j].chave)
      {
            w[k++] = A[i++].chave;
            numeroDeComparacoesDeChavesQuickSort++;
            numeroDeCopiasDeRegistrosQuickSort++;
      } 
      else 
      {
            w[k++] = A[j++].chave;
            numeroDeComparacoesDeChavesQuickSort++;
            numeroDeCopiasDeRegistrosQuickSort++;
      }
   }  
   while (i < meio)
   {
        w[k++] = A[i++].chave;  
        numeroDeCopiasDeRegistrosQuickSort++;
   } 
   while (j < Dir)
   {
        w[k++] = A[j++].chave;  
        numeroDeCopiasDeRegistrosQuickSort++;
   }  
   for (i = Esq; i < Dir; ++i)
   {
        A[i].chave = w[i-Esq];  
        numeroDeCopiasDeRegistrosQuickSort++;
   }  

   free (w);  
}

void MergeSort(int Esq, int Dir, Item *A)
{
   if (Esq < Dir-1) 
   {                 
      int meio = (Esq + Dir)/2; 
               
      MergeSort (Esq, meio, A);        
      MergeSort (meio, Dir, A);        
      Merge (Esq, meio, Dir, A);     
   }
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITMO HEAPSORT
void heapify(Item *A, int n, int i)   // Empilha uma subarvore com raiz em i 
{
    // Inicializa o maior como raiz
    int maior = i; 

    // Esquerda = 2*i + 1
    int Esq = 2 * i + 1; 

    // Direita = 2*i + 2
    int Dir = 2 * i + 2; 
 
    // Se o filho esquerdo for maior que a raiz
    if(Esq < n)
    {
        if(A[Esq].chave > A[maior].chave)
        {
            maior = Esq;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        else {
            numeroDeComparacoesDeChavesQuickSort++;
        }
    }

    // Se o filho direito for maior que o maior
    if(Dir < n)
    {
        if(A[Dir].chave > A[maior].chave)
        {
            maior = Dir;
            numeroDeComparacoesDeChavesQuickSort++;
        }
        else {
            numeroDeComparacoesDeChavesQuickSort++;
        }
    }

    // Se o maior nao for a raiz
    if (maior != i) {
        // troca os valores de A[i].chave e A[maior].chave
        int aux = A[i].chave;
        A[i].chave = A[maior].chave;
        A[maior].chave = aux;
        numeroDeCopiasDeRegistrosQuickSort += 3;
 
        // Agrupa recursivamente a subarvore afetada
        heapify(A, n, maior);
    }
}
 
void HeapSort(Item *A, int n)
{
    // Constrói o heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }

    // Um por um extrai um elemento do heap
    for (int i = n - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        // troca os valores de A[0].chave e A[i].chave
        int aux = A[0].chave;
        A[0].chave = A[i].chave;
        A[i].chave = aux;
        numeroDeCopiasDeRegistrosQuickSort += 3;
 
        // chama para o heap reduzido 
        heapify(A, i, 0);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////


int main(/* int argc, char *argv[] */)
{
    struct rusage resources;
    int rc;
    double utime, stime, total_time;

    /* do some work here */
    ////////////////////////////////////////////////////////////////

    // ler do terminal o comando quicksort -v 1 -s 10 -i entrada.txt -o saida10.txt
    string palavra, vaiLerOMenosV, vaiTerParametro, fimDoParametro, vaiLerOMenosI, nomeDoArquivoDeEntrada, vaiLerOMenosO, nomeDoArquivoDeSaida;
    int numeroQuickSort, parametro, sementeDoGeradorDeNumerosAleatorios;

    cin >> palavra;      
    cin >> vaiLerOMenosV;
    cin >> numeroQuickSort;
    cin >> vaiTerParametro;
    if(vaiTerParametro == "-s")
    {
        parametro = -69;
        fimDoParametro = vaiTerParametro;
    }
    else
    {
        cin >> parametro;
        cin >> fimDoParametro;
    }
    cin >> sementeDoGeradorDeNumerosAleatorios;
    cin >> vaiLerOMenosI;
    cin >> nomeDoArquivoDeEntrada;
    cin >> vaiLerOMenosO;
    cin >> nomeDoArquivoDeSaida;

    ifstream arquivoDeEntrada;
    arquivoDeEntrada.open(nomeDoArquivoDeEntrada);

    int numeroDeValoresDeN;
    arquivoDeEntrada >> numeroDeValoresDeN;

    // 2. Para cada valor de N, lido do arquivo de entrada:
    // a. Gera um conjunto de N elementos aleatoriamente (utilizando a semente passada, 
    //    no caso 10).
    // b. Ordena o conjunto, contabilizando as estatısticas de desempenho
    // c. Armazena estatısticas de desempenho em arquivo de saída

    int auxiliarDeLeitura;
    int valorDeN;
    int contadorDeConjuntosCriados = 0;

    for(auxiliarDeLeitura = 0; auxiliarDeLeitura<numeroDeValoresDeN; auxiliarDeLeitura++)
    {
        arquivoDeEntrada >> valorDeN;
        cout << "valorDeN: " << valorDeN << endl;   
        
        // faz isso 5 vezes
        for(contadorDeConjuntosCriados = 1; contadorDeConjuntosCriados<6; contadorDeConjuntosCriados++)
        {
            // a. Gera um conjunto de N elementos aleatoriamente (utilizando a semente passada)
            srand(sementeDoGeradorDeNumerosAleatorios*contadorDeConjuntosCriados);

            // cria um Item com N posições
            Item *A = new Item[valorDeN];
            for (int i = 0; i < valorDeN; i++)
            {
                // preenche o Item com números aleatórios utilizando a semente passada
                A[i].chave = rand();
            }

            // b. Ordena o conjunto, contabilizando as estatısticas de desempenho

            // ordena o Item
            numeroDeComparacoesDeChavesQuickSort = 0;
            numeroDeCopiasDeRegistrosQuickSort = 0;
            ofstream arquivoDeSaida;
            arquivoDeSaida.open(nomeDoArquivoDeSaida, ios::app);

            if(numeroQuickSort == 1){
                QuickSort(A, valorDeN);
                arquivoDeSaida << "ALGORITMO QUICKSORT RECURSIVO" << endl;
            }
            else if(numeroQuickSort == 2){
                if(parametro == 3){
                    QuickSortM3(A, valorDeN);
                    arquivoDeSaida << "ALGORITMO QUICKSORT MEDIANA DE 3" << endl;
                }
                else if(parametro == 5){
                    QuickSortM5(A, valorDeN);
                    arquivoDeSaida << "ALGORITMO QUICKSORT MEDIANA DE 5" << endl;
                }
                else if(parametro == 7){
                    QuickSortM7(A, valorDeN);
                    arquivoDeSaida << "ALGORITMO QUICKSORT MEDIANA DE 7" << endl;
                }
            }
            else if(numeroQuickSort == 3)
            {
                if(parametro == 10){
                    QuickSortSelecao10(A, valorDeN);
                    arquivoDeSaida << "ALGORITMO QUICKSORT SELECAO PARA M = 10" << endl;
                }
                else if(parametro == 100){
                    QuickSortSelecao100(A, valorDeN);
                    arquivoDeSaida << "ALGORITMO QUICKSORT SELECAO PARA M = 100" << endl;
                }
            } 
            else if(numeroQuickSort == 4)
            { 
                QuickSortNaoRecursivo(A, valorDeN);
                arquivoDeSaida << "ALGORITMO QUICKSORT NAO RECURSIVO" << endl;
            }
            else if(numeroQuickSort == 5)
            {
                QuickSortEmpilhaInteligente(A, valorDeN);
                arquivoDeSaida << "ALGORITMO QUICKSORT EMPILHA INTELIGENTE" << endl;
            }
            else if(numeroQuickSort == 6)
            {
                MergeSort(0, valorDeN, A);
                arquivoDeSaida << "ALGORITMO MERGESORT" << endl;
            }
            else if(numeroQuickSort == 7)
            {
                HeapSort(A, valorDeN);
                arquivoDeSaida << "ALGORITMO HEAPSORT" << endl;
            }

            // imprime o numero de comparacoes e numero de copias
            cout << "Comparacoes: " << numeroDeComparacoesDeChavesQuickSort << endl;  
            cout << "Copias: " << numeroDeCopiasDeRegistrosQuickSort << endl; 


            // c. Armazena estatısticas de desempenho em arquivo de saída
            // escreve no arquivo de saída o número de comparações e o número de cópias
            arquivoDeSaida << "Para o valor de " << valorDeN << " temos:" << endl;
            arquivoDeSaida << "Comparacoes: " << numeroDeComparacoesDeChavesQuickSort << endl;
            arquivoDeSaida << "Copias: " << numeroDeCopiasDeRegistrosQuickSort << endl;


            if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
            perror("getrusage failed");
            utime = (double) resources.ru_utime.tv_sec
            + 1.e-6 * (double) resources.ru_utime.tv_usec; stime = (double) resources.ru_stime.tv_sec
            + 1.e-6 * (double) resources.ru_stime.tv_usec; total_time = utime+stime;

            arquivoDeSaida << "User time " << utime << ", System time " << stime << ", Total Time " << total_time << endl;

            arquivoDeSaida << endl;
        }

    }

    // 3. Ao final, basta processar os arquivos de saída referentes a cada uma das sementes, 
    // calculando as médias de cada estatística, para cada valor de N e algoritmo considerado.

    // O processamento dos arquivos de saída foram feitos no Jupyter Notebook e, posteriormente, a criação de tabelas e gráficos no Excel.
    
    return 0;
}