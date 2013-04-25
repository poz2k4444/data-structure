/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: ADT_OBJ_DIN_LISTADEC
    Programa Base: ADT_OBJ_DIN_LISTAC
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
               

#ifndef _ADT_OBJ_DIN_LISTADEC_H
#define _ADT_OBJ_DIN_LISTADEC_H

/****  Librerias **************************************************************/
#include <iostream>
#include <string>

using namespace std;
/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/

template <class T> class Nodo{
       public:
          T dato;
          ;Nodo<T> *sig, *ant;//Linea Modificada   
      
       public:
          ;Nodo(): sig(NULL), ant(NULL){}//Linea Modificada
          ;Nodo(T e): dato(e), sig(NULL), ant(NULL){}  //Linea Modificada
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase lista
      Descripción: Declara la clase                                      ***/
;template <class T> class ListaDEC{//Linea Modificada
      //Variables de instancia
      private:
          Nodo<T> *lst;
          int num;
      //Metodos de la clase 
      public:
          ;ListaDEC();//Linea Modificada
          ;~ListaDEC();//Linea Modificada
          bool empty();
          bool full();
          bool setIni(T);
          bool setFin(T);
          ;bool getIni(T &);//Linea Modificada
          ;bool getFin(T &);//Linea Modificada
          bool setOrd(T);
          bool getElem(T);
          void print();
          Nodo<T> * search(T);
          void ordenar2(){ordenar(true);}
          void ordenar(bool);
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
;template <class T> ListaDEC<T>::ListaDEC(){//Linea Modificada
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
;template <class T> ListaDEC<T>::~ListaDEC(){//Linea Modificada
    eliminar();     
}//Fin del metodo destructoir
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: Verifica si la lista tiene elementos o no
          Entrada: Ninguna
           Salida: V/F si tiene o no elementos
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
;template <class T> bool ListaDEC<T>::empty(){//Linea Modificada
    return lst == NULL ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Llena
      Descripción: Verifica si la lista ya etsa llena
          Entrada: Ninguna
           Salida: V/F si esta llena o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
;template <class T> bool ListaDEC<T>::full(){//Linea Modificada
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
;template <class T> bool ListaDEC<T>::setIni(T e){//Linea Modificada
         Nodo<T> *tmp = new Nodo<T>(e);
         if(!full()){
              if(empty()){
                   lst = tmp;
                   tmp ->sig = tmp;
                   tmp->ant = tmp;
                   return true;
              }else{
                   ;tmp->sig = lst;//Linea Modificada
                   tmp->ant = lst->ant;
                   lst->ant->sig = tmp;
                   ;lst->ant = tmp;//Linea Modificada
                   lst = tmp;
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
;template <class T> bool ListaDEC<T>::setFin(T e){//Linea Modificada
       Nodo<T> *tmp = new Nodo<T>(e);  
       if(!full()){
            if(empty()){
                /*** Del lst = tmp; ***/
                /*** Del tmp->sig = tmp; ***/
                setIni(e);
                return true; 
            }else{
                ;tmp->sig = lst;//Linea Modificada
                ;tmp->ant = lst->ant; //Linea Modificada
                lst->ant->sig = tmp;
                ;lst->ant = tmp;//Linea Modificada
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
;template <class T> bool ListaDEC<T>::getIni(T &e){//Linea Modificada
         
        Nodo<T> *tmp(lst); 
        if(!empty()){
             if(lst->sig == lst){
                e = lst->dato;
                delete lst;
                lst = NULL;
                return true;  
             }else{
                lst = tmp->sig;
                ;tmp->ant->sig = tmp->sig; //Linea Modificada  
                ;tmp->sig = tmp->ant;//Linea Modificada
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
;template <class T> bool ListaDEC<T>::getFin(T &e){//Linea Modificada
        Nodo<T> *tmp;
        if(!empty()){
             if(lst->sig == lst){
                  e = lst->dato;
                  delete lst;
                  lst = NULL;
                  return true;
             }else{
                  ;tmp = lst->ant;//Linea Modificada
                  tmp->ant->sig = lst;
                  lst->ant = tmp->ant;
                  delete tmp;
                  /*** Del while(tmp->sig != lst){ ***/
                  /*** Del       tmp = tmp->sig;  ***/
                  /*** Del } ***/
                  /*** Del tmp->sig = lst->sig;***/
                  /*** Del delete lst;***/
                  /*** Del lst = tmp;***/
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
;template <class T> bool ListaDEC<T>::setOrd(T e){//Linea Modificada
         Nodo<T> *tmp, *aux, *aux2;
         if(!full()){
            tmp = new Nodo<T>(e);
            if(empty()){
                 lst = tmp;
                 tmp->sig = tmp;
                 tmp->ant = tmp;
                 return true;
            }else{
                 aux = lst;
                 aux2 = lst->sig;
                 while(e>aux->sig->dato && aux2 != lst){
                       aux = aux->sig;
                       aux2 = aux2->sig;  
                 }
                 if(aux2!=lst){
                      tmp->sig = aux->sig;
                      tmp->ant = aux;
                      aux->sig->ant = tmp;
                      aux->sig = tmp;
                      return true;
                 }else{
                      ;tmp->sig = lst;//Linea Modificada
                      tmp->ant = lst->ant;
                      lst->ant->sig = tmp;
                      lst->ant = tmp;
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
;template <class T> bool ListaDEC<T>::getElem(T e){//Linea Modificada
         Nodo<T> *apt;
               
               if(!empty()){
                    if(lst -> sig != lst){
                           if(lst -> dato == e){
                                lst -> sig -> ant = lst -> ant;
                                lst -> ant -> sig = lst -> sig;
                                apt = lst -> sig;
                                delete lst; 
                                lst = apt;
                           }else{
                              apt = lst;
                              while(apt -> sig != lst && apt -> dato != e){
                                      apt = apt -> sig;
                              }
                              if(apt -> dato == e){
                                   apt -> ant -> sig = apt -> sig;
                                   apt -> sig -> ant = apt -> ant;
                                   delete apt;
                                   return true;
                              }else{
                                    return false;      
                              }
                           }
                    }else{
                          if(lst -> dato == e){
                                 delete lst;
                                 lst = NULL;
                                 return true;       
                          }else{
                                      return false;
                          }
                    }
               }else{
                     return false;      
               }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: imprimir
      Descripción: imprime en pantalla los elementos de la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/
;template <class T> void ListaDEC<T>::print(){//Linea Modificada
         Nodo<T> *tmp;
         if(!empty()){
             tmp = lst;
             do{
                ;cout<<tmp->dato<<" -> ";//Linea Modificada
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
;template <class T> Nodo<T> * ListaDEC<T>::search(T e){//Linea Modificada
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

/***     Elemento: longitud
      Descripción: dice la longitud de la lista
          Entrada: nignuna
           Salida: ninguna
    Pre-Condicion: Lista inicializada 
   Post-Condicion: ninguna                                                  ***/
;template <class T> int ListaDEC<T>::length(){//Linea Modificada
         Nodo<T> *tmp;
         if(!empty()){
              if(lst->sig !=lst){
                   int x = 0;
                   ;tmp = lst;//Linea Modificada
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
;template <class T> void ListaDEC<T>::ordenar(bool b){//Linea Modificada
         Nodo<T> *tmp;
         if(!empty()){
              if(b){
                  ;tmp = lst;//Linea Modificada
                  b = false;
                  ;while(tmp->sig != lst){//Linea Modificada
                       if(tmp->dato > tmp->sig->dato){
                            T a = tmp->dato;
                            tmp->dato = tmp->sig->dato;
                            tmp->sig->dato = a;
                            b = true;
                       }
                       tmp = tmp->sig;   
                  }
                  ordenar(b);
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
;template <class T> void ListaDEC<T>::eliminar(){//Linea Modificada
         Nodo<T> * tmp;
         if(!empty()){
            do{ 
              ;tmp = lst->sig;//Linea Modificada
              lst->sig = tmp->sig;
              tmp->sig->ant = lst;
              delete tmp;
            }while(lst->sig!=lst);
            delete lst;
            lst = NULL;
         }
}   
/***     Fin Elemento                                                       ***/

#endif//Fin del if
/***     Fin_Sección                                                        ***/
