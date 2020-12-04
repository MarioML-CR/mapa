//
// Created by Mario Martinez on 03/12/20.
//

#include "Arista.h"
Arista::Arista(int peso, const string &nombre, Vertice *ady, Arista *sig, Vertice *prev, Arista *ant) :
        peso(peso), nombre(nombre), ady(ady), sig(sig), prev(prev), ant(ant) {
    setPeso(peso);
    setNombre(nombre);
    setAdy(ady);
}

Arista::~Arista() {

}

int Arista::getPeso() const {
    return peso;
}

void Arista::setPeso(int peso) {
    Arista::peso = peso;
}

const string &Arista::getNombre() const {
    return nombre;
}

void Arista::setNombre(const string &nombre) {
    Arista::nombre = nombre;
}

Arista *Arista::getSig() const {
    return sig;
}

void Arista::setSig(Arista *sig) {
    Arista::sig = sig;
}

Vertice *Arista::getAdy() const {
    return ady;
}

void Arista::setAdy(Vertice *ady) {
    Arista::ady = ady;
}

Vertice *Arista::getPrev() const {
    return prev;
}

void Arista::setPrev(Vertice *prev) {
    Arista::prev = prev;
}

Arista *Arista::getAnt() const {
    return ant;
}

void Arista::setAnt(Arista *ant) {
    Arista::ant = ant;
}