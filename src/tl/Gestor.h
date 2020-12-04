//
// Created by Mario Martinez on 03/12/20.
//

#ifndef MAPA_GESTOR_H
#define MAPA_GESTOR_H

#include "../bl/grafo/Grafo.h"
#include "../ui/utilitario/Validar.h"
#include "../bl/hash/TablaHash.h"
//
//Validar val;

class Gestor {
public:
    Gestor();

    Grafo *getGrafo() const;

    void setGrafo(Grafo *grafo);

    void insertVertice(string nombre);

    string insertaArista(string salida, string llegada, int peso);

    string listaAdyacencia();

    string listaAdyacenciaXVertice(string vertice);

    string listaPredecesores();

    string listaPredecesoresXVertice(string vertice);

    string eliminarArista(string salida, string llegada);

    string eliminarVertice(string vertice);

    void eliminarGrafo();

    int numVertices();

    bool vacio() const;

    string recorridoAnchura(string pOrigen);

    string recorridoProfundidad(string pOrigen);

    string primeroAnchura(string pOrigen, string pDestino);

    string primeroProfundidad(string pOrigen, string pDestino);

    string dijkstra(string pOrigen, string pDestino);

    /*
     * Tabla Hash
     */
    void addUbicaciones(string ubic);

    string optenerUbicacion(string ubic);

private:
    Grafo *grafo;
    TablaHash *tablaHash;
};


#endif //MAPA_GESTOR_H
