#include <iostream>
#include <vector>
#include <string>
#include "filme.h"
using namespace std;

Filme::Filme(){
    this->id="";
    this->titulo="";
    this->genero="";
    this->duracion=0;
    this->numeroCalificaciones=0;
}

Filme::Filme(string id, string titulo, string genero, int duracion){
    this->id=id;
    this->titulo=titulo;
    this->genero=genero;
    this->duracion=duracion;
    this->numeroCalificaciones=0;
}

void Filme::calificar(int calificacion) {
    this->calificaciones.push_back(calificacion);
    this->numeroCalificaciones++;
}

string Filme::promedio(){
    if(numeroCalificaciones==0){
        return "SC";
    }
    double suma=0;
    for (int i=0; i<this->numeroCalificaciones; i++) {
        suma+=this->calificaciones[i];
    }
    double promedio =suma/this->numeroCalificaciones;
    // El formateo del promedio a un entero y a un decimal se hace con el siguiente bloque. El mismo fue creado con Claude AI.
    int parteEntera = static_cast<int>(promedio);     
    int parteDecimal= static_cast<int>(promedio * 10) % 10;  
    return to_string(parteEntera)+"."+to_string(parteDecimal);
}

string Filme::getID(){
    return this->id;
}

string Filme::getGenero(){
    return this->genero;
}

string Filme::getTitulo(){
    return this->titulo;
}


ostream& operator<<(ostream& os, Filme& filme){
    string regreso=filme.id+","+filme.titulo+","+to_string(filme.duracion)+","+filme.genero+","+filme.promedio();
    os<<regreso;
    return os;
}