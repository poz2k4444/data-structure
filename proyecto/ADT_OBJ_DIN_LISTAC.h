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
               

#ifndef _ADT_OBJ_DIN_LISTAC_H
#define _ADT_OBJ_DIN_LISTAC_H

/****  Librerias **************************************************************/
#include <iostream>
#include "nodos.h"

using namespace std;


/***     Elemento: clase lista
      Descripción: Declara la clase                                      ***/
template <class T> class ListaC : public Nodo<T>{
      //Variables de instancia
      private:
          Nodo<T> *lst;
          int num;
      //Metodos de la clase 
      public:
          ListaC();
          ~ListaC();
          bool empty();
          bool full();
          bool setIni(T);
          bool setFin(T);
          bool getIni(T);
          bool getFin(T);
          bool setOrd(T);
          bool getElem(T);
          void print();
          Nodo<T> * search(T);
          Nodo<T> * ini();
          void ordenar2(bool);
          void eliminar();
          int length();
          void ordenar(){
              ordenar2(true);     
          }
      
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
template <class T> ListaC<T>::ListaC(){
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
template <class T> ListaC<T>::~ListaC(){
    eliminar();     
}//Fin del metodo destructoir
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: Verifica si la lista tiene elementos o no
          Entrada: Ninguna
           Salida: V/F si tiene o no elementos
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool ListaC<T>::empty(){
    return lst == NULL ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Llena
      Descripción: Verifica si la lista ya etsa llena
          Entrada: Ninguna
           Salida: V/F si esta llena o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool ListaC<T>::full(){
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
template <class T> bool ListaC<T>::setIni(T e){
         Nodo<T> *tmp = new Nodo<T>(e);
         if(!full()){
              if(empty()){
                   lst = tmp;
                   tmp ->sig = tmp;
                   return true;
              }else{
                   tmp->sig = lst->sig;
                   lst->sig = tmp;
                    
                   return true;
              }
         }else{
            return false;   
         }

} 
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter fin
      Descripción: mete un nuevo elemento al fin del lista
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un nuevo elemento al final                    ***/
template <class T> bool ListaC<T>::setFin(T e){
       Nodo<T> *tmp = new Nodo<T>(e);  
       if(!full()){
            if(empty()){
                lst = tmp;
                tmp->sig = tmp;
                return true; 
            }else{
                tmp->sig = lst->sig;
                lst->sig = tmp;
                lst = tmp;
                return true;  
            }
       }else{
           return false;  
       }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: getIni
      Descripción: Saca el elemento del inicio
          Entrada: ninguna
           Salida: v/F si lo pudo meter o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el primer elemento                             ***/
template <class T> bool ListaC<T>::getIni(T e){
         
        Nodo<T> *tmp; 
        if(!empty()){
             if(lst->sig == lst){
                e = lst->dato;
                delete lst;
                lst = NULL;
                return true;  
             }else{
                tmp = lst->sig;   
                lst->sig = lst->sig->sig;
                e = tmp->dato;
                delete tmp;  
                return true; 
             }
        }else{
            return false;  
        }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: getFin
      Descripción: Saca el elemento del final
          Entrada: ninguna
           Salida: T/F si lo sacó o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el ultimo elemento                             ***/
template <class T> bool ListaC<T>::getFin(T e){
        Nodo<T> *tmp;
        if(!empty()){
             if(lst->sig == lst){
                  e = lst->dato;
                  delete lst;
                  lst = NULL;
                  return true;
             }else{
                  tmp = lst;
                  while(tmp->sig != lst){
                        tmp = tmp->sig;  
                  } 
                  tmp->sig = lst->sig;
                  delete lst;
                  lst = tmp;
                  return true;
             }
        }else{
            return false;  
        }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: meter ordenado
      Descripción: mete un elemento de forma ordenada
          Entrada: elemento
           Salida: T/F si lo pudo meter o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con nuevo elemento ordenada                        ***/
template <class T> bool ListaC<T>::setOrd(T e){
         Nodo<T> *tmp, *aux, *aux2;
         if(!full()){
            tmp = new Nodo<T>(e);
            if(empty()){
                 lst = tmp;
                 tmp->sig = tmp;
                 return true;
            }else{
                 aux = lst;
                 aux2 = lst->sig;
                 while(e>aux->sig->dato && aux2 != lst){
                       aux = aux->sig;
                       aux2 = aux2->sig;  
                 }
                 if(e<aux2->dato){
                      tmp->sig = aux->sig;
                      aux->sig = tmp;
                      return true;
                 }else{
                      tmp->sig = lst->sig;
                      lst->sig = tmp;
                      lst = tmp;
                      return true; 
                 }
            }
         }else{
            return false;   
         }        
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar elemento
      Descripción: saca un elemento dado por el usuario de la lista
          Entrada: elemento
           Salida: T/F si lo saco o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un elemento menos                              ***/
template <class T> bool ListaC<T>::getElem(T e){
         Nodo<T> *tmp, *apt;
         bool b;
         if(!empty()){
              if(lst->sig != lst){
                  tmp = lst;
                  b = false;
                  do{
                      if(tmp->sig->dato==e){
                          apt = tmp->sig;
                          tmp->sig = apt->sig;
                          delete apt;
                          b = true; 
                      }
                      
                  tmp = tmp->sig;
                  }while(tmp!=lst);
              }else{
                  if(e == lst->dato){
                       delete lst;
                       lst = NULL;
                       return true;
                  }else{
                       return false; 
                  }
                  return b;
              }
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: imprimir
      Descripción: imprime en pantalla los elementos de la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void ListaC<T>::print(){
         Nodo<T> *tmp;
         if(!empty()){
             tmp = lst;
             do{
                cout<<tmp->sig->dato<<"\t";
                tmp = tmp->sig; 
             }while(tmp!=lst);
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: buscar
      Descripción: busca un elemento en la lista
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> Nodo<T> * ListaC<T>::search(T e){
         Nodo<T> *tmp;
         bool b;
         if(!empty()){
              b = false;
              tmp = lst;
              do{
                  if(e==tmp->sig->dato){
                      b=true; 
                  }
                  tmp = tmp->sig;
              }while(tmp!=lst && b==false);
              if(tmp == lst){
                   return NULL;  
                   cout<<"no se encontro";
              }else{
                   return tmp; 
                   cout<< tmp; 
              }
         }else{
               return NULL;
         }
}   
/***     Fin Elemento                                                       ***/
template <class T> Nodo<T> * ListaC<T>::ini(){
         Nodo<T> *tmp;
         if(empty()){
             tmp = lst;
             return tmp;    
         }else{
             tmp = lst->sig;
             return tmp;   
         }
}
/***     Elemento: longitud
      Descripción: dice la longitud de la lista
          Entrada: nignuna
           Salida: ninguna
    Pre-Condicion: Lista inicializada 
   Post-Condicion: ninguna                                                  ***/
template <class T> int ListaC<T>::length(){
         Nodo<T> *tmp;
         if(!empty()){
              if(lst->sig !=lst){
                   int x = 1;
                   tmp = lst->sig;
                   do{
                       tmp = tmp->sig;
                       x++;
                   }while(tmp!=lst);
                   return x;
              }else{
                   return 1; 
              }
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: ordenar
      Descripción: ordena la lista
          Entrada: lista
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista ordenada                                           ***/
template <class T> void ListaC<T>::ordenar2(bool b){
         Nodo<T> *tmp;
         if(!empty()){
              if(b){
                  tmp = lst->sig;
                  b = false;
                  while(tmp->sig != lst->sig){
                       if(tmp->dato > tmp->sig->dato){
                            T a = tmp->dato;
                            tmp->dato = tmp->sig->dato;
                            tmp->sig->dato = a;
                            b = true;
                       }
                       tmp = tmp->sig;   
                  }
                  ordenar2(b);
              }
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: eliminar
      Descripción: elimina los lementos de la lista liberando memoria
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin elementos                                      ***/
template <class T> void ListaC<T>::eliminar(){
         Nodo<T> * tmp;
         if(!empty()){
            do{ 
              tmp = lst->sig;
              lst->sig = tmp->sig;
              delete tmp;
            }while(lst->sig!=lst);
            delete lst;
            lst = NULL;
         }
}   
/***     Fin Elemento                                                       ***/

#endif//Fin del if
/***     Fin_Sección                                                        ***/
