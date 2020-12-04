//
// Created by Mario Martinez on 03/12/20.
//

#ifndef MAPA_VERTICE_H
#define MAPA_VERTICE_H

#include <string>
//class Arista;

#include "Arista.h"


using namespace std;

class Vertice {
public:

    Vertice(int indice, const string &nombre, Vertice *next = nullptr,
            Arista *ady = nullptr, Arista *precedente = nullptr);

    virtual ~Vertice();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Vertice *getNext() const;

    void setNext(Vertice *next);

    Arista *getAdy() const;

    void setAdy(Arista *ady);

    int getIndice() const;

    void setIndice(int indice);

    Arista *getPrecedente() const;

    void setPrecedente(Arista *precedente);

private:
    int indice; // para ordenar lo vértices en forma ascendente
    string nombre;
    Vertice *next;
    Arista *ady;
    Arista *precedente;
};


#endif //MAPA_VERTICE_H
