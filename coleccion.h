#ifndef COLECCION_H
#define COLECCION_H
#include <iostream>
#include <vector>
#include <string>
#include "pelicula.h"
#include "capitulo.h"
using namespace std;

class Coleccion {
    private:
        vector<Filme*> coleccion;
        int tamanoColeccion;
    public:
        Coleccion();
        void cargarArchivoCrearObjetos(string videos);
        void imprimirColeccion();
        bool calificarFilme(string ID, int calificacion);
        void filtrarCalificacion(int seleccion, int calificacion);
        bool filtrarGenero(int seleccion, string genero);
};

#endif