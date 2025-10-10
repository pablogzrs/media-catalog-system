#ifndef CAPITULO_H
#define CAPITULO_H
#include <iostream>
#include <vector>
#include <string>
#include "filme.h"
using namespace std;

class Capitulo : public Filme {
    private:
        string serie;
        int temporada,
            episodio;
    public:
        Capitulo();
        Capitulo(string id, string titulo, string genero, int duracion, string serie, int temporada, int episodio);
        friend ostream& operator<<(ostream& os, Capitulo& capitulo);
        void funcionInutil();
};

#endif