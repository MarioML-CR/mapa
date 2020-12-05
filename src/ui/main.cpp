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

void insertMapa(){
    // inserción de vértices
    string ubic[32] = {"san_jose", "volcan_arenal", "monteverde", "volcan_poas", "santa_rosa",
                       "golfo_papagayo", "conchal", "flamingo", "tamarindo", "montezuma",
                       "isla_tortuga",  "carara", "jaco", "manuel_antonio", "donimical",
                       "bahia_drake", "isla_del_cano", "corcovado", "golfito", "talamanca",
                       "sarapiqui", "braulio_carrillo", "volcan_irazu", "tortuguero", "siquirres",
                       "rio_pacuare", "cahuita", "punta_uva", "puerto_viejo", "manzanillo",
                       "puntarenas", "liberia"};
    for (int i = 0; i < 32; ++i) {
        for (auto & c: ubic[i]) c = toupper(c);
        gestor.insertVertice( ubic[i]);
        gestor.addUbicaciones(ubic[i]);
    }
    // inserción de aristas
    /**
    CARARA
    CONCHAL
    CAHUITA
    GOLFITO
    JACO
    FLAMINGO
    TALAMANCA
    DONIMICAL
    TAMARINDO
    CORCOVADO
    MONTEZUMA
    SIQUIRRES
    PUNTA_UVA
    MANZANILLO
    MONTEVERDE
    SANTA_ROSA
    TORTUGUERO
    SAN_JOSE
    ISLA_TORTUGA
    PUERTO_VIEJO
    SARAPIQUI
    GOLFO_PAPAGAYO
    MANUEL_ANTONIO
    BAHIA_DRAKE
    RIO_PACUARE
    VOLCAN_POAS
    BRAULIO_CARRILLO
    VOLCAN_ARENAL
    ISLA_DEL_CANO
    VOLCAN_IRAZU
    PUNTARENAS
    */
    gestor.insertaArista("SAN_JOSE", "VOLCAN_POAS", 48.8);
    gestor.insertaArista("SAN_JOSE", "BRAULIO_CARRILLO", 53.5);
    gestor.insertaArista("SAN_JOSE", "VOLCAN_IRAZU", 51);
    gestor.insertaArista("SAN_JOSE", "CARARA", 75.6);
//    gestor.insertaArista("CARARA", "SAN_JOSE", 75.6); // TODO: revisar
    gestor.insertaArista("BRAULIO_CARRILLO", "SARAPIQUI", 44);
    gestor.insertaArista("BRAULIO_CARRILLO", "VOLCAN_POAS", 25.1);
    gestor.insertaArista("VOLCAN_POAS", "PUNTARENAS", 106);
    gestor.insertaArista("VOLCAN_POAS", "VOLCAN_ARENAL", 117);
    gestor.insertaArista("PUNTARENAS", "MONTEVERDE", 62.7);

    gestor.insertaArista("PUNTARENAS", "ISLA_TORTUGA", 59.6);
    gestor.insertaArista("PUNTARENAS", "TAMARINDO", 171);
    gestor.insertaArista("PUNTARENAS", "FLAMINGO", 187);
    gestor.insertaArista("PUNTARENAS", "CONCHAL", 188);
    gestor.insertaArista("PUNTARENAS", "GOLFO_PAPAGAYO", 162);
    gestor.insertaArista("PUNTARENAS", "MONTEZUMA", 87.4);
    gestor.insertaArista("PUNTARENAS", "LIBERIA", 125);
    gestor.insertaArista("MONTEZUMA", "TAMARINDO", 184);
    gestor.insertaArista("FLAMINGO", "TAMARINDO", 23.8);
    gestor.insertaArista("FLAMINGO", "CONCHAL", 6.2);
    gestor.insertaArista("GOLFO_PAPAGAYO", "CONCHAL", 57);
    gestor.insertaArista("LIBERIA", "GOLFO_PAPAGAYO", 42.1);

    gestor.insertaArista("MONTEVERDE", "VOLCAN_ARENAL", 105);
    gestor.insertaArista("CARARA", "JACO", 23.8);
    gestor.insertaArista("CARARA", "PUNTARENAS", 39.2);
    gestor.insertaArista("JACO", "MANUEL_ANTONIO", 78.8);
    gestor.insertaArista("MANUEL_ANTONIO", "DONIMICAL", 49.8);
    gestor.insertaArista("DONIMICAL", "BAHIA_DRAKE", 165);
    gestor.insertaArista("BAHIA_DRAKE", "GOLFITO", 93.9);
    gestor.insertaArista("BAHIA_DRAKE", "ISLA_DEL_CANO", 30);
    gestor.insertaArista("CORCOVADO", "ISLA_DEL_CANO", 60);
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

