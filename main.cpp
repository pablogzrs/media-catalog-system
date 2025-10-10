#include <iostream>
#include <string>
#include "coleccion.h"
using namespace std;

void imprimirMenuPrincipal() {
    cout << "****** OPCIONES *****" << endl;
    cout << "Ingresa 1 para mostrar colección completa" << endl;
    cout << "Ingresa 2 para calificar un filme" << endl;
    cout << "Ingresa 3 para filtrar por calificación" << endl;
    cout << "Ingresa 4 para filtrar por género" << endl;
    cout << "Ingresa 9 para salir" << endl;
    cout << "Selecciona una opción: ";
}

void imprimirMenuFiltros() {
    cout << "¿Qué quieres ver?" << endl;
    cout << "Ingresa 1 para sólo películas" << endl;
    cout << "Ingresa 2 para sólo capítulos" << endl;
    cout << "Ingresa 3 para ver todos los filmes" << endl;
    cout << "Selecciona una opción: ";
}

int main() {
    Coleccion coleccion;
    coleccion.cargarArchivoCrearObjetos("video.txt");
    int opcion;
    
    cout << "****** BIENVENIDO *****" << endl;
    
    while(true) {
        imprimirMenuPrincipal();
        cin >> opcion;
        
        if(opcion == 1) {
            cout << "****** COLECCION *****" << endl;
            coleccion.imprimirColeccion();
        }
        else if(opcion == 2) {
            cout << "****** CALIFICAR FILME ******" << endl;
            string id;
            int calificacion;
            cin.ignore();
            cout << "Ingresa el ID del filme: ";
            getline(cin, id);
            cout << "Ingresa tu calificación (1-5): ";
            cin >> calificacion;

            if(calificacion >= 1 && calificacion <= 5) {
                coleccion.calificarFilme(id, calificacion);
            } else {
                cout << "La calificación debe estar entre 1 y 5" << endl;
            }
        }
        else if(opcion == 3) {
            cout << "****** FILTRAR POR CALIFICACIÓN ******" << endl;
            int seleccion, calificacionMinima;
            imprimirMenuFiltros();
            cin >> seleccion;
            cout << "Ingresa la calificación mínima (1-5): ";
            cin >> calificacionMinima;

            if(seleccion >= 1 && seleccion <= 3 &&
               calificacionMinima >= 1 && calificacionMinima <= 5) {
                coleccion.filtrarCalificacion(seleccion, calificacionMinima);
            } else {
                cout << "Has ingresado un valor inválido. Vuelve a intentarlo." << endl;
            }
        }
        else if(opcion == 4) {
            cout << "****** FILTRAR POR GÉNERO ****** " << endl;
            int seleccion;
            string genero;
            imprimirMenuFiltros();
            cin >> seleccion;
            cin.ignore();
            cout << "Ingresa el género: ";
            getline(cin, genero);

            if(seleccion >= 1 && seleccion<= 3) {
                coleccion.filtrarGenero(seleccion, genero);
            } else {
                cout << "Has ingresado un valor inválido. Vuelve a intentarlo." << endl;
            }
        }
        else if(opcion == 9) {
            cout << "¡Gracias por usar el sistema!" << endl;
            break;
        }
        else {
            cout << "Has ingresado un valor inválido. Vuelve a intentarlo." << endl;
        }
    }
    return 0;
}