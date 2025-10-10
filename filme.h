#ifndef FILME_H
#define FILME_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Filme {
    protected:
         string id,
                titulo,
                genero;
        int duracion,
            numeroCalificaciones;
        vector<int> calificaciones;
    public:
        Filme();
        Filme(string id, string titulo, string genero, int duracion);
        void calificar(int calificacion);
        string promedio();
        string getID();
        string getGenero();
        string getTitulo();
        friend ostream& operator<<(ostream& os, Filme& filme);
        // Para poder usar dynamic cast en las búsquedas necesito que "filme" sea un objeto polimórfico. Para eso declaro esta funcion virtual, que
        // le da esa particularidad. De ahí en más no sirve para absolutamente nada. 
        virtual void funcionInutil()=0;
};

#endif