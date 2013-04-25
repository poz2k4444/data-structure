/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: _ADT_OBJ_DIN_LISTA_H
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 16/Febrero/2008 2:10p.m.
      Descripción: Crear la estructura Lista con objetos
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
               

#ifndef _ADT_OBJ_DIN_LISTA_H
#define _ADT_OBJ_DIN_LISTA_H

/****  Librerias **************************************************************/
#include <iostream>
#include "nodos.h"

using namespace std;


/***     Elemento: clase lista
      Descripción: Declara la clase                                      ***/
template <class T> class Lista : public Nodo<T>{
      //Variables de instancia
      private:
          Nodo<T> *lst;
          int num;
      //Metodos de la clase 
      public:
          Lista();
          ~Lista();
          bool empty();
          bool full();
          bool setIni(T);
          bool setFin(T);
          bool getIni(T);
          bool getFin(T);
          void setOrd(T);
          bool getElem(T);
          Nodo<T> * search(T);
          void print();
          void ord2(bool);
          void ordenar();
          void eliminar();
          Nodo<T> * ini(){Nodo<T> *tmp(lst); return tmp;}
          int length();
      
};//Fin de la clase lista
/***     Fin Elemento                                                       ***/
/***     Fin_Sección                                                        ***/

/***     Sección: Funciones o metodos
     Descripción: se declaran los metodos de la clase                       ***/
     
/***     Elemento: Constructor
      Descripción: Inicializa la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: Lista Inicializado                                      ***/
template <class T> Lista<T>::Lista(){
    lst = NULL;     
    num = 0;
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Destructor
      Descripción: Libera la memoria usada por el lista
          Entrada: Ninguna
           Salida: Ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista destruido                                         ***/
template <class T> Lista<T>::~Lista(){
    eliminar();     
}//Fin del metodo destructoir
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: Verifica si la lista tiene elementos o no
          Entrada: Ninguna
           Salida: V/F si tiene o no elementos
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool Lista<T>::empty(){
    return lst == NULL ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Llena
      Descripción: Verifica si la lista ya etsa llena
          Entrada: Ninguna
           Salida: V/F si esta llena o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool Lista<T>::full(){
         //Variables local
         Nodo<T> *tmp = new Nodo<T>();
         if(tmp == NULL){
            return true; 
         }
         delete tmp;
    return false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter inicio
      Descripción: mete un nuevo elemento al inicio del lista
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Lsua inicializado  
   Post-Condicion: Lista con un nuevo elemento al inicio                   ***/
template <class T> bool Lista<T>::setIni(T e){
    //Variable local
    Nodo<T> * tmp;
    tmp = new Nodo<T>(e);
    if(!full()){
        if(!empty()){
             tmp->sig = lst;
             lst = tmp;             
        }else{
             lst = tmp;
             return true;      
        }
    }else{//Fin del full
        return false;
    }
}//Fin del metodo setIni
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter fin
      Descripción: mete un nuevo elemento al fin del lista
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un nuevo elemento al final                    ***/
template <class T> bool Lista<T>::setFin(T e){
        //Variable local
    Nodo<T> *tmp, *apt;
    if(!full()){
         tmp = new Nodo<T>(e);       
         if(empty()){
            lst = tmp;  
         }else{
            apt = lst;
            while(apt->sig!=NULL){
                  apt = apt->sig;  
            } 
            apt->sig = tmp;  
         }//Fin del else
         return true;
         
    }else{//Fin del fin     
         return false;
    }
}//Fin del metodo setFin
/***     Fin Elemento                                                       ***/

/***     Elemento: eliminar
      Descripción: elimina los lementos de la lista liberando memoria
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin elementos                                                  ***/
template <class T> void Lista<T>::eliminar(){
    //Variables local
    Nodo<T> *tmp, *apt;
    while(lst !=NULL){
        apt = lst;
        lst = lst->sig;
        delete apt;    
    }
    lst = NULL;//Fin del while   
}//Fin del metodo meter ordenado
/***     Fin Elemento                                                  ***/   

/***     Elemento: imprimir
      Descripción: imprime en pantalla los elementos de la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/ 
template <class T> void Lista<T>::print(){
         Nodo<T> *tmp;
         if(!empty()){
         tmp = lst;
         while(tmp->sig != NULL){
               cout<<tmp->dato<<"\t";
               tmp = tmp->sig; 
         }
         cout<<tmp->dato;
         }
}

/***     Fin Elemento                                                       ***/ 

/***     Elemento: getIni
      Descripción: Saca el elemento del inicio
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el primer elemento                                                  ***/
template <class T> bool Lista<T>::getIni(T e) {
       //VARIABLE LOCAL
       Nodo<T> *apt;
       
       if(empty()){
                  return false;
       }else{
         if(lst->sig != NULL){                 
           e= lst->dato;
           apt = lst;
           lst = lst -> sig;
           delete apt;
           return true;
         }else{
           delete lst;
           lst = NULL;
           return true;          
         }
       }
}                                 
/***     Fin Elemento                                                       ***/ 

/***     Elemento: getFin
      Descripción: Saca el elemento del final
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el ultimo elemento                                                  ***/
template <class T> bool Lista<T>::getFin(T e) {
       Nodo<T> *apt, *tmp;
       if(!empty()){
         if(lst->sig == NULL){
            delete lst;
            lst = NULL;     
         }else{
            apt = lst;
            do{
               tmp = apt;
               apt = apt->sig; 
            }while(apt->sig != NULL);
            delete apt;
            tmp->sig = NULL;      
         }  
       }else{
         return false;      
       }
}             

/***     Fin Elemento                                                       ***/

/***     Elemento: meter ordenado
      Descripción: mete un elemento de forma ordenada
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con nuevo elemento ordenada                        ***/
template <class T> void Lista<T>::setOrd(T e) {
        Nodo<T> *tmp, *aux;
        if(!full()){
             tmp = new Nodo<T>(e);
             if(!empty()){
                  aux = lst;
                  if(aux->sig!=NULL){
                       if(e > aux->dato){
                            while(aux->sig !=NULL && e>aux->sig->dato){
                                 aux = aux->sig;  
                            }
                            if(aux->sig!=NULL){
                                 tmp->sig = aux->sig;
                                 aux->sig = tmp;
                            }else{
                                 aux->sig = tmp;
                                 tmp->sig = NULL; 
                            }
                       }else{
                           setIni(e);  
                       }
                  }else{  
                       if(e < aux->dato){
                            setIni(e);
                       }else{
                            setFin(e);
                              }
                  }      
             }else{
                   setIni(e);
             }
        }
}
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar elemento
      Descripción: saca un elemento dado por el usuario de la lista
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un elemento menos                              ***/
template<class T> bool Lista<T>::getElem(T e){
               //variables locales
               Nodo<T> *apt, *aux, *b;
               int n = 1;
               
               b = search(e);
               if(b != NULL){
                            if(lst -> dato == e){
                                   getIni(e);
                                   return true;
                            }else{
                                  apt = lst;
                                  aux = apt -> sig;
                                  //while(aux != NULL && aux -> dato != e){
                                  while(n != 0 && aux -> dato != e){
                                            apt = apt -> sig;
                                            aux = apt -> sig;
                                            if(apt -> sig == NULL){
                                                 n = 0;
                                            }
                                  }
                                  if(aux -> dato == e){
                                         if(aux -> sig == NULL){
                                                delete apt -> sig;
                                                apt -> sig = NULL;
                                                return true;
                                         }else{
                                               apt -> sig = aux -> sig;
                                               return true;      
                                         }
                                  }else{
                                       return false;
                                  }
                            }
               }else
                     cout <<"No esta"<<endl;
               }
/***     Fin Elemento                                                       ***/

/***     Elemento: ordenar
      Descripción: ordena la lista
          Entrada: lista
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista ordenada                                           ***/
template <class T> void Lista<T>::ord2(bool b) {
         Nodo<T> *tmp;
         if(b){
              tmp = lst;
              b = false;
              while(tmp->sig != NULL){
                   if(tmp->dato>tmp->sig->dato){
                        T a = tmp->dato;
                        tmp->dato = tmp->sig->dato;
                        tmp->sig->dato = a;
                        b = true;
                   }  
                   tmp = tmp->sig; 
              }
              ord2(b);
         }
}
/***     Fin Elemento                                                       ***/

/***     Elemento: ordenar
      Descripción: ordena la lista
          Entrada: lista
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista ordenada                                           ***/
template <class T> void Lista<T>::ordenar() {
         bool b = true;
         ord2(b);
}
/***     Fin Elemento                                                       ***/
/***     Elemento: buscar
      Descripción: busca un elemento en la lista
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                           ***/
template<class T> Nodo<T> * Lista<T>::search(T e){
               //variables de isntancia
               Nodo<T> *apt;
               if(!empty()){
                    apt = lst;
                    while((apt -> dato != e) && apt -> sig){
                            apt = apt -> sig; 
                    }
                    if(apt -> dato == e){
                         return apt;
                    }else{
                          
                          return NULL;      
                    }
               }else{
                     
                     return NULL;
               }         
}
/***     Fin Elemento                                                       ***/

/***     Elemento: longitud
      Descripción: dice la longitud de la lista
          Entrada: nignuna
           Salida: ninguna
    Pre-Condicion: Lista inicializada 
   Post-Condicion: ninguna                                           ***/
template <class T> int Lista<T>::length() {
       Nodo<T> *tmp;  
       if(!empty()){
           tmp = lst;
           int i=1;
           while(tmp->sig!=NULL){
                 i++;
                 tmp = tmp->sig;                
           } 
           return i;
       }  
       return 0;
}   
/***     Fin Elemento                                                       ***/
#endif
