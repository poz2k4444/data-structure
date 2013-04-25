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
               

#ifndef _ADT_OBJ_DIN_LISTADE_H// Linea modificada
#define _ADT_OBJ_DIN_LISTADE_H// Linea modificada

/****  Librerias **************************************************************/
#include <iostream>

using namespace std;
/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/

template <class T> class Nodo{
       public:
          T dato;
          ;Nodo<T> *sig, *ant;// Linea modificada   
      
       public:
          ;Nodo(): sig(NULL), ant(NULL){}// Linea modificada
          ;Nodo(T e): dato(e), sig(NULL), ant(NULL){}// Linea modificada
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase lista
      Descripción: Declara la clase                                      ***/
template <class T> class ListaDE{
      //Variables de instancia
      private:
          Nodo<T> *lst;
          int num;
      //Metodos de la clase 
      public:
          ;ListaDE();// Linea modificada
          ;~ListaDE();// Linea modificada
          bool empty();
          bool full();
          bool setIni(T);
          bool setFin(T);
          bool getIni(T &);
          bool getFin(T &);
          void setOrd(T);
          void getElem(T);
          ;Nodo<T> * search(T);// Linea modificada
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
;template <class T> ListaDE<T>::ListaDE(){// Linea modificada
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
;template <class T> ListaDE<T>::~ListaDE(){// Linea modificada
    eliminar();     
}//Fin del metodo destructoir
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: Verifica si la lista tiene elementos o no
          Entrada: Ninguna
           Salida: V/F si tiene o no elementos
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
;template <class T> bool ListaDE<T>::empty(){// Linea modificada
    return lst == NULL ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Llena
      Descripción: Verifica si la lista ya etsa llena
          Entrada: Ninguna
           Salida: V/F si esta llena o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
;template <class T> bool ListaDE<T>::full(){// Linea modificada
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
;template <class T> bool ListaDE<T>::setIni(T e){// Linea modificada
    //Variable local
    Nodo<T> * tmp, *aux;

    if(!full()){
        tmp = new Nodo<T>(e);
        aux = lst;
        if(!empty()){
             //lst->ant = tmp;
                     
             tmp->sig = aux;
             aux->ant = tmp;
             lst = tmp;
             tmp->ant = NULL;
             return true;
        }else{
             lst = tmp; 
             tmp->sig = NULL;
             tmp->ant = NULL;
        }   
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
;template <class T> bool ListaDE<T>::setFin(T e){// Linea modificada
        //Variable local
    Nodo<T> *tmp, *apt;
    if(!full()){
         tmp = new Nodo<T>(e);       
         if(empty()){
            setIni(e);  
         }else{
            apt = lst;
            while(apt->sig!=NULL){
                  apt = apt->sig;  
            } 
            apt->sig = tmp;
            tmp->ant = apt;
            tmp->sig = NULL;  
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
;template <class T> void ListaDE<T>::eliminar(){// Linea modificada
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
;template <class T> void ListaDE<T>::print(){// Linea modificada
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
;template <class T> bool ListaDE<T>::getIni(T &e) {// Linea modificada
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
;template <class T> bool ListaDE<T>::getFin(T &e) {// Linea modificada
       Nodo<T> *apt;
       
       if(empty())
                  return false;
       if(lst->sig == NULL) {
                   e = lst->dato;
                   delete lst;
                   lst = NULL;
       }else{
            apt = lst;
            ;while (apt->sig!= NULL) {// Linea modificada
                  ;apt = apt->sig;// Linea modificada
            }     
            e = apt->dato;
            apt->ant->sig = NULL;
            delete apt;   
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
;template <class T> void ListaDE<T>::setOrd(T e) {// Linea modificada
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
                                 tmp->ant = aux;
                                 aux->sig->ant = tmp;
                                 aux->sig = tmp;
                            }else{
                                 aux->sig = tmp;
                                 tmp->ant = aux;
                                 tmp->sig = NULL; 
                            }
                       }else{
                           setIni(e);  
                       }
                  }else{  
                       if(e < aux->dato){
                            ;setIni(e);// Linea modificada
                       }else{
                            ;setFin(e);// Linea modificada
                              }
                  }      
             }else{
                   ;setIni(e);// Linea modificada
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
;template <class T> void ListaDE<T>::getElem(T e) {// Linea modificada
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
                         
                         aux->sig->ant = aux2->sig;
                         delete aux;               
                     }else{
                         if(e==aux->dato){
                              delete aux;
                              aux2->sig =NULL;
                         }  
                     }
                }else{  
                     lst = aux->sig;
                     delete aux;
                }
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
;template <class T> void ListaDE<T>::ord2(T b) {// Linea modificada
         Nodo<T> *tmp;
         if(!empty()){
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
}
/***     Fin Elemento                                                       ***/

/***     Elemento: ordenar
      Descripción: ordena la lista
          Entrada: lista
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista ordenada                                           ***/
;template <class T> void ListaDE<T>::ordenar() {// Linea modificada
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
;template <class T> Nodo<T> * ListaDE<T>::search(T e){// Linea modificada
         Nodo<T> *tmp;
         if(!empty()){
              /*** Del int i = 0;                                           ***/
              tmp = lst;
              while(tmp->sig!=NULL && tmp->dato != e){
                    tmp = tmp ->sig;
                    /*** Del i++;                                           ***/
              }
              ;if(tmp->dato == e){// Linea modificada
                   return tmp;       
                   /*** Del cout<<"En la posicion "<<i<<"esta el dato: "<<e<<endl<<endl; ***/
              }
              return NULL;
         }
         return NULL;
}
/***     Fin Elemento                                                       ***/

/***     Elemento: longitud
      Descripción: dice la longitud de la lista
          Entrada: nignuna
           Salida: ninguna
    Pre-Condicion: Lista inicializada 
   Post-Condicion: ninguna                                           ***/
;template <class T> int ListaDE<T>::length() {// Linea modificada
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
/*** Fin_Seccion                                                            ***/
