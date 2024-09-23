#include "ArbolAVL.h"

#include <iostream>
template <class T>
ArbolAVL<T>::ArbolAVL() {
    raiz = nullptr;
}

template <class T>
ArbolAVL<T>::~ArbolAVL() {
    if(raiz!=nullptr){
        delete raiz;
        raiz=nullptr;
    }
}

template <class T>
bool ArbolAVL<T>::esVacio() {
    return raiz == nullptr;
}

template <class T>
T ArbolAVL<T>::datoRaiz() {
    if(raiz!=nullptr){
        return raiz->getDato();
    }
    return -1;
}

template <class T>
int ArbolAVL<T>::altura() {
    if(esVacio()){
        return -1;
    }
    if(raiz->esHoja()){
        return 0;
    }
    return raiz->altura();
}

template <class T>
int ArbolAVL<T>::tamano() {
    return raiz->tam();
}

template <class T>
bool ArbolAVL<T>::insertar(T valorDato) {
    return false //Sin implementar
}

template <class T>
bool ArbolAVL<T>::eliminar(T valorDato) {
    return false //sin implementar
}

template <class T>
bool ArbolAVL<T>::buscar(T valorDato) {
    if(raiz!=nullptr){
        NodoAVL<T>* nodo= raiz;
        while(nodo!=nullptr){
            if(valorDato > nodo->getDato()){
                nodo = nodo->getHijoDer();
            } else if(valorDato < nodo->getDato()){
                nodo = nodo->getHijoIzq();
            } else {
                return true;
            }
        }
    }
    return false;
}

template <class T>
void ArbolAVL<T>::preOrden() {
    // Primero el padre, luego hijo izquierdo y luego hijo derecho
    if(raiz!=nullptr){
        raiz->preOrden();
    }
}

template <class T>
void ArbolAVL<T>::posOrden() {
    // Primero hijos, luego padre
    raiz->posOrden();
}

template <class T>
void ArbolAVL<T>::inOrden() {
    // Hijo izquierdo, luego padre, luego hijo derecho
    raiz->inOrden();
}

template <class T>
void ArbolAVL<T>::nivelOrden() {
    // Por niveles, de izquierda a derecha
    raiz->nivelOrden();
}
