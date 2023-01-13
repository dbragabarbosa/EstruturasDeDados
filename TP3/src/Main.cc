#include <iostream>
#include <fstream>
#include <string>

#include "Dicionario.h"
#include "TipoItem.h"
#include "TipoNo.h"
#include "Verbete.h"
#include "FilaDeSignificados.h"

using namespace std;


// Objetivo

// O objetivo deste trabalho é projetar, codificar e avaliar diferentes implementações de um dicionário de 
// palavras. O dicionário deve permitir consultas, inserções, retiradas, impressão ordenada e atualização de uma 
// entrada. Cada entrada tem como chave uma palavra, seu tipo e zero ou mais significados da palavra (a palavra 
// pode aparecer no dicionário, mas ainda sem algum significado associado). Você deve comparar duas implementações, 
// uma baseada em árvore de pesquisa balanceada e outra baseada em hash, as quais devem ser comparadas considerando 
// uma carga de trabalho típica do dicionário (faz parte do trabalho definir cargas de trabalho típicas).

// O foco da avaliação é verificar o funcionamento correto do sistema ao executar cargas de trabalho típicas e
// mesmo partes dela, caracterizando diferentes situações. A análise de complexidade das funções implementadas será 
// avaliada na documentação, e é necessário fazer uma comparação descrevendo as vantagens e desvantagens de cada 
// implementação.


// Quais TADs implementar?
// Você deverá implementar pelo menos três Tipos Abstratos de Dados (TADs): o primeiro para o dicionário, o 
// segundo para verbete e o terceiro para o significado do verbete. Detalhes de implementação como o tamanho do 
// hash e a função hash são parte do projeto.


int main()
{
// Parâmetros

// O seu programa deve aceitar três parâmetros:

// -i: informa o nome do arquivo de entrada
// -o: informa o nome do arquivo de saída
// -t: informa a implementação a ser utilizada: hash ou arv

// Exemplo:

// bin/tp3 -i entrada.txt -o saida.txt -t arv
// bin/tp3 -i entrada.txt -o saida.txt -t hash

    // lendo os parametros
    string bin, i, nomeArquivoDeEntrada, o, nomeArquivoDeSaida, t, tipoDeImplementacao;

    cin >> bin;
    cin >> i;
    cin >> nomeArquivoDeEntrada;
    cin >> o;
    cin >> nomeArquivoDeSaida;
    cin >> t;
    cin >> tipoDeImplementacao;


// O programa principal deve ser idêntico, independente da implementação interna do TAD Dicionario. O 
// programa vai realizar a seguinte sequência de operações:

// 1. Criar o dicionário, indicando o número máximo de verbetes a ser inseridos (que pode ser o número de 
// linhas do arquivo de entrada).


    //  A entrada do programa é um arquivo contendo palavras e seus significados. Cada linha do arquivo tem o 
    // seguinte formato:

    // a [applied] concerned with concrete problems or data

    // onde:
    // a - indica o tipo da verbete (adjetivo, nome ou verbo).
    // [applied] - é verbete (sem os colchetes).
    // concerned with concrete problems or data - é o significado do verbete.

    // Note que um verbete pode conter mais de um significado, como no exemplo a seguir:

    // a [bad] immoral, evil
    // a [bad] below average in quality or performance, defective
    // a [bad] spoiled, spoilt, capable of harming

    // Ou nenhum significado até o momento:

    // a [artistic]
    // a [ashamed]
    // a [asleep]

    // contar o numero de linhas do arquivo de entrada
    ifstream arquivoDeEntrada;
    arquivoDeEntrada.open(nomeArquivoDeEntrada);

    int numeroMaximoDeVerbetes = 0;
    string linha;
    string tipoDeVerbete;
    string verbete;
    string significadoCompleto;


    while (getline(arquivoDeEntrada, linha))
    {
        numeroMaximoDeVerbetes++;
    }

    arquivoDeEntrada.close();

// 1. Criar o dicionário, indicando o número máximo de verbetes a ser inseridos (que pode ser o número de 
// linhas do arquivo de entrada).

    Dicionario *dicionario = new Dicionario();
    dicionario->SetNumMaximoDeVerbetes(numeroMaximoDeVerbetes);

// 2. Inserir no dicionário criado todos os verbetes e seus significados a partir do arquivo de entrada. Note 
// que um verbete pode ter mais de um significado e a estrutura de dados deve permitir o armazenamento dos 
// potencialmente vários significados de um verbete.

    ifstream arquivoDeEntrada2;
    arquivoDeEntrada2.open(nomeArquivoDeEntrada);

    TipoItem *itemAuxiliar = new TipoItem();

    while (getline(arquivoDeEntrada2, linha))
    {
        // até o primeiro espaço, tira de linha  e coloca em tipoDeVerbete
        tipoDeVerbete = linha.substr(0, linha.find(" "));
        itemAuxiliar->chave.tipo = tipoDeVerbete;

        // o que tiver entre os colchetes, tira de linha e coloca em verbete
        verbete = linha.substr(linha.find("[") + 1, linha.find("]") - linha.find("[") - 1);
        itemAuxiliar->chave.palavra = verbete;

        // o que tiver depois do colchete fechado, tira de linha e coloca em significadoCompleto
        significadoCompleto = linha.substr(linha.find("]") + 1, linha.length() - linha.find("]") - 1);
        itemAuxiliar->chave.significados.Enfileira(significadoCompleto, verbete);

        if (significadoCompleto != ""){
            itemAuxiliar->chave.temSignificado = true;
        }
        else{
            itemAuxiliar->chave.temSignificado = false;
        }

        dicionario->Insere(*itemAuxiliar);
    }


// 3. Imprimir o dicionário resultante em ordem alfabética dos verbetes e ordem de inserção dos significados 
// dos verbetes. Por exemplo, os verbetes artistic e bad, cujos significados foram apresentados acima, seriam 
// impressos como:

// artistic(a)
// bad (a)
// 1. immoral, evil
// 2. below average in quality or performance, defective
// 3. spoiled, spoilt, capable of harming


    ofstream arquivoDeSaida;
    arquivoDeSaida.open(nomeArquivoDeSaida, ios::app);

    dicionario->InOrdem(dicionario->raiz, nomeArquivoDeSaida);


// 4. Remover todos os verbetes que tem pelo menos um significado, pois a empresa que está construindo o 
// dicionário quer saber quais verbetes ainda tem que ser complementados com os seus significados.


    dicionario->RemoveVerbetesComSignificado(dicionario->raiz);


// 5. Imprimir novamente o dicionário, que deve conter apenas os verbetes que não tem significado 
// registrado ainda.


    dicionario->InOrdem(dicionario->raiz, nomeArquivoDeSaida);

    arquivoDeEntrada2.close();


// 6. Destruir o dicionário.


    dicionario->Limpa();


// Avaliação Experimental

// Você deve considerar pelo menos as seguintes dimensões na sua avaliação experimental:

// - Número de verbetes
// - Número máximo de significados por verbete


    return 0;
}