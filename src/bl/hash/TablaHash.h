//
// Created by Mario Martinez on 03/12/20.
//

#ifndef MAPA_TABLAHASH_H
#define MAPA_TABLAHASH_H


#include "Ubicacion.h"

class TablaHash {
public:
    TablaHash();

    virtual ~TablaHash();

    void addUbicacion(int indice, Ubicacion * ptr);

    Ubicacion * getUbicacion(int indice, long num);

    enum {MAX = 15};
private:
    Ubicacion *vectorUbic[MAX];
};


#endif //MAPA_TABLAHASH_H
