//
// Created by Mario Martinez on 03/12/20.
//

#ifndef MAPA_UBICACION_H
#define MAPA_UBICACION_H
#include <iostream>
using namespace std;

class Ubicacion {
public:
    Ubicacion(long num, const string &nombre, Ubicacion *next = nullptr);

    virtual ~Ubicacion();

    long getNum() const;

    void setNum(long num);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Ubicacion *getNext() const;

    void setNext(Ubicacion *next);

private:
    long num;
    string nombre;
    Ubicacion * next;
};


#endif //MAPA_UBICACION_H
