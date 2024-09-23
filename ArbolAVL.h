#ifndef _ARBOL_AVL_H
#define _ARBOL_AVL_H

#include "NodoAVL.h"

template<class T>
class ArbolAVL {
protected:
    NodoAVL<T>* raiz; 
public:
    ArbolAVL();
    ~ArbolAVL(); 
    bool esVacio(); 
    T datoRaiz(); 
    int altura();
    int tamano();
    bool insertar(T valorDato);
    bool eliminar(T valorDato); 
    bool buscar(T valorDato); 
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolAVL.hxx"
#endif