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
               

#ifndef _ADT_OBJ_DIN_VECTOR_H
#define _ADT_OBJ_DIN_VECTOR_H

/****  Librerias **************************************************************/
#include <iostream>

using namespace std;
/**** Clase Vector  ***********************************************************/
template <class T> class Vector{
      //Variables de instancia
      private:
          T *vec;
          int max, top;
          void ord2(T *);
      //Metodos de la clase 
      public:
          Vector();
          Vector(int);
          ~Vector();
          bool empty();
          bool full();
          bool setIni(T);
          bool setFin(T);
          bool getIni(T &);
          bool getFin(T &);
          bool setOrd(T);
          void getElem(T);
          void search(T);
          void print();
          void ordenar();
          bool eliminar();
      
};//Fin de la clase vector
/***     Fin_Sección                                                        ***/

/***     Sección: Funciones o metodos
     Descripción: se declaran los metodos de la clase                       ***/

/***     Elemento: Constructor
      Descripción: Inicializa el vector
          Entrada: el numero de elementos/la capacidad del vector
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: Vector Inicializado                                      ***/
template <class T> Vector<T>::Vector(){
    top = 0;
    vec = new int[1000];     
}//Fin del metodo constructor

/***     Fin Elemento                                                       ***/
/***     Elemento: Constructor
      Descripción: Inicializa el vector
          Entrada: el numero de elementos/la capacidad del vector
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: Vector Inicializado                                      ***/
template <class T> Vector<T>::Vector(int n){
    max = n;
    top = 0;
    vec = new int[max];     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Destructor
      Descripción: Libera la memoria usada por el vector
          Entrada: Ninguna
           Salida: Ninguna
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Vector destruido                                         ***/
template <class T> Vector<T>::~Vector(){
    delete [] vec;     
}//Fin del metodo destructoir
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: Verifica si el vector tiene elementos o no
          Entrada: Ninguna
           Salida: V/F si tiene o no elementos
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool Vector<T>::empty(){
    return top == 0 ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: Verifica si el vector no tiene espacios vacios
          Entrada: Ninguna
           Salida: V/F si tiene o no espacios vacios
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool Vector<T>::full(){
    return top >= max ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter inicio
      Descripción: mete un nuevo elemento al inicio del vector
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Vector con un nuevo elemento al inicio                   ***/
template <class T> bool Vector<T>::setIni(T e){
    if(!full()){
         for(int i = top; i>0; i--){
               vec[i] = vec[i-1];
         }
         vec[0] = e;
         top++;
         return true;
    }//Fin del full
    return false;
}//Fin del metodo setIni
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter fin
      Descripción: mete un nuevo elemento al fin del vector
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Vector con un nuevo elemento al final                    ***/
template <class T> bool Vector<T>::setFin(T e){
    if(!full()){
         vec[top++] = e;
         return true;
    }//Fin del fin     
    return false;
}//Fin del metodo setFin
/***     Fin Elemento                                                       ***/

/***     Elemento: Sacar inicio
      Descripción: Saca un nuevo elemento al inicio del vector
          Entrada: Ninguna
           Salida: V y el elemento/F si lo pudo sacar o no
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Vector sin un nuevo elemento al inicio                   ***/
template <class T> bool Vector<T>::getIni(T &e){
    if(!empty()){
         e = vec[0];
         top--;
         for(int i = 1; i <= top; i++){
               vec[i-1] = vec[i];
         }
         return true;
    }//Fin del fin
    return false;
}//Fin del metodo getIni
/***     Fin Elemento                                                       ***/

/***     Elemento: Sacar fin
      Descripción: Saca un nuevo elemento al fin del vector
          Entrada: Ninguna
           Salida: V y el elemento/F si lo pudo sacar o no
    Pre-Condicion: Vector inicializado  
   Post-Condicion: Vector sin un nuevo elemento al fin                   ***/
template <class T> bool Vector<T>::getFin(T &e){
    if(!empty()){
         top--;
         e = vec[top];
         
         return true;
    }//Fin del if
    return false;
}//Fin del metodo getFin
/***     Fin Elemento   
  
/***     Elemento: MeterOrd
      Descripción: mete el elemento ordenadamente
          Entrada: el elemento
           Salida: ninguna
    Pre-Condicion: vecor inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> bool Vector<T>::setOrd(T e){
    if(!full()){
         int x=0;
         top++;
         while(e>vec[x] && x<top-1){
               x++;  
         }
         for(int i = top; i<=x; i--){
               vec[i] = vec[i-1];
         }
         vec[x] = e;
         return true;
    }//Fin del if
    return false;     
}//Fin del metodo meter ordenado
/***     Fin Elemento                                                  ***/

/***     Elemento: Sacarelem
      Descripción: saca el elemento deseado
          Entrada: el elemento
           Salida: T/V si lo puedo sacar o no
    Pre-Condicion: vecor inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void Vector<T>::getElem(T e){
    if(!empty()){
         for(int i=0;i<top;i++){
             if(vec[i] == e){
                for(int j = i; j<top; j++){
                     vec[j] = vec[j+1]; 
                }  
                i=top;top--;
             } 
             
             
         }
         cout<<"No esta ese elemento en el vector"<<endl<<endl;
         
         //return;
    }//Fin del if
    //return;     
}//Fin del metodo sacr ordenado  */
/***     Fin Elemento

/***     Elemento: buscar
      Descripción: busca el elemento y da la posicion
          Entrada: el elemento
           Salida: la posicion del vector dado
    Pre-Condicion: vecor inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void Vector<T>::search(T e){
    if(!empty()){
         int i=0;
         while(e!=vec[i]&&i<top){
               i++;  
         }
         if(i==top){
            cout<<"No se encontro el elemento "<<e<<endl;  
         }else{
               cout<<"El elemento: "<<vec[i]<<" esta en la posicion: "<<i+1<<endl;
         }
         return;
    }//Fin del if
    return;     
}//Fin del metodo buscar
/***     Fin Elemento

/***     Elemento: buscar
      Descripción: busca el elemento y da la posicion
          Entrada: el elemento
           Salida: la posicion del vector dado
    Pre-Condicion: vecor inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void Vector<T>::print(){
    if(!empty()){
         for(int i=0;i<top;i++){
               cout<<"El elemento en la posicion "<<i+1<<" es: "<<vec[i]<<endl;
         }
         return;
    }//Fin del if
    return;     
}//Fin del metodo buscar
/***     Fin Elemento****/

/***     Elemento: ordenar
      Descripción: ordena el vector
          Entrada: vector
           Salida: V/F si puedo o no ordenar
    Pre-Condicion: Vector inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void Vector<T>::ord2(T *vec){
    if(!empty()){
         for(int i=1;i<top;i++){
               for(int j=0;j<top-i;j++){
                     if(vec[j]>vec[j+1]){
                          int a = vec[j];  
                          vec[j]=vec[j+1];
                          vec[j+1]=a;
                             
                     }
               }
         }
         return;
    }//Fin del if
    return;
}//Fin del metodo getFin
/***     Fin Elemento                                                       ***/
/***     Elemento: ordenar
      Descripción: ordena el vector
          Entrada: vector
           Salida: V/F si puedo o no ordenar
    Pre-Condicion: Vector inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void Vector<T>::ordenar(){
         ord2(vec);
}//Fin del metodo getFin
/***     Fin Elemento     

/***     Elemento: MeterOrd
      Descripción: mete el elemento ordenadamente
          Entrada: el elemento
           Salida: ninguna
    Pre-Condicion: vecor inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> bool Vector<T>::eliminar(){
    if(!empty()){
         top = 0;
         return true;
    }//Fin del if
    return false;     
}//Fin del metodo meter ordenado
/***     Fin Elemento                                                  ***/                                                  
#endif

/***     Fin_Sección                                                        ***/
