#include "ListaEncadeada.h"
#include "TipoCelula.h"
#include "TipoItem.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ListaEncadeada* contas = new ListaEncadeada();;      
    // FilaEncadeada* emails = new FilaEncadeada();;
    ListaEncadeada* emailsEnviados = new ListaEncadeada();;
    

    ifstream file;
    file.open("input.txt");

    string palavra;
    int num_id;
    int prioridade;
    string mensagem;
    string mensagemAuxiliar;

    while(file)
    {
        file >> palavra; 

        if(file.eof())
        {
            break;
        }

        if(palavra  ==  "CADASTRA")
        {
            file >> num_id;
            contas->InsereFinal(num_id);
        }
        else if(palavra == "REMOVE")
        {
            file >> num_id;
            contas->RemovePosicao(num_id);
        }
        else if(palavra == "ENTREGA")
        {
            file >> num_id >> prioridade;
            while(file >> mensagemAuxiliar)
            {
                if(mensagemAuxiliar == "FIM"){
                    break;
                }
                else{
                    mensagem += mensagemAuxiliar + " ";
                }
            }
            // emails->EnfileiraComPrioridade(num_id, prioridade, mensagem);
            TipoItem temp = num_id;
            if(!(contas->Pesquisa(temp.GetChave()))) {
                cout << "ERRO: CONTA " << temp.GetChave() << " NÃO EXISTE" << endl;
            }
            else{
                emailsEnviados->InsereComPrioridade(num_id, prioridade, mensagem);
            }
            mensagem = "";
        }
        else if(palavra == "CONSULTA")
        {
            file >> num_id;
            TipoItem temp = num_id;
            if(!(contas->Pesquisa(temp.GetChave()))) {
                cout << "ERRO: CONTA " << temp.GetChave() << " NÃO EXISTE" << endl;
            }
            else{
                emailsEnviados->ImprimeMensagem(num_id);
            }
        }
    }






    return 0;
}