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
    if (esVacio()) {
        return -1;
    }
    return raiz->altura();
}

template <class T>
int ArbolAVL<T>::tamano() {
    if(raiz!=nullptr){
        return raiz->tam();
    }
    return -1;
}



template <class T>
bool ArbolAVL<T>::insertar(T valorDato) {
    bool insertado = false;
    raiz = insertarNodo(raiz, valorDato, insertado);
    balancearArbol();  // Balancear después de la inserción
    return insertado;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::insertarNodo(NodoAVL<T>* nodo, T valorDato, bool& insertado) {
    if (nodo == nullptr) {
        NodoAVL<T>* nuevoNodo = new NodoAVL<T>();
        nuevoNodo->setDato(valorDato);
        insertado = true;
        return nuevoNodo;
    }

    if (valorDato < nodo->getDato()) {
        nodo->setHijoIzq(insertarNodo(nodo->getHijoIzq(), valorDato, insertado));
    } else if (valorDato > nodo->getDato()) {
        nodo->setHijoDer(insertarNodo(nodo->getHijoDer(), valorDato, insertado));
    } else {
        insertado = false;  // Valor duplicado
        return nodo;
    }

    return nodo->balancearNodo();
}





template <class T>
bool ArbolAVL<T>::eliminar(T valorDato) {
    NodoAVL<T>* nodo = raiz;
    NodoAVL<T>* nodoPadre = nullptr;

    // Busca el nodo a eliminar
    while (nodo != nullptr && nodo->getDato() != valorDato) {
        nodoPadre = nodo;
        if (valorDato < nodo->getDato()) {
            nodo = nodo->getHijoIzq();
        } else {
            nodo = nodo->getHijoDer();
        }
    }

    // Nodo no encontrado
    if (nodo == nullptr) {
        return false;
    }

    // Caso 1: Nodo hoja
    if (nodo->esHoja()) {
        if (nodo == raiz) {
            delete raiz;
            raiz = nullptr;
        } else if (nodo == nodoPadre->getHijoIzq()) {
            nodoPadre->setHijoIzq(nullptr);
        } else {
            nodoPadre->setHijoDer(nullptr);
        }
        delete nodo;
    }
    // Caso 2: Nodo con un solo hijo
    else if (nodo->getHijoIzq() == nullptr || nodo->getHijoDer() == nullptr) {
        NodoAVL<T>* hijo = (nodo->getHijoIzq() != nullptr) ? nodo->getHijoIzq() : nodo->getHijoDer();
    
        if (nodo == raiz) {
            raiz = hijo; // Si se está eliminando la raíz
        } else if (nodoPadre->getHijoIzq() == nodo) {
            nodoPadre->setHijoIzq(hijo);
        } else {
            nodoPadre->setHijoDer(hijo);
        }
        delete nodo; 
    }
    // Caso 3: Nodo con dos hijos
    else {
        NodoAVL<T>* sucesor = nodo->getHijoDer();
        NodoAVL<T>* padreSucesor = nodo;

        while (sucesor->getHijoIzq() != nullptr) {
            padreSucesor = sucesor;
            sucesor = sucesor->getHijoIzq();
        }

        nodo->setDato(sucesor->getDato()); // Reemplaza el dato del nodo a eliminar

        // Eliminar el sucesor
        if (padreSucesor->getHijoIzq() == sucesor) {
            padreSucesor->setHijoIzq(sucesor->getHijoDer());
        } else {
            padreSucesor->setHijoDer(sucesor->getHijoDer());
        }
        delete sucesor;
    }

    // Balancear el árbol desde el nodo padre
    if (nodoPadre != nullptr) {
        nodoPadre->balancearNodo();
    }
    balancearArbol();
    return true;
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
    if(raiz!=nullptr){
        raiz->posOrden();
    }
}

template <class T>
void ArbolAVL<T>::inOrden() {
    // Hijo izquierdo, luego padre, luego hijo derecho
    if(raiz!=nullptr){
        raiz->inOrden();
    }
}

template <class T>
void ArbolAVL<T>::nivelOrden() {
    // Por niveles, de izquierda a derecha
    if(raiz!=nullptr){
        raiz->nivelOrden(); 
    }
    
}

//Metodos de balanceo
template <class T>
void ArbolAVL<T>::balancearArbol() {
    if (raiz != nullptr) {
        raiz->balancearNodo();
    }
}
