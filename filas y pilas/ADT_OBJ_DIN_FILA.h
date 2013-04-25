/***     Secci�n: Declaraci�n
     Descripci�n: La declaracion de la base                                 ***/

/***     Programa: _ADT_OBJ_DIN_FILA_H
    Programa Base: Ninguno
      Programador: Francisco Josu� L�pez Aguilar
            Fecha: 12/Marzo/2009 10:24p.m.
      Descripci�n: Crear la estructura Vector con objetos
                   con los siguiente m�todos:
              + Constructor
              + Destructor
              + Vacio
              + Lleno
              + set Inicio
              + get Final
              + Imprimir                                                    ***/
              
                
#ifndef _ADT_FILA_H
#define _ADT_FILA_H


using namespace std;

/****  Librerias **************************************************************/
#include<iostream>
#include"ADT_OBJ_DIN_LISTA.h"

/**** Clase Fila  ***********************************************************/
template <class T> class Fila : public Lista<T>{
      
      //m�todos de la clase
      public:
      
      Fila();
      ~Fila();
      bool meter(T);
      bool sacar(T &);
      void print();
      
      
      
      
      
};// Fin clase lista
/***     Fin Elemento                                                       ***/
/***     Fin_Secci�n                                                        ***/

/***     Secci�n: Funciones o metodos
     Descripci�n: se declaran los metodos de la clase                       ***/

/***     Elemento: Constructor
      Descripci�n: Inicializa la fila
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: fila Inicializado                                      ***/
template<class T> Fila<T>::Fila(){
              Lista<T>();               
}
/***     Fin Elemento                                                       ***/

/***     Elemento: Destructor
      Descripci�n: finaliza la pila
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: fila Inicializada 
   Post-Condicion: fila destruida                                           ***/
template<class T> Fila<T>::~Fila(){
               
}
/***     Fin Elemento                                                       ***/

/***     Elemento: meter
      Descripci�n: introduce un elemento a la fila
          Entrada: el elemento
           Salida: T/F si lometi� o no
    Pre-Condicion: fila inicializada  
   Post-Condicion: fila con un elemento m�s                                      ***/
template<class T> bool Fila<T>::meter(T e){     
       return Lista<T>::setIni(e);
}
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar
      Descripci�n: saca un elemento de la fila
          Entrada: ninguna
           Salida: ningT/F si lo sac� o no y el elemento
    Pre-Condicion: fila inicializada  
   Post-Condicion: fila con un elemento menos                                      ***/
template<class T> bool Fila<T>::sacar(T & e){     
       return Lista<T>::getFin(e);
}
/***     Fin Elemento                                                       ***/

/***     Elemento: imprimir
      Descripci�n: imprime la fila
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: lista inicializada  
   Post-Condicion: ninguna                                      ***/
template<class T> void Fila<T>::print(){
               return Lista<T>::print();
}
/***     Fin Elemento                                                       ***/

#endif
/***     Fin_Secci�n                                                        ***/
