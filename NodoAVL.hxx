#include "NodoAVL.h"

#include <iostream>
#include <queue>

template <class T>
NodoAVL<T>::NodoAVL() : hijoIzq(nullptr), hijoDer(nullptr) {}

template <class T>
NodoAVL<T>::~NodoAVL() {
    if (hijoDer != nullptr) {
        hijoDer = nullptr;
        delete hijoDer;
    }
    if (hijoIzq != nullptr) {
        hijoIzq = nullptr;
        delete hijoIzq;
    }
}

template <class T>
T& NodoAVL<T>::getDato() {
    return dato; 
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getHijoIzq() const {
    return hijoIzq; 
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getHijoDer() const {
    return hijoDer; 
}

template <class T>
bool NodoAVL<T>::esHoja() {
    return hijoIzq == nullptr && hijoDer == nullptr; // Retorna true si es hoja
}

template <class T>
void NodoAVL<T>::setDato(T& datoNuevo) {
    this->dato = datoNuevo;
}

template <class T>
int NodoAVL<T>::altura() {
    if (esHoja()) {
        return 0;
    }
    int altura;
    int alturaHijoIzq = -1, alturaHijoDer = -1;
    if (getHijoIzq() != nullptr) {
        alturaHijoIzq = getHijoIzq()->altura(); // Llama recursivamente a los hijos izquierdos
    }
    if (getHijoDer() != nullptr) {
        alturaHijoDer = getHijoDer()->altura(); // Llama recursivamente a los hijos derechos
    }

    if (alturaHijoDer >= alturaHijoIzq) {
        altura = alturaHijoDer + 1;
    } else {
        altura = alturaHijoIzq + 1;
    }
    return altura;
}

template <class T>
void NodoAVL<T>::setHijoIzq(NodoAVL<T>* izq) {
    hijoIzq = izq;
}

template <class T>
void NodoAVL<T>::setHijoDer(NodoAVL<T>* der) {
    hijoDer = der;
}

template <class T>
void NodoAVL<T>::preOrden() {
    // Primero el padre, luego hijo izquierdo y luego hijo derecho
    std::cout << this->getDato() << "  ";
    if (this->getHijoIzq() != nullptr) {
        hijoIzq->preOrden();
    }
    if (hijoDer != nullptr) {
        hijoDer->preOrden();
    }
}

template <class T>
void NodoAVL<T>::posOrden() {
    // Primero hijos, luego padre
    if (this->getHijoIzq() != nullptr) {
        hijoIzq->posOrden();
    }
    if (this->getHijoDer() != nullptr) {
        hijoDer->posOrden();
    }
    std::cout << this->getDato() << "  ";
}

template <class T>
void NodoAVL<T>::inOrden() {
    // Hijo izquierdo, luego padre, luego hijo derecho
    if (this->getHijoIzq() != nullptr) {
        hijoIzq->inOrden();
    }
    std::cout << this->getDato() << "  ";
    if (this->getHijoDer() != nullptr) {
        hijoDer->inOrden();
    }
}

template <class T>
void NodoAVL<T>::nivelOrden() {
    // Por niveles, de izquierda a derecha
    std::queue<NodoAVL<T>*> cola;
    cola.push(this); // Se añade la raiz a la cola

    while (!cola.empty()) {
        NodoAVL<T>* nodoActual = cola.front();
        cola.pop();
        std::cout << nodoActual->getDato() << "  ";
        if (nodoActual->getHijoIzq() != nullptr) {
            cola.push(nodoActual->getHijoIzq());
        }
        if (nodoActual->getHijoDer() != nullptr) {
            cola.push(nodoActual->getHijoDer());
        }
    }
}

template <class T>
int NodoAVL<T>::tam() {
    int tamActual = 1;
    if (this->getHijoDer() != nullptr) {
        tamActual += getHijoDer()->tam();
    }
    if (this->getHijoIzq() != nullptr) {
        tamActual += getHijoIzq()->tam();
    }
    return tamActual;
}

//Metodos de balanceo
template <class T>
int NodoAVL<T>::factorBalance() {
    //Devuelve el factor balance del nodo actual
    int alturaIzq = getHijoIzq() ? getHijoIzq()->altura() : -1;
    int alturaDer = getHijoDer() ? getHijoDer()->altura() : -1;
    return alturaIzq - alturaDer;
}


template <class T>
NodoAVL<T>* NodoAVL<T>::balancearNodo() {
    int factorBalance = this->factorBalance();

    // Si el balance es mayor que 1, el subárbol izquierdo está desbalanceado
    if (factorBalance > 1) {
        if (this->getHijoIzq()->factorBalance() >= 0) {
            // Rotación simple a la derecha
            return this->rotacionDerecha();
        } else {
            // Rotación doble: primero rotación izquierda en el hijo izquierdo, luego derecha
            this->setHijoIzq(this->getHijoIzq()->rotacionIzquierda());
            return this->rotacionDerecha();
        }
    }
    // Si el balance es menor que -1, el subárbol derecho está desbalanceado
    else if (factorBalance < -1) {
        if (this->getHijoDer()->factorBalance() <= 0) {
            // Rotación simple a la izquierda
            return this->rotacionIzquierda();
        } else {
            // Rotación doble: primero rotación derecha en el hijo derecho, luego izquierda
            this->setHijoDer(this->getHijoDer()->rotacionDerecha());
            return this->rotacionIzquierda();
        }
    }

    // Si el nodo está balanceado, devolver el nodo sin cambios
    return this;
}



//Rotaciones
template <class T>
NodoAVL<T>* NodoAVL<T>:: rotacionDerecha() {
    NodoAVL<T>* nuevoNodo = this->getHijoIzq();
    this->setHijoIzq(nuevoNodo->getHijoDer());
    nuevoNodo->setHijoDer(this);
    return nuevoNodo;
}

template <class T>
NodoAVL<T>* NodoAVL<T>:: rotacionIzquierda() {
    NodoAVL<T>* nuevoNodo = this->getHijoDer();  
    this->setHijoDer(nuevoNodo->getHijoIzq());
    nuevoNodo->setHijoIzq(this);
    return nuevoNodo;
}

template <class T>
NodoAVL<T>* NodoAVL<T>:: rotacionIzquierdaDerecha() {
    this->setHijoIzq(rotacionIzquierda(this->getHijoIzq()));
    return rotacionDerecha(this);
}

template <class T>
NodoAVL<T>* NodoAVL<T>:: rotacionDerechaIzquierda() {
    this->setHijoDer(rotacionDerecha(this->getHijoDer()));
    return rotacionIzquierda(this);
}