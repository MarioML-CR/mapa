//
// Created by Mario Martinez on 03/12/20.
//

#include "Grafo.h"

Grafo::Grafo(Vertice *head, Vertice *tail, int tam) : head(head), tail(tail), tam(tam) {}

Grafo::~Grafo() {

}

Vertice *Grafo::getHead() const {
    return head;
}

void Grafo::setHead(Vertice *head) {
    Grafo::head = head;
}


Vertice *Grafo::getTail() const {
    return tail;
}

void Grafo::setTail(Vertice *tail) {
    Grafo::tail = tail;
}

int Grafo::getTam() const {
    return tam;
}

void Grafo::setTam(int tam) {
    Grafo::tam = tam;
}

bool Grafo::esListaVacia() const {
    return getHead() == nullptr;
}
/**
 * Método:              numVertices
 * Descripción:         Método que permite establecer el número de vértices del grafo
 * @return              variable de tipo int que representa el número de vértices del grafo
 */
int Grafo::numVertices() const {
    return getTam();
}
/**
 * Método:              getVertice
 * Descripción:         Método sobrecargado que permite obtener el nodo que contiene el nombre pasado
 * por parámetro
 * @param nombre        variable de tipo string que representa el nombre del nodo a buscar
 * @return              variable de tipo Vértice que contiene el nombre pasado por parámetro
 */
Vertice *Grafo::getVertice(string &nombre) {
    Vertice * aux = getHead();
    while (aux != nullptr){
        if (aux->getNombre().compare(nombre) == 0) {
            return aux;
        }
        aux = aux->getNext();
    }
    return aux;
}

/**
 * Método:              getVertice
 * Descripción:         Método sobrecargado que permite obtener el nodo que contiene el índice pasado
 * por parámetro
 * @param indice        variable de tipo int que representa el índice del nodo a buscar
 * @return              variable de tipo Vértice que contiene el nombre pasado por parámetro
 */
Vertice *Grafo::getVertice(int indice) {
    Vertice * aux = getHead();
    while (aux != nullptr) {
        if (aux->getIndice() == indice){
            return aux;
        }
        aux = aux->getNext();
    }
    return aux;
}

/**
 * Método:              insertVertice
 * Descripción:         Método que permite insertar un vértice de forma ordenada
 * @param indice        variable de tipo int que representa el índice del vértice
 * @param nombre        varibale de tipo string que representa el nombre del vértice a insertar
 */
void Grafo::insertVertice(int indice, string &nombre) {
    if(esListaVacia()){
        setHead(new Vertice(indice, nombre));
        setTail(getHead());
        setTam(getTam() + 1);
    } else {
        if (getHead()->getIndice() >= indice) {
            insertarAlIincio(indice, nombre);
        } else if(getTail()->getIndice() <= indice) { // insertar al final
            insertarAlFinal(indice, nombre);
        } else {
            Vertice *aux = getHead();
            do {
                if (aux->getIndice() <= indice && aux->getNext()->getIndice() >= indice){
                    Vertice *nuevo = new Vertice(indice, nombre);
                    nuevo->setNext(aux->getNext());
                    aux->setNext(nuevo);
                    setTam(getTam() + 1);
                    break;
                }
                aux =aux->getNext();
            } while (aux->getNext() != nullptr);
        }
    }
}
/**
 * Método:              insertarAlIincio
 * Descripción:         Método privado que permite insertar un vértice a la lista de vértices al inicio
 * @param indice
 * @param nombre
 */
void Grafo::insertarAlIincio(int indice, string &nombre) {
    Vertice *nuevo = new Vertice(indice, nombre);
    nuevo->setNext(getHead());
    setHead(nuevo);
    setTam(getTam() + 1);
}
/**
 * Método:              insertarAlFinal
 * Descripción:         Método privado que permite insertar un vértice a la lista de vértices al final
 * @param indice
 * @param nombre
 */
void Grafo::insertarAlFinal(int indice, string &nombre) {
    Vertice *nuevo = new Vertice(indice, nombre);
    getTail()->setNext(nuevo);
    setTail(nuevo);
    setTam(getTam() + 1);
}


/**
 * Método:              insertaArista
 * Descripción:         Método que permite insertar una arista o arco entre dos vértices
 * @param salida        variable de tipo vértice que representa el vértice de salida
 * @param llegada       variable de tipo vértice que representa el vértice de llegada
 * @param peso          variable de tipo int que representa el peso del arco
 */
string Grafo::insertaArista(string &salida, string &llegada, float peso) {
    string res = "";
    Vertice *origen = getVertice(salida);
    Vertice *destino = getVertice(llegada);
    if (origen != nullptr && destino != nullptr){
        // Aristas adyacentes
        Arista *nueva = new  Arista(peso, llegada,destino);
        Arista *aux = origen->getAdy();
        Vertice *anterior = origen;
        if (aux == nullptr){
            origen->setAdy(nueva);
            origen->getAdy()->setPrev(origen);
            nueva->setAdy(destino);
        } else {
            /** recorre las aristas hasta llegar a la última para insertar la nueva arista y
             * conectarla con el vértice destino.
             */
            while (aux->getSig() != nullptr){
                aux = aux->getSig();
            }
            aux->setSig(nueva);
            nueva->setPrev(origen);
            nueva->setAdy(destino);
        }
//         Aristas adyacentes
        Arista *nuevo = new Arista(peso, salida, origen);
        Arista * aux2 = destino->getPrecedente();
        if (aux2 == nullptr){
            destino->setPrecedente(nuevo);
            nuevo->setPrev(origen);
        } else {
            while (aux2->getAnt() != nullptr){
                aux2 = aux2->getAnt();
            }
            aux2->setAnt(nuevo);
            nuevo->setPrev(origen);
        }
        res = "La arista se creo satisfactoriamente\n";
    } else {
        res = "Uno de los vértices no existe\n";
    }
    return res;
}

/**
 * Método:              listaSucesores
 * Descripción:         Método que permite imprimir la lista de adyacencia o sucesores
 * @return              variable de tipo string que representa la lista de sucesores.
 */
string Grafo::listaSucesores() {
    string lista = "";
    int i;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        lista = "Lista de vértices y adyacencias:\n";
        Vertice *vertAux = getHead();
        Arista * arisAux;
        while (vertAux != nullptr){
            lista += vertAux->getNombre() + ": ";
            arisAux = vertAux->getAdy();
            i = 0;
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getAdy()->getNombre();
                } else {
                    lista += ", " + arisAux->getAdy()->getNombre();
                }
                i += 1;
                arisAux = arisAux->getSig();
            }
            vertAux = vertAux->getNext();
            lista += "\n";
        }
    }
    return lista;
}

/**
 * Método:              listaSucesoresXVertice
 * Descripción:         Método que permite imprimir la lista de adyacencia de un vértice específico
 * @param indice        variable de tipo int que representa el índice del vértice
 * @return              variable de tipo string que representa la lista de adyacencia.
 */
string Grafo::listaSucesoresXVertice(int indice) {
    string lista = "";
    int i = 0;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        Vertice *vertAux = getHead();
        Arista * arisAux = nullptr;
        while (vertAux != nullptr && vertAux->getIndice() <= indice){
            if (vertAux->getIndice() == indice){
                arisAux = vertAux->getAdy();
                if (arisAux == nullptr){
                    lista = "El vértice " + vertAux->getNombre() + " no tiene adyacencias\n";
                } else {
                    lista = "Lista de adyacencias del vértice " + vertAux->getNombre() + ": ";
                }
                break;
            }
            vertAux = vertAux->getNext();
        }
        if (arisAux != nullptr){
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getAdy()->getNombre();
                } else {
                    lista += ", " + arisAux->getAdy()->getNombre();
                }
                arisAux = arisAux->getSig();
                i += 1;
            }
        } else {
            lista = "El vértice ingresado no existe\n";
        }
    }
    return lista;
}
/**
 * Método:              listaPredecesores
 * Descripción:         Método que permite imprimir la lista de sucesores
 * @return              variable de tipo string que representa la lista de adyacencia.
 */
string Grafo::listaPredecesores() {
    string lista = "";
    int i;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        lista = "Lista de vértices y predecesores:\n";
        Vertice *vertAux = getHead();
        Arista * arisAux;
        while (vertAux != nullptr){
            lista += vertAux->getNombre() + ": ";
            arisAux = vertAux->getPrecedente();
            i = 0;
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getPrev()->getNombre();
                } else {
                    lista += ", " + arisAux->getPrev()->getNombre();
                }
                i += 1;
                arisAux = arisAux->getAnt();
            }
            vertAux = vertAux->getNext();
            lista += "\n";
        }
    }
    return lista;
}
/**
 * Método:              listaPredecesoresXVertice
 * Descripción:         Método que permite imprimir la lista de predecesores de un vértice específico
 * @param indice        variable de tipo int que representa el índice del vértice
 * @return              variable de tipo string que representa la lista de predecesores.
 */
string Grafo::listaPredecesoresXVertice(int indice) {
    string lista = "";
    int i = 0;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        Vertice *vertAux = getHead();
        Arista * arisAux = nullptr;
        while (vertAux != nullptr && vertAux->getIndice() <= indice){
            if (vertAux->getIndice() == indice){
                arisAux = vertAux->getPrecedente();
                if (arisAux == nullptr){
                    lista = "El vértice " + vertAux->getNombre() + " no tiene predecesores\n";
                } else {
                    lista = "Lista de predecesores del vértice " + vertAux->getNombre() + ": ";
                }
                break;
            }
            vertAux = vertAux->getNext();
        }
        if (arisAux != nullptr){
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getPrev()->getNombre();
                } else {
                    lista += ", " + arisAux->getPrev()->getNombre();
                }
                i += 1;
                arisAux = arisAux->getAnt();
            }
        } else {
            lista = "El vértice ingresado no existe\n";
        }
    }
    return lista;
}



/**
 * Método:              eliminarArista
 * Descripción:         Método público que permite eliminar un arco o arista entre dos vértices,
 * este método recibe dos parametros de tipo string
 * @param salida        variable de tipo string que representa el vértice de salida
 * @param llegada       variable de tipo string que representa el vértice de llegada
 */
string Grafo::eliminarArista(string &salida, string &llegada) {
    Vertice *origen = getVertice(salida);
    Vertice *destino = getVertice(llegada);
    return eliminarArista(origen, destino);
}
/**
 * Método:              eliminarArista
 * Descripción:         Método privado que permite eliminar un arco o arista entre dos vértices,
 * este método recibe dos parámetros de tipo Vertice
 * @param salida        variable de tipo vértice que representa el vértice de salida
 * @param llegada       variable de tipo vértice que representa el vértice de llegada
 */
string Grafo::eliminarArista(Vertice * origen, Vertice * destino) {
    string res = "";
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen\n";
    } else {
        int band = 0;
        Arista *actual, *anterior;
        actual = origen->getAdy();
        if (actual == nullptr){ // no existe arista
            res = "El vértice origen no tiene aristas\n";
        } else if(actual->getAdy() == destino){ // la primera arista
            origen->setAdy(actual->getSig());
            delete actual;
            res = "El vértice entre " + origen->getNombre() + " y " + destino->getNombre() + " fue eliminado\n";
        } else { // cualquier otra arista
            while (actual->getAdy() != nullptr){
                if (actual->getAdy() == destino){
                    band = 1;
                    anterior->setSig(actual->getSig());
                    delete actual;
                    res = "El vértice entre " + origen->getNombre() + " y " + destino->getNombre() + " fue eliminado\n";
                    break;
                }
                anterior = actual;
                actual = actual->getSig();
            }
            if (band == 0){
                res = "Esos dos vértices no están conectados\n";
            }

        }
    }
    return res;
}
/**
 * Método:              elminarGrafo
 * Descripción:         Método que permite eliminar el grafo
 */
void Grafo::elminarGrafo() {
    Vertice *aux;
    while (getHead() != nullptr){
        aux = getHead();
        setHead(getHead()->getNext());
        aux = nullptr;
        delete aux;
    }
    setTail(nullptr);
    setTam(0);
}
/**
 * Método:              eliminarVertice
 * Descripción:         Método público que permite eliminar un vértice
 * @param pEliminar     variable de tipo string que representa el nombre del vértice
 * @return              variable de tipo bool, true si se eliminó, false y no existe
 */
string Grafo::eliminarVertice(string &pEliminar) {
    Vertice *vert = getVertice(pEliminar);
    return eliminarVertice(vert);
}
/**
 * Método:              eliminarVertice
 * Descripción:         Método privado que permite eliminar un vértice
 * @param vert          variable de tipo vértice que representa el vértice a eliminar
 * @return              variable de tipo bool, true si se eliminó, false y no existe
 */
string Grafo::eliminarVertice(Vertice *vert) {
    string res = "";
    if (vert == nullptr){
        res = "El vértice ingresado no existe\n";
    } else {
        Vertice *actual, *anterior;
        Arista *aux;
        actual = getHead();
        while (actual != nullptr){ // se eliminan las aristas que tenga
            aux = actual->getAdy();
            while (aux != nullptr){
                if (aux->getAdy() == vert){
                    eliminarArista(actual, aux->getAdy());
                    break;
                }
                aux = aux->getSig();
            }
            actual = actual->getNext();
        }
        actual = getHead();
        if (getHead() == vert){
            setHead(getHead()->getNext());
            delete actual;
        } else {
            while (actual != vert){
                anterior = actual;
                actual = actual->getNext();
            }
            anterior->setNext(actual->getNext());
            delete actual;
        }
        res = "El vértice fue eliminado\n";
    }
    return res;
}
/**
 * Método:              recorridoAnchura
 * Descripción:         Método público que permite hacer un recorrido por anchura del grafo
 * @param pOrigen       variable de tipo string que representa el nombre de vértice de origen
 */
string Grafo::recorridoAnchura(string &pOrigen) {
    Vertice *origen = getVertice(pOrigen);
    return recorridoAnchura(origen);
}
/**
 * Método:              recorridoAnchura
 * Descripción:         Método privado que permite hacer un recorrido por anchura del grafo
 * @param origen        variable de tipo vértice que representa el nombre de vértice de origen
 */
string Grafo::recorridoAnchura(Vertice *origen) {
    string res = "";
    if (origen == nullptr){
        res = "No exite el vértice";
    } else {
        int band, band2;
        stack<string> pilaRes; // pila que contiene las respuestas.
        Vertice *actual;
        queue<Vertice*> cola;
        list<Vertice*> lista;
        list<Vertice*>::iterator i;
        cola.push(origen); // se coloca el vértice origen en una cola (el que pasan como parámetro
        while (!cola.empty()){ // mientras la cola no esté vacía
            band = 0;
            actual = cola.front();
            cola.pop(); // desencolamos un vértice, será el vértice actual
            for (i = lista.begin(); i != lista.end(); i++) {
                if (*i == actual){
                    band = 1;
                }
            }
            if (band == 0) { // si el vértice actual no ha sido visitado
                res += actual->getNombre() + ", "; // procesar el vértice actual
                lista.push_back(actual); // colocar el vértice en la lista de visitados
                Arista * aux = actual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++) { // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // encolar el vértice
                        cola.push(aux->getAdy());
                    }
                    aux = aux->getSig();
                }
            }
        }
    }
    return res + "\n";
}
/**
 * Método:              recorridoProfundidad
 * Descripción:         Método público que permite hacer un recorrido en profundidad del grafo
 * recibiendo como parámetro el nombre del vértice de origen
 * @param pOrigen       variable de tipo string que representa el nombre del vértice de origen
 */
string Grafo::recorridoProfundidad(string &pOrigen) {
    Vertice *origen = getVertice(pOrigen);
    return recorridoProfundidad(origen);
}
/**
 * Método:              recorridoProfundidad
 * Descripción:         Método privado que permite hacer un recorrido en profundidad del grafo
 * recibiendo como parámetro el vértice de origen
 * @param origen        variable de tipo vértice que representa el nombre del vértice de origen
 */
string Grafo::recorridoProfundidad(Vertice *origen) {
    string res = "";
    if (origen == nullptr){
        res = "No exite el vértice";
    } else {
        int band, band2;
        Vertice *actual;
        stack<Vertice*> pila;
        list<Vertice*> lista;
        list<Vertice*>::iterator i; // iterador para la lista
        pila.push(origen); // se coloca el vértice origen en una pila
        while (!pila.empty()){ // mientras la pila no esté vacía:
            band = 0;
            actual = pila.top();
            pila.pop(); // desepilar el vértice, será el vértice actual
            for (i = lista.begin(); i != lista.end(); i++) { // si el vertice actual no ha sido visitado o está en la lista
                if (*i == actual){
                    band = 1;
                }
            }
            if (band == 0){ // si el vertice actual no ha sido visitado:
                res += actual->getNombre() + ", "; // se "procesa" el vértice actual
                lista.push_back(actual); // se coloca el vértice actual en la lista de visitados
                Arista *aux = actual->getAdy(); // se va a ubicar en la primera arista del vértice actual
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++) {
                        if (*i == aux->getAdy()) {
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado.
                        pila.push(aux->getAdy()); // apilar el vértice
                    }
                    aux = aux->getSig();
                }
            }
        }
    }
    return res + "\n";
}
/**
 * Método:              primeroAnchura
 * Descripción:         Método público que permite hacer un recorrido en anchura del grafo
 * recibiendo como parámetros dos string del nombre de los vértices de origen y destino
 * @param pOrigen       variable de tipo string que representa el nombre del vértice de origen
 * @param pDestino      variable de tipo string que representa el nombre del vértice de destino
 */
string Grafo::primeroAnchura(string &pOrigen, string &pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    return primeroAnchura(origen, destino);
}
/**
 * Método:              primeroAnchura
 * Descripción:         Método provado que permite hacer un recorrido en anchura del grafo
 * recibiendo como parámetros dos variable de tipo vértice que representan los vértices de origen y destino
 * @param origen        variable de tipo vértice que representa el vértice de origen
 * @param destino       variable de tipo vértice que representa el vértice de destino
 */
string Grafo::primeroAnchura(Vertice *origen, Vertice *destino) {
    string res = "";
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen";
    } else {
        int band, band2, band3 = 0, k = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, Vertice*> VerticeVertice; // pila de parejas de vértices
        queue<Vertice*> cola;
        stack<VerticeVertice> pila; // inicializar una pila que almacene parejas de datos origen-destino
        stack<string> pilaRes; // pila que contiene las respuestas.
        list<Vertice*> lista;
        list<Vertice*>::iterator i;
        cola.push(origen); // colocar el vértice origen en una cola
        while (!cola.empty()){ // mientras la cola no esté vacía
            band = 0;
            verticeActual = cola.front();
            cola.pop(); // desencolar un vértice, será el vértice actual
            for (i = lista.begin(); i != lista.end(); i++) {
                if (verticeActual == *i) {
                    band =1;
                }
            }
            if (band == 0){ //si el vértice actual no ha sido visitado:
                // mostrar la ruta encontrada
                if (verticeActual == destino){ // si el vértice actual es igual al vértice destino:
                    band3 = 1;
                    destinoActual = destino; // el vértice destino se convierte en destino actual
                    while (!pila.empty()){ // mientras la pila no esté vacía
//                        res += destinoActual->getNombre() + "<-"; // imprimir el destino actual; al revés porque en la pila se saca al revés
                        pilaRes.push(destinoActual->getNombre());
                        while (!pila.empty() && pila.top().second != destinoActual){ // mientras la pila no esté vacía y el vértice destino en el tope de la pila sea distinto del destino actual
                            pila.pop(); // desapilar
                        }
                        if (!pila.empty()){ // si la pila no está vacía
                            destinoActual = pila.top().first; // el vértice origen en el tope de la pila se convierte en el destino actual
                        }
                    }
//                    break;  // terminar
                }
                lista.push_back(verticeActual); // colocar el vértice actual en la lista de visitados
                aux = verticeActual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++){
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado
                        cola.push(aux->getAdy());
                        pila.push(VerticeVertice(verticeActual, aux->getAdy())); // apilar la pareja: vértice actual y vértice destino
                    }
                    aux = aux->getSig(); // encolar el vértice
                }
            }
        }
        if (band3 == 0){ // si la cola se vació sin encontrar el destino
            // no existe una ruta entre esos vértices
            res = "No hay ruta entre esos dos vértices";
        }
        while (!pilaRes.empty()){
            if (k > 0) {
                res += "->";
            }
            res += pilaRes.top();
            k += 1;
            pilaRes.pop();
        }
    }
    return res + "\n";
}
/**
 * Método:              primeroProfundidad
 * Descripción:         Método público que permite hacer un recorrido en profundidad
 * estableciendo la primera opción.
 * @param pOrigen       variable de tipo string que representa el nombre del vértice de origen
 * @param pDestino      variable de tipo string que representa el nombre del vértice de destino
 */
string Grafo::primeroProfundidad(string &pOrigen, string &pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    return primeroProfundidad(origen, destino);
}
/**
 * Método:              primeroProfundidad
 * Descripción:         Método privado que permite hacer un recorrido en profundidad
 * estableciendo la primera opción.
 * @param origen        variable de tipo vértice que representa el vértice de origen
 * @param destino       variable de tipo vértice que representa el vértice de destino
 */
string Grafo::primeroProfundidad(Vertice *origen, Vertice *destino) {
    string res = "";
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen";
    } else {
        int band, band2, band3 = 0, k = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, Vertice*> parVertices;
        stack<Vertice*> pila;
        list<Vertice*> lista;
        stack<string> pilaRes; // pila que contiene las respuestas.
        stack<parVertices> pilaPar; // inicializar una pila que almacene parejas de datos origen-destino
        list<Vertice*>::iterator i; // se declara un iterador para la lista
        pila.push(origen); // colocar el vértice origen en una pila
        while (!pila.empty()){ // mientras la pila no esté vacía
            band = 0;
            verticeActual = pila.top(); // almacenamos el tope de la fila
            pila.pop(); // desapilar un vértice, seá el vértice actual
            for (i = lista.begin(); i != lista.end(); i++){
                if (verticeActual == *i){
                    band = 1;
                }
            }
            if (band == 0){ // si el vértice actual no ha sido visitado (no encontró ese vértice en la lista de visitados
                if (verticeActual == destino){ // si el vértice actual es igual al vértice destino
                    band3 = 1;
                    // mostrar la ruta encontrada
                    destinoActual = destino; // el vértice destino se convierte en destino actual
                    while (!pilaPar.empty()){ // mientras la pila no esté vacía
//                        res += destinoActual->getNombre() + "<-"; // imprimir el destino actual
                        pilaRes.push(destinoActual->getNombre());
                        while (!pilaPar.empty() && pilaPar.top().second != destinoActual){ // mientras la pila no esté vacía y el vértice destino en el tipo de la pila sea distinto del destino actual
                            pilaPar.pop(); // desapilar
                        }
                        if (!pilaPar.empty()){ // si la pila no está vacía
                            destinoActual = pilaPar.top().first; // el vértice origen en el tope de la pila se convierte en el destino actual
                        }
                    }
                    break; // terminar
                }
                lista.push_back(verticeActual); // colocar el vértice actual en la lista de visitados
                aux = verticeActual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++){
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado
                        pila.push(aux->getAdy()); // apilar el vértice
                        pilaPar.push(parVertices(verticeActual, aux->getAdy())); // apilar la pareja: vértice actual y vértice destino
                    }
                    aux = aux->getSig();
                }
            }
        }
        if (band3 == 0){ // si la pila se vacío sin encontrar el destino
            res = "No hay ruta entre esos dos vértices"; // no existe una ruta entre esos vértices.
        }
        while (!pilaRes.empty()){
            if (k > 0) {
                res += "->";
            }
            res += pilaRes.top();
            k += 1;
            pilaRes.pop();
        }
    }
    return res + "\n";
}
/**
 * Método:              dijkstra
 * Descripción:         Método público que permite generar la ruta de menor costo.
 * @param pOrigen       variable de tipo string que representa el nombre del vértice de origen
 * @param pDestino      variable de tipo string que representa el nombre del vértice de destino
 */
string Grafo::dijkstra(string &pOrigen, string &pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    return dijkstra(origen, destino);
}
/**
 * Método:              dijkstra
 * Descripción:         Método privado que permite generar la ruta de menor costo.
 * @param origen        variable de tipo vértice que representa el vértice de origen
 * @param destino       variable de tipo vértice que representa el vértice de destino
 */
string Grafo::dijkstra(Vertice *origen, Vertice *destino) {
    string res = "";
    int k = 0;
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen";
    } else {
        float costoActual = 0;
        int band, band2 = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, float> verticeCosto;
        typedef pair<Vertice*, Vertice*> verticeVertice;
        list<verticeCosto> listaCostos;
        list<verticeCosto> listaOrdenada;
        stack<verticeVertice> pila; // inicializar una pila que almacene parejas de datos origen-destino
        stack<string> pilaRes; // pila que contiene las respuestas.
        list<verticeCosto>::iterator i, j;
        listaCostos.emplace_back(origen, 0); // permite recibir solo dos argumentos, lo permite a partir de 11.
        listaOrdenada.emplace_back(origen,0);
//        listaCostos.push_back(verticeCosto(origen, 0)); // colocar el vértice origen en una lista "costos", asociar a este costo cero
//        listaOrdenada.push_back(verticeCosto(origen, 0)); // colocar el vértice origen en una lista ordenada (por costo), asociar a este un costo cero
        while (!listaOrdenada.empty()){ // mientras la lista ordenada no esté vacía
            verticeActual = listaOrdenada.front().first; // obtener el primer vértice de la lista ordenada, será el vértice actual.
            costoActual = listaOrdenada.front().second; // el costo asociado a ese vértice será el costo actual
            listaOrdenada.pop_front(); // eliminar el primer vértice de la lista
            if (verticeActual == destino){ // si el vértice actual es igual al vértice destino
                res = "Costo: " + to_string(costoActual);
                band2 = 1;
                // mostar la ruta encontrada y terminar
                destinoActual = destino; // el vértice destino se convierte en destino actual
                while (!pila.empty()){ // mientras la pila no esté vacía
//                    res += destinoActual->getNombre() + "<-"; // imprimir el destino actual
                    pilaRes.push(destinoActual->getNombre());
                    while (!pila.empty() && pila.top().second != destinoActual){ // mientras la pila no esté vacía y el vértice destino en el tope de la pila sea distinto del destino actual
                        pila.pop(); // desapilar
                    }
                    if (!pila.empty()){ // si la pila no está vacía
                        destinoActual = pila.top().first; // el vértice origen en el tope de la pila se convierte en el destino actual
                    }
                }
                break;
            }
            aux = verticeActual->getAdy();
            while (aux != nullptr){ // para cada vértice que el vértice actual tiene como destino
                band = 0;
                costoActual += aux->getPeso(); // calcular el costo del vértice destino, sumando su costo al costo actual
                for (i = listaCostos.begin(); i != listaCostos.end(); i++){
                    if (aux->getAdy() == i->first){
                        band = 1;
                        if (costoActual < i->second){ // de lo contrario: si el nuevo costo es menor al costo que tiene asociado el vértice en la lista de costos
                            (*i).second = costoActual; // actualizar el costo del vértice en la lista de costos con el nuevo costo
                            for (j = listaOrdenada.begin(); j != listaOrdenada.end(); j++){
                                if (j->first == aux->getAdy()){
                                    (*j).second = costoActual;
                                }
                            }
                            listaOrdenada.sort(comparacion);
                            pila.push(verticeVertice(verticeActual, aux->getAdy())); // se apila la paraja: vértice actual y vértice destino
                            costoActual -= aux->getPeso(); // actualizar el costo del vértice en la lista ordenada con el nuevo costo
                        }
                    }
                }
                if (band == 0){ // si el vértice no se encuentra en la lista de costos
                    listaCostos.emplace_back(aux->getAdy(), costoActual); // permite recibir solo dos argumentos, lo permite a partir de 11.
                    listaOrdenada.emplace_back(aux->getAdy(), costoActual);
//                    listaCostos.push_back(verticeCosto(aux->getAdy(), costoActual)); // insertar el vértice en la lista de costos, asociando el nuevo costo
//                    listaOrdenada.push_back(verticeCosto(aux->getAdy(), costoActual)); // insertar el vértice en la lista ordenada, asociando el nuevo costo
                    listaOrdenada.sort(comparacion);
                    pila.push(verticeVertice(verticeActual, aux->getAdy())); // se apila la pareja: vértice actual y vértice destino
                    costoActual -= aux->getPeso();
                }
                aux = aux->getSig();
            }
        }
        if (band2 == 0){ // si la lista ordenada se vació sin encontrar el destino: no existe una ruta entre esos vértice
            res = "No hay ruta entre esos dos vértices"; // no existe una ruta entre esos vértices.
        }
        res += "\n";
        while (!pilaRes.empty()){
            if (k > 0) {
                res += "->";
            }
            res += pilaRes.top();
            k += 1;
            pilaRes.pop();
        }
    }
    return res + "\n";
}


/**
 * Método:              comparacion
 * Descripción:         Método que permite comparar costos
 * @param a             variable de tipo pair<Vertice, int>
 * @param b             variable de tipo pair<Vertice, int>
 * @return              variable de tipo bool, true si a es menor a b, y false caso contrario
 */
bool Grafo::comparacion(pair<Vertice *, int> a, pair<Vertice *, int> b) {
    return a.second < b.second;
}
