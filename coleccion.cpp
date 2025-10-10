#include <iostream>
#include <vector>
#include <string>
#include <fstream>    
#include <sstream>    
#include "pelicula.h"
#include "capitulo.h"
#include "coleccion.h"
using namespace std;

Coleccion::Coleccion(){
    this->tamanoColeccion=0;
}

// Es necesario mencionar que todo este método fue creado con Claude AI. La idea de leer el txt en la coleccion y a partir de ahí llenar su
// vector de filmes con objetos según corresponda sí es mía. Sin embargo, no tenía suficientes conocimientos para implementarla y, contrario a
// otros casos donde la he citado como ayuda puntual, en este caso tiene mucho más peso en mi código. 
// Su funcionamiento es el siguiente: Primero, abre el archivo usando ifstream y lee cada línea completa con getline(). Después, para cada línea, 
//utiliza un stringstream para dividir el contenido por comas, almacenando cada campo en un vector de strings. El resto viene de la identificación 
//de campos de cada objeto: si tiene 4 será película y si tiene 7 será capítulo.Una vez identificado el tipo, convierte los campos numéricos de string 
// a entero usando stoi() y crea dinámicamente el objeto correspondiente (Pelicula o Capitulo) usando new, para guardarlo en el vector de punteros 
// de filmes. También incrementa el contador tamanoColeccion, utilizado en funciones posteriores. 
// Claude. (2025, 15 de junio). Creación de la función cargarArchivoCrearObjetos.
void Coleccion::cargarArchivoCrearObjetos(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string campo;
        vector<string> campos;
    
        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }
        
        if (campos.size() == 4) {
            string id = campos[0];
            string titulo = campos[1];
            int duracion = stoi(campos[2]);
            string genero = campos[3];
            
            Pelicula* nuevaPelicula = new Pelicula(id, titulo, genero, duracion);
            coleccion.push_back(nuevaPelicula);
            tamanoColeccion++;
        }
   
        else if (campos.size() == 7) {
            string id = campos[0];
            string titulo = campos[1];
            int duracion = stoi(campos[2]);
            string genero = campos[3];
            string serie = campos[4];
            int temporada = stoi(campos[5]);
            int episodio = stoi(campos[6]);
            
            Capitulo* nuevoCapitulo = new Capitulo(id, titulo, genero, duracion, serie, temporada, episodio);
            coleccion.push_back(nuevoCapitulo);
            tamanoColeccion++;
        }
    }
    archivo.close();
}

void Coleccion::imprimirColeccion(){
    for(int i = 0; i < tamanoColeccion; i++){
        cout << *coleccion[i] << endl;  
    }
}

bool Coleccion::calificarFilme(string ID, int calificacion){
    for(int i = 0; i < coleccion.size(); i++){
        if(coleccion[i]->getID()==ID){
            coleccion[i]->calificar(calificacion);
            cout<<"Se ha registrado tu calificación"<<endl;
            return true;
        }
    }
    cout<<"El filme no está registrado"<<endl;
    return false;
}

void Coleccion::filtrarCalificacion(int seleccion, int calificacion){
    if(seleccion==1){
        cout << "Peliculas calificadas con al menos: " << to_string(calificacion) << endl;
        for(int i = 0; i < this->tamanoColeccion; i++){
            // Consulté a Claude AI sobre como hacer que un str pase a ser un double. Por eso se usa stod.
            if(coleccion[i]->promedio() != "SC" && stod(coleccion[i]->promedio())>=calificacion){
                if(dynamic_cast<Capitulo*>(coleccion[i]) == nullptr){
                    cout << coleccion[i]->getID() << "," << coleccion[i]->getTitulo() << "," << coleccion[i]->getGenero() << ","<< coleccion[i]->promedio() << endl;
                }
            }
        }
    }
    if(seleccion==2){
        cout << "Capitulos calificados con al menos: " << to_string(calificacion) << endl;
        for(int i = 0; i < this->tamanoColeccion; i++){
            if(coleccion[i]->promedio() != "SC" && stod(coleccion[i]->promedio())>=calificacion){
                if(dynamic_cast<Pelicula*>(coleccion[i]) == nullptr){
                    cout << coleccion[i]->getID() << "," << coleccion[i]->getTitulo() << "," << coleccion[i]->getGenero() << ","<< coleccion[i]->promedio() << endl;
                }
            }
        }
    }
    if(seleccion==3){
        cout << "Filmes calificados con al menos: " << to_string(calificacion) << endl;
        for(int i = 0; i < this->tamanoColeccion; i++){
            if(coleccion[i]->promedio() != "SC" && stod(coleccion[i]->promedio())>=calificacion){
                cout << coleccion[i]->getID() << "," << coleccion[i]->getTitulo() << "," << coleccion[i]->getGenero() << ","<< coleccion[i]->promedio() << endl;
                }
            }
        }
}

bool Coleccion::filtrarGenero(int seleccion, string genero){
   bool generoExiste=false;
    if(seleccion == 1){ 
        cout << "Peliculas del genero: " << genero << endl;
        for(int i = 0; i < this->tamanoColeccion; i++){
            if(coleccion[i]->getGenero() == genero){
                if(dynamic_cast<Capitulo*>(coleccion[i]) == nullptr){
                    cout << coleccion[i]->getID() << "," << coleccion[i]->getTitulo() << "," << coleccion[i]->promedio() << endl;
                    generoExiste = true;
                }
            }
        }
    }
    else if(seleccion == 2){ 
        cout << "Capitulos del genero: " << genero << endl;
        for(int i = 0; i < tamanoColeccion; i++){
            if(coleccion[i]->getGenero() == genero){
                if(dynamic_cast<Pelicula*>(coleccion[i]) == nullptr){
                    cout << coleccion[i]->getID() << "," << coleccion[i]->getTitulo() << "," << coleccion[i]->promedio() << endl;
                    generoExiste = true;
                }
            }
        }
    }
    else if(seleccion == 3){ 
        cout << "Filmes del genero: " << genero << endl;
        for(int i = 0; i < tamanoColeccion; i++){
            if(coleccion[i]->getGenero() == genero){
                cout << coleccion[i]->getID() << "," << coleccion[i]->getTitulo() << "," << coleccion[i]->promedio() << endl;
                generoExiste = true;
            }
        }
    }
    
    if(generoExiste==false){
        cout << "Lo sentimos, no hay filmes registrados con ese genero" << endl;
    }
    
    return generoExiste;
}