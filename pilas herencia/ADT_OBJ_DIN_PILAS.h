/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: _ADT_OBJ_DIN_VECTOR_H
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 10/Febrero/2008 1:24p.m.
      Descripción: Crear la estructura Vector con objetos
                   con los siguiente métodos:
              + Constructor
              + Destructor
              + Vacio
              + Lleno
              + set Inicio
              + set Final
              + set Elemento Ordenado
              + get Inicio
              + get Final
              + get Elemento
              + Buscar
              + Imprimir
              + Eliminar
              + Ordenar
              + Buscar                                                       ***/
               

#ifndef _ADT_OBJ_DIN_PILAS_H
#define _ADT_OBJ_DIN_PILAS_H

/****  Librerias **************************************************************/
#include <iostream>
#include "ADT_OBJ_DIN_VECTOR.h"

using namespace std;
/**** Clase Vector  ***********************************************************/
template <class T> class Pila : public Vector<T>{
         bool meter(T);
         
};

template <class T> bool Pila<T>::meter(T e){
     Vector<T>::setFin(e);     
}
#endif
