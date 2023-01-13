#ifndef VERBETE_H 
#define VERBETE_H

#include <iostream>
#include <fstream>
#include <string>

#include "FilaDeSignificados.h"

using namespace std;

typedef struct
{
    string palavra;
    string tipo;

    bool temSignificado; 

    FilaDeSignificados significados;

} Verbete;

#endif