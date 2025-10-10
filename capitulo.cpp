#include <iostream>
#include <vector>
#include <string>
#include "capitulo.h"
using namespace std;

Capitulo::Capitulo(){
    this->id="";
    this->titulo="";
    this->genero="";
    this->duracion=0;
    this->numeroCalificaciones=0;
    this->serie="";
    this->temporada=0;
    this->episodio=0;
}

Capitulo::Capitulo(string id, string titulo, string genero, int duracion, string serie, int temporada, int episodio){
    this->id=id;
    this->titulo=titulo;
    this->genero=genero;
    this->duracion=duracion;
    this->numeroCalificaciones=0;
    this->serie=serie;
    this->temporada=temporada;
    this->episodio=episodio;
}

ostream& operator<<(ostream& os, Capitulo& capitulo){
    // El código que trunca la salida a un sólo entero y a un sólo decimal fue tomado de ChatGPT
    string regreso=capitulo.id+","+capitulo.titulo+","+to_string(capitulo.duracion)+","+capitulo.genero+","+capitulo.serie+"T"+to_string(capitulo.temporada)+","+to_string(capitulo.episodio)+","+capitulo.promedio();

    os<<regreso;
    return os;
}

void Capitulo::funcionInutil(){}