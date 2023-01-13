#ifndef TIPONO_H
#define TIPONO_H

#include <iostream>
#include <string>

#include "TipoItem.h"

using namespace std;

typedef string TipoChave; // TipoChave é uma string

class TipoNo
{
    public:
        TipoNo();

        TipoItem item;   

        int altura;  

        TipoNo* esq;  
        TipoNo* dir;    
        TipoNo* pai;    

        int max(int v1, int v2);  
        int height(TipoNo* node);  
        int balanceFactor(TipoNo* node);  

};

#endif