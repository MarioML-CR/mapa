#include <iostream>
#include "../tl/Gestor.h"
#include "utilitario/Validar.h"

using namespace std;

Gestor gestor;
Validar validar;
void menu();
void insertMapa();
void optenerUbicacion();
void procesarMenu(int &, bool &);
void listaAdyacencia();
void listaAdyacenciaXVertice();
void listaPredecesores();
void listaPredecesoresXVertice();
void numVertices();
void recorridoAnchura();
void recorridoProfundidad();
void primeroAnchura();
void primeroProfundidad();
void dijkstra();

int main() {
    insertMapa();
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú Árbol\n\nElija una opción\n" <<
             "01 buscar ubicación\n" <<
             "02 Imprimir sucesores\n" <<
             "03 Imprimir sucesores por vértice\n" <<
             "04 Imprimir predecesores\n" <<
             "05 Imprimir predecesores por vértice\n" <<
             "06 Número de vértices\n" <<
             "07 Recorrido en anchura\n" <<
             "08 Recorrido en profundidad\n" <<
             "09 Primero en anchura\n" <<
             "10 Primero en profundidad\n" <<
             "11 Ruta de menor costo (Dijkstra)\n" <<
             "12 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            optenerUbicacion();
            break;
        case 2:
            listaAdyacencia();
            break;
        case 3:
            listaAdyacenciaXVertice();
            break;
        case 4:
            listaPredecesores();
            break;
        case 5:
            listaPredecesoresXVertice();
            break;
        case 6:
            numVertices();
            break;
        case 7:
            recorridoAnchura();
            break;
        case 8:
            recorridoProfundidad();
            break;
        case 9:
            primeroAnchura();
            break;
        case 10:
            primeroProfundidad();
            break;
        case 11:
            dijkstra();
            break;
        case 12:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}

int ingresarNum(string msg){
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1){
            cout << "El indice ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}

void insertMapa(){
    // inserción de vértices
    string ubic[82] = {"San José", "Escazú", "Desamparados", "Puriscal", "Tarrazú", "Aserrí", "Mora",
                       "Goicoechea", "Santa_Ana", "Alajuelita", "Vázquez_de_Coronado", "Acosta", "Tibás",
                       "Moravia", "Montes_de_Oca", "Turrubares", "Dota", "Curridabat", "Pérez_Zeledón",
                       "León_Cortés_Castro", "Alajuela", "San_Ramón", "Grecia", "San_Mateo", "Atenas",
                       "Naranjo", "Palmares", "Poás", "Orotina", "San_Carlos", "Zarcero", "Valverde_Vega",
                       "Upala", "Los_Chiles", "Guatuso", "Cartago", "Paraíso","La_Unión", "Jiménez",
                       "Turrialba", "Alvarado", "Oreamuno", "El_Guarco", "Heredia", "Barva", "Santo_Domingo",
                       "Santa_Bárbara", "San_Rafael", "San_Isidro", "Belén", "Flores", "San_Pablo",
                       "Sarapiquí", "Liberia", "Nicoya", "Santa_Cruz", "Bagaces", "Carrillo", "Cañas",
                       "Abangares", "Tilarán", "Nandayure", "La_Cruz", "Hojancha", "Puntarenas", "Esparza",
                       "Buenos_Aires", "Montes_de_Oro", "Osa", "Aguirre", "Golfito", "Coto_Brus", "Parrita",
                       "Corredores", "Garabito", "Limón", "Pococí", "Siquirres", "Talamanca", "Matina",
                       "Guácimo", "Río_Cuarto"}
    string nombres[7] = {"SAN_JOSé", "ALAJUELA", "CARTAGO", "HEREDIA", "PUNTARENAS", "GUANACASTE", "LIMóN"};
    for (int i = 0; i < 7; ++i) {
        gestor.insertVertice(nombres[i]);
        gestor.addUbicaciones(nombres[i]);
    }
    // inserción de aristas
    gestor.insertaArista("SAN_JOSé", "CARTAGO", 500);
    gestor.insertaArista("SAN_JOSé", "HEREDIA", 200);
    gestor.insertaArista("SAN_JOSé", "GUANACASTE", 600);
    gestor.insertaArista("ALAJUELA", "PUNTARENAS", 100);
    gestor.insertaArista("ALAJUELA", "CARTAGO", 500);
    gestor.insertaArista("CARTAGO", "GUANACASTE", 200);
    gestor.insertaArista("HEREDIA", "ALAJUELA", 300);
    gestor.insertaArista("HEREDIA", "GUANACASTE", 800);
    gestor.insertaArista("PUNTARENAS", "SAN_JOSé", 400);
    gestor.insertaArista("PUNTARENAS", "CARTAGO", 300);
    gestor.insertaArista("GUANACASTE", "PUNTARENAS", 300);
    gestor.insertaArista("LIMóN", "SAN_JOSé", 480);
    gestor.insertaArista("LIMóN", "HEREDIA", 220);
    gestor.insertaArista("LIMóN", "CARTAGO", 560);
    cout << "La carga se realizó satisfactoriamente. Para ver reportes vuelva al menú principal\n";
}
void optenerUbicacion(){
    string loc;
    cout << "Ingrese el nombre de la ubicación a buscar\n";
    cin >> loc;
    for (auto & c: loc) c = toupper(c);
    cout << gestor.optenerUbicacion(loc);
}
void listaAdyacencia(){
    cout << gestor.listaAdyacencia();
}
void listaAdyacenciaXVertice(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vértice del cual desea mostrar sus adyacencias\n";
        cin >> vertice;
        for (auto & c: vertice) c = toupper(c);
        cout << gestor.listaAdyacenciaXVertice(vertice);
    }
}
void listaPredecesores(){
    cout << gestor.listaPredecesores();
}
void listaPredecesoresXVertice(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vértice del cual desea mostrar sus predecesores\n";
        cin >> vertice;
        for (auto & c: vertice) c = toupper(c);
        cout << gestor.listaPredecesoresXVertice(vertice);
    }
}
void eliminarVertice(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vértice que desea eliminar\n";
        cin >> vertice;
        for (auto & c: vertice) c = toupper(c);
        cout << gestor.eliminarVertice(vertice);
    }
}
void eliminarArista(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string origen, destino;
        cout << "Ingrese la ciudad de origen\n";
        cin >> origen;
        for (auto & c: origen) c = toupper(c);
        cout << "Ingrese la ciudad de destino\n";
        cin >> destino;
        for (auto & c: destino) c = toupper(c);
        cout << gestor.eliminarArista(origen, destino) << endl;
    }

}
void eliminarGrafo(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        gestor.eliminarGrafo();
    }

}
void numVertices(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        cout << "La matriz de adyacencia tiene " + to_string(gestor.numVertices()) + " vértices\n";
    }
}
void recorridoAnchura(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string nombre;
        cout << "Ingrese el nombre del vértice inicial\n";
        cin.ignore();
        getline(cin, nombre, '\n');
        for (auto & c: nombre) c = toupper(c);
        cout << gestor.recorridoAnchura(nombre);
    }
}
void recorridoProfundidad(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string nombre;
        cout << "Ingrese el nombre del vértice inicial\n";
        cin.ignore();
        getline(cin, nombre, '\n');
        for (auto & c: nombre) c = toupper(c);
        cout << gestor.recorridoProfundidad(nombre);
    }
}
void primeroAnchura(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string origen, destino;
        cout << "Ingrese el nombre del vértice origen\n";
        cin >> origen;
        for (auto & c: origen) c = toupper(c);
        cout << origen << endl;
        cout << "Ingrese el nombre del vértice destino\n";
        cin >> destino;
        for (auto & c: destino) c = toupper(c);
        cout << gestor.primeroAnchura(origen, destino);
    }
}
void primeroProfundidad(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string origen, destino;
        cout << "Ingrese el nombre de la vértice de origen\n";
        cin >> origen;
        for (auto & c: origen) c = toupper(c);
        cout << "Ingrese el nombre de la vértice de destino\n";
        cin >> destino;
        for (auto & c: destino) c = toupper(c);
        cout << gestor.primeroProfundidad(origen, destino);
    }
}
void dijkstra(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string origen, destino;
        cout << "Ingrese el nombre de la vértice de origen\n";
        cin >> origen;
        for (auto & c: origen) c = toupper(c);
        cout << "Ingrese el nombre de la vértice de destino\n";
        cin >> destino;
        for (auto & c: destino) c = toupper(c);
        cout << gestor.dijkstra(origen, destino);
    }
}

