#include "ArbolAVL.h"
#include "NodoAVL.h"

#include <iostream>
#include <string>
int main(){
    ArbolAVL<int>* arbol = new ArbolAVL<int>();
    std::cout<<"Hola\n";
    std::cout<<"Es vacio: "<<arbol->esVacio()<<std::endl;

    std::cout << "insercion de dato: " << arbol->insertar(50) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(30) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(70) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(20) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(40) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(60) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(80) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(10) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(25) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(35) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(45) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(55) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(65) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(75) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(85) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(5) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(15) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(95) << std::endl;
    std::cout << "insercion de dato: " << arbol->insertar(105) << std::endl;





    std::cout<<"Es vacio: "<<arbol->esVacio()<<std::endl;


    std::cout<<"Pre-orden: "<<std::endl;
    arbol->preOrden();
    std::cout<<std::endl;

    std::cout<<"Pos-orden: "<<std::endl;
    arbol->posOrden();
    std::cout<<std::endl;

    std::cout<<"In-orden: "<<std::endl;
    arbol->inOrden();
    std::cout<<std::endl;

    std::cout<<"Nivel-orden: "<<std::endl;
    arbol->nivelOrden();
    std::cout<<std::endl;

    std::cout<<"El tamaño actual del arbol es: "<<arbol->tamano()<<std::endl;
    
    std::cout<<"Eliminar: "<<arbol->eliminar(40)<<std::endl;


    std::cout<<"Despues de la eliminacion:"<<std::endl;

    std::cout<<"Pre-orden: "<<std::endl;
    arbol->preOrden();
    std::cout<<std::endl;

    std::cout<<"Pos-orden: "<<std::endl;
    arbol->posOrden();
    std::cout<<std::endl;

    std::cout<<"In-orden: "<<std::endl;
    arbol->inOrden();
    std::cout<<std::endl;

    std::cout<<"Nivel-orden: "<<std::endl;
    arbol->nivelOrden();
    std::cout<<std::endl;

    std::cout<<"El tamaño actual del arbol es: "<<arbol->tamano()<<std::endl;

}