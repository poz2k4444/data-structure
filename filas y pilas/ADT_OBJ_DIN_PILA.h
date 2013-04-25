/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: _ADT_OBJ_DIN_PILA_H
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 12/Marzo/2009 10:44p.m.
      Descripción: Crear la estructura Vector con objetos
                   con los siguiente métodos:
              + Constructor
              + Destructor
              + Vacio
              + Lleno
              + set Inicio
              + get Final
              + Imprimir                                                    ***/
              
                
#ifndef _ADT_PILA_H
#define _ADT_PILA_H


using namespace std;

/****  Librerias **************************************************************/
#include<iostream>
#include"ADT_OBJ_DIN_VECTOR.h"

/**** Clase Fila  ***********************************************************/
template <class T> class Pila : public Vector<T>{
      
      //métodos de la clase
      public:
      
      Pila();
      ~Pila();
      bool meter(T);
      bool sacar(T &);
      void print();
      
      
      
      
      
};// Fin clase pila
/***     Fin Elemento                                                       ***/
/***     Fin_Sección                                                        ***/

/***     Sección: Funciones o metodos
     Descripción: se declaran los metodos de la clase                       ***/

/***     Elemento: Constructor
      Descripción: Inicializa la pila
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: fila Inicializado                                      ***/
template<class T> Pila<T>::Pila(){
              Vector<T>();               
}
/***     Fin Elemento                                                       ***/

/***     Elemento: Destructor
      Descripción: finaliza la pila
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: pila Inicializada 
   Post-Condicion: pila destruida                                           ***/
template<class T> Pila<T>::~Pila(){
               
}
/***     Fin Elemento                                                       ***/

/***     Elemento: meter
      Descripción: introduce un elemento a la pila
          Entrada: el elemento
           Salida: T/F si lometió o no
    Pre-Condicion: pila inicializada  
   Post-Condicion: pila con un elemento más                                      ***/
template<class T> bool Pila<T>::meter(T e){     
       return Vector<T>::setFin(e);
}
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar
      Descripción: saca un elemento de la pila
          Entrada: ninguna
           Salida: ningT/F si lo sacó o no y el elemento
    Pre-Condicion: pila inicializada  
   Post-Condicion: pila con un elemento menos                                      ***/
template<class T> bool Pila<T>::sacar(T & e){     
       return Vector<T>::getFin(e);
}
/***     Fin Elemento                                                       ***/

/***     Elemento: imprimir
      Descripción: imprime la fila
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: pila inicializada  
   Post-Condicion: ninguna                                      ***/
template<class T> void Pila<T>::print(){
               return Vector<T>::print();
}
/***     Fin Elemento                                                       ***/

#endif
/***     Fin_Sección                                                        ***/
