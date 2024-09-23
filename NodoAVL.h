#ifndef _NODO_AVL_H_
#define _NODO_AVL_H_

#include <string>

template <class T>
class NodoAVL{
    protected:
        T dato;
        NodoAVL <T>* hijoIzq;
        NodoAVL <T>* hijoDer;
    
    public: 
        NodoAVL();
        ~NodoAVL();
        T& getDato();
        NodoAVL<T>* getHijoIzq() const;
        NodoAVL<T>* getHijoDer() const;
        bool esHoja();
        void setDato(T& datoNuevo);
        int altura();


        void setHijoIzq(NodoAVL<T>* izq);
        void setHijoDer(NodoAVL<T>* der);
                 
        
        void preOrden();
        void posOrden();
        void inOrden();
        void nivelOrden();
        int tam();

        
};

#include "NodoAVL.hxx"

#endif