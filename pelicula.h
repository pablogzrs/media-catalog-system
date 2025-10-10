#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include <vector>
#include <string>
#include "filme.h"
using namespace std;

class Pelicula : public Filme {
    public:
        Pelicula();
        Pelicula(string id, string titulo, string genero, int duracion);
        void funcionInutil();
};

#endif

