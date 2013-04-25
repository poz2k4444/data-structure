/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: ADT_OBJ_DIN_LISTADE
    Programa Base: ADT_OBJ_DIN_LISTA
      Programador: Francisco Josué López Aguilar
            Fecha: 28/Febrero/2008 4:30p.m.
      Descripción: Crear la estructura Lista doblemente encadenada con objetos
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
              + Buscar    
              + Longitud                                                    ***/
               

#ifndef _ADT_OBJ_DIN_LISTADE_H
#define _ADT_OBJ_DIN_LISTADE_H

/****  Librerias **************************************************************/
#include <iostream>

using namespace std;
/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/

template <class T> class Nodo{
       public:
          T dato;
          Nodo<T> *sig;   
      
       public:
          Nodo(): sig(NULL){}
          Nodo(T e): dato(e), sig(NULL){}  
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase lista
      Descripción: Declara la clase                                      ***/
template <class T> class Lista{
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
          void getElem(T);
          void search(T);
          void print();
          void ord2(T);
          void ordenar();
          void eliminar();
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

    if(!full()){
        tmp = new Nodo<T>(e);
        tmp->sig = lst;
        lst = tmp;
        return true;
    }//Fin del full
    return false;
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
         
    }//Fin del fin     
    return false;
    
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
    }//Fin del while   
}//Fin del metodo eliminar
/***     Fin Elemento                                                  ***/   

/***     Elemento: imprimir
      Descripción: imprime en pantalla los elementos de la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/ 
template <class T> void Lista<T>::print(){
         Nodo<T> *tmp;
         tmp = lst;
         while(tmp != NULL){
               cout<<"El dato es: "<<tmp->dato<<" "<<endl;
               tmp = tmp->sig; 
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
       
       if(empty())
                  return false;
       e= lst->dato;
       apt = lst;
       lst = lst -> sig;
       delete apt;
       return true;
}                                 
/***     Fin Elemento                                                       ***/ 

/***     Elemento: getFin
      Descripción: Saca el elemento del final
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el ultimo elemento                                                  ***/
template <class T> bool Lista<T>::getFin(T e) {
       Nodo<T> *apt;
       
       if(empty())
                  return false;
       if(lst->sig == NULL) {
                   e = lst->dato;
                   delete lst;
                   lst = NULL;
       }//fin del if
       else {
            apt = lst;
            while (apt->sig->sig != NULL) {
            
            
            }        
       }//fin del else
       return true;
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
                       while(aux->sig!=NULL && aux->dato<tmp->dato){
                             aux = aux->sig;  
                       }
                       if(aux->sig!=NULL){
                            tmp->sig = aux->sig;
                            aux->sig = tmp;
                       }
                       aux = tmp;
                  }  
                  if(tmp->dato<aux->dato){
                       tmp =lst;
                       lst =tmp;
                  }
                  aux->sig =tmp;
             }
             lst = tmp;
        } 
}
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar elemento
      Descripción: saca un elemento dado por el usuario de la lista
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un elemento menos                              ***/
template <class T> void Lista<T>::getElem(T e) {
        Nodo<T> *aux, *aux2;
        if(!empty()){
             aux = lst;
             if(aux->sig!=NULL){
                if(e!= aux->dato){
                     aux2 =aux;
                     aux = aux->sig;
                     while(aux->sig !=NULL && e!=aux->dato){
                            aux2 = aux;
                            aux= aux->sig; 
                     }
                     if(aux->sig!=NULL){
                         aux2->sig = aux->sig;
                         delete aux;               
                     }
                }  
                lst = aux->sig;
                delete aux;
             }
             if(e==aux->dato){
                lst=NULL;
                delete aux;  
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
template <class T> void Lista<T>::ord2(T b) {
         Nodo<T> *tmp;
         if(b){
              tmp = lst;
              b = false;
              while(tmp->sig != NULL){
                   if(tmp->dato>tmp->sig->dato){
                        int a = tmp->dato;
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
template <class T> void Lista<T>::search(T e) {
         Nodo<T> *tmp;
         if(!empty()){
              int i = 0;
              tmp = lst;
              while(tmp->sig!=NULL && tmp->dato != e){
                    tmp = tmp ->sig;
                    i++;               
              }
              if(tmp->sig!= NULL){
                   cout<<"En la posicion "<<i<<"esta el dato: "<<e<<endl<<endl;
              }
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

/*** Fin_Seccion                                                            ***/
#endif
