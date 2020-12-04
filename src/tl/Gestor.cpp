//
// Created by Mario Martinez on 03/12/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    grafo = new Grafo();
    tablaHash = new TablaHash();
}

Grafo *Gestor::getGrafo() const {
    return grafo;
}

void Gestor::setGrafo(Grafo *grafo) {
    Gestor::grafo = grafo;
}

void Gestor::insertVertice(string nombre) {
    getGrafo()->insertVertice(Validar::stringASCII(nombre), nombre);
}

string Gestor::insertaArista(string salida, string llegada, float peso) {
    return getGrafo()->insertaArista(salida, llegada, peso);
}

string Gestor::listaAdyacencia() {
    return getGrafo()->listaSucesores();
}


string Gestor::listaAdyacenciaXVertice(string vertice) {
    return getGrafo()->listaSucesoresXVertice(Validar::stringASCII(vertice));
}

string Gestor::listaPredecesores() {
    return getGrafo()->listaPredecesores();
}

string Gestor::listaPredecesoresXVertice(string vertice) {
    return getGrafo()->listaPredecesoresXVertice(Validar::stringASCII(vertice));
}


string Gestor::eliminarArista(string salida, string llegada) {
    return getGrafo()->eliminarArista(salida, llegada);
}

void Gestor::eliminarGrafo() {
    getGrafo()->elminarGrafo();
}

int Gestor::numVertices() {
    return getGrafo()->numVertices();
}

bool Gestor::vacio() const {
    return getGrafo()->esListaVacia();
}

string Gestor::eliminarVertice(string vertice) {
    return getGrafo()->eliminarVertice(vertice);
}

string Gestor::recorridoAnchura(string pOrigen) {
    return getGrafo()->recorridoAnchura(pOrigen);
}

string Gestor::recorridoProfundidad(string pOrigen) {
    return getGrafo()->recorridoProfundidad(pOrigen);
}

string Gestor::primeroAnchura(string pOrigen, string pDestino) {
    return getGrafo()->primeroAnchura(pOrigen, pDestino);
}

string Gestor::primeroProfundidad(string pOrigen, string pDestino) {
    return getGrafo()->primeroProfundidad(pOrigen, pDestino);
}

string Gestor::dijkstra(string pOrigen, string pDestino) {
    return getGrafo()->dijkstra(pOrigen, pDestino);
}

void Gestor::addUbicaciones(string ubic) {
    int num = Validar::stringASCII(ubic);
    tablaHash->addUbicacion(Validar::hashing(num, TablaHash::MAX),
                            new Ubicacion(num, ubic));
}

string Gestor::optenerUbicacion(string ubic) {
    string res;
    int num = Validar::stringASCII(ubic);
    Ubicacion * aux = tablaHash->getUbicacion(Validar::hashing(num, TablaHash::MAX),num);
    if (aux != nullptr){
        res = "Los datos de la ubación " + aux->getNombre() + "\n";
    } else {
        res = "No existe ninguna ciudad con el nombre ingresado\n";
    }
    return res;
}
