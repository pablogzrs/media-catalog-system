#include <iostream>
#include <vector>
#include <string>
#include "pelicula.h"
using namespace std;

Pelicula::Pelicula(){
    this->id="";
    this->titulo="";
    this->genero="";
    this->duracion=0;
    this->numeroCalificaciones=0;
}

Pelicula::Pelicula(string id, string titulo, string genero, int duracion){
    this->id=id;
    this->titulo=titulo;
    this->genero=genero;
    this->duracion=duracion;
    this->numeroCalificaciones=0;
}

void Pelicula::funcionInutil(){} 