/***     Secci�n: Declaraci�n
     Descripci�n: La declaracion de la base                                 ***/

/***     Programa: _nodos_H
    Programa Base: Ninguno
      Programador: Francisco Josu� L�pez Aguilar
            Fecha: 18/mayo/2009 2:10p.m.
      Descripci�n: la clase nodos que contiene los nodos usados en los ADT  ***/
#ifndef _nodos_H
#define _nodos_H

/****  Librerias **************************************************************/
#include <iostream>
#include <string>


using namespace std;
/***     Elemento: clase nodo
      Descripci�n: Declara la clase                                      ***/

template <class T> class Nodo{
       public:
          T dato;
          Nodo<T> *sig;   
      
       public:
          Nodo(): sig(NULL){}
          Nodo(T e): dato(e), sig(NULL){}  
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase nodo
      Descripci�n: Declara la clase                                      ***/

template <class T> class NodoC{
       public:
          T dato;
          ;NodoC<T> *sig, *ant;//Linea Modificada   
      
       public:
          ;NodoC(): sig(NULL), ant(NULL){}//Linea Modificada
          ;NodoC(T e): dato(e), sig(NULL), ant(NULL){}  //Linea Modificada
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase nodo
      Descripci�n: Declara la clase                                      ***/

template <class T> class NodoAVL{
       public:
          T dato;
          NodoAVL<T> *der, *izq;
          int fb;
      
       public:
          NodoAVL(): der(NULL), izq(NULL), fb(0){}
          NodoAVL(T e): dato(e), der(NULL), izq(NULL), fb(0){}
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

#endif
