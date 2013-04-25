/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: ADT_OBJ_DIN_AVL
    Programa Base: Ninguna
      Programador: Francisco Josué López Aguilar
            Fecha: 09/Abril/2009 9:34 p.m.
      Descripción: Crear la estructura árbol AVL con objetos
                   con los siguiente métodos:
              + Constructor
              + Destructor
              + Vacio
              + Lleno
              + setElem
              + getElem
              + Inorden
              + Preorden
              + postorden
              + inorden inverso
              + prorden inverso
              + postorden inverso
              + buscar
              + sucesor
              + predecesor    
              + hijos
              + padre
              + altura
              + camino
              + nivel del nodo
              + eliminar
              + rotación simple derecha
              + rotación simple izquierda
              + rotación doble derecha
              + rotación doble izquierda
              + operador <<
              + operador >>
              + operador +
              + operador -
              + operador =
              + operador <
              + operador >
              + operador <=
              + operador >=
              + operador ==                                                    ***/
               

#ifndef _ADT_OBJ_DIN_AVL_H
#define _ADT_OBJ_DIN_AVL_H

/****  Librerias **************************************************************/
#include <iostream>
#include "nodos.h"
using namespace std;


/***     Elemento: clase AVL
      Descripción: Declara la clase                                      ***/
template <class T> class AVL{
      //Variables de instancia
      private:
          NodoAVL<T> *raiz;
      //Metodos de la clase 
      public:
          AVL();
          ~AVL();
          bool vacio();
          bool lleno();
          bool meter(T);
          bool sacar(T);
          void inorden(NodoAVL<T> *);
          void preorden(NodoAVL<T> *);
          void postorden(NodoAVL<T> *);
          void inordeninv(NodoAVL<T> *);
          void preordeninv(NodoAVL<T> *);
          void postordeninv(NodoAVL<T> *);
          NodoAVL<T> * buscar(T);
          NodoAVL<T> * sucesor(NodoAVL<T> *);
          NodoAVL<T> * predecesor(NodoAVL<T> *);    
          void hijos(T);
          NodoAVL<T> * padre(T);
          int altura(NodoAVL<T> *);
          void camino(T);
          int nivel(T);
          void eliminar(NodoAVL<T> *);
          void rsd(NodoAVL<T> *);
          void rsi(NodoAVL<T> *);
          void rdd(NodoAVL<T> *);
          void rdi(NodoAVL<T> *);
          void facb(NodoAVL<T> *);
          void balanceando(NodoAVL<T> *);
          void pivote(NodoAVL<T> *);
          NodoAVL<T> * ini(){NodoAVL<T> *tmp(raiz); return tmp;}
          void preord(){
            preorden(raiz);     
          }
          void inord(){
            inorden(raiz);
          }
          void postord(){
            postorden(raiz);
          }
          void preordinv(){
            preordeninv(raiz);       
          }
          void inordinv(){
            inordeninv(raiz);     
          }
          void postordinv(){
            postordeninv(raiz);     
          }
          int alto(){
            return altura(raiz);    
          }
      
};//Fin de la clase lista
/***     Fin Elemento                                                       ***/
/***     Fin_Sección                                                        ***/

/***     Sección: Funciones o metodos
     Descripción: se declaran los metodos de la clase                       ***/
     
/***     Elemento: Constructor
      Descripción: Inicializa el árbol
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: árbol Inicializado                                      ***/
template <class T> AVL<T>::AVL(){
    raiz = NULL;
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: destructor
      Descripción: destruye el árbol
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: arbol inicializado  
   Post-Condicion: árbol destruido                                      ***/
template <class T> AVL<T>::~AVL(){
    eliminar(raiz);
    raiz = NULL;
}//Fin del metodo destructor
/***     Fin Elemento                                                       ***/

/***     Elemento: vacio
      Descripción: checa si está o no vacío
          Entrada: ninguna
           Salida: T/F si está o no vacío
    Pre-Condicion: árbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> bool AVL<T>::vacio(){
    return raiz == NULL ? true : false;
}//Fin del metodo vacio
/***     Fin Elemento                                                       ***/

/***     Elemento: lleno
      Descripción: checa si está o no lleno
          Entrada: ninguna
           Salida: T/F si está o no lleno
    Pre-Condicion: árbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> bool AVL<T>::lleno(){
    NodoAVL<T> *tmp = new NodoAVL<T>();
         if(tmp == NULL){
            return true; 
         }
         delete tmp;
    return false;
}//Fin del metodo lleno
/***     Fin Elemento                                                       ***/

/***     Elemento: meter
      Descripción: mete un nuevo elemento al árbol
          Entrada: elemento
           Salida: T/F si lo metió o no
    Pre-Condicion: arbol inicialiado  
   Post-Condicion: arbol con un elemento nuevo                                      ***/
template <class T> bool AVL<T>::meter(T e){
    //variable locales
    NodoAVL<T> *tmp, *aux(raiz), *ant(NULL);
    if(!lleno()){
      tmp = new NodoAVL<T>(e);
      while(aux!=NULL){
          ant = aux;
          if(aux->dato > e){
              aux = aux->izq;
          }else{
              aux = aux->der;
          }
      }
      if(ant == NULL){
          raiz = tmp;
      }else if(ant->dato > e){
          ant->izq = tmp;
          facb(raiz);
          pivote(raiz);//balanceando();
          return true;
      }else if(ant->dato < e){
          ant->der = tmp;
          facb(raiz);
          pivote(raiz);//balanceando();
          return true;
      }else{
          delete tmp;
          return false;
      }
    }else{
      return false;    
    }
    
}//Fin del metodo meter
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar
      Descripción: saca un elemento del arbol
          Entrada: elemento
           Salida: T/F si lo pudo sacar o no
    Pre-Condicion: arbol inicializado  
   Post-Condicion: arbol con un elemento menos                                      ***/
template <class T> bool AVL<T>::sacar(T e){
   NodoAVL<T> *b, *p, *s, *aux;
    b = buscar(e);
    if(b != NULL){
      p = predecesor(b);
      if(p != NULL){
        aux = padre(p->dato);
        b->dato = p->dato;
        if(aux->dato < p->dato){
          aux->der = NULL;               
        }else{
          aux->izq = NULL;    
        }
        delete p;
        facb(raiz);
        pivote(raiz);
        return true;
           
      }else{
        s = sucesor(b);
        if(s != NULL){
          aux = padre(s->dato);
          b->dato = s->dato;
          if(aux->dato < s->dato){
            aux->der = NULL;               
          }else{
            aux->izq = NULL;    
          }
          delete s;
          facb(raiz);
          pivote(raiz);
          return true;     
        }else{
          aux = padre(b->dato);
          if(aux->dato < b->dato){
            aux->der = NULL;               
          }else{
            aux->izq = NULL;    
          }
          delete b;
          facb(raiz);
          pivote(raiz);
          return true;      
        }      
      }
    }else{
      return false;      
    }
}//Fin del metodo sacar
/***     Fin Elemento                                                       ***/

/***     Elemento: inorden
      Descripción: Imprime los elementos inorden
          Entrada: raiz
           Salida: elementos inorden en pantalla
    Pre-Condicion: arbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> void AVL<T>::inorden(NodoAVL<T> *tmp){
    if(tmp != NULL){
       inorden(tmp->izq);
       cout<<tmp->dato<<"->("<<tmp->fb<<")";;
       inorden(tmp->der);  
    }
}//Fin del metodo inorden
/***     Fin Elemento                                                       ***/

/***     Elemento: preorden
      Descripción: imprime los elementos en preorden
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: arbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> void AVL<T>::preorden(NodoAVL<T> *tmp){
    if(tmp != NULL){
       cout<<tmp->dato<<"->";
       preorden(tmp->izq);
       preorden(tmp->der);  
    }
}//Fin del metodo preorden
/***     Fin Elemento                                                       ***/

/***     Elemento: postorden
      Descripción: imprime en postorden
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: árbol Inicializado
   Post-Condicion: Ninguna                                        ***/
template <class T> void AVL<T>::postorden(NodoAVL<T> *tmp){
    if(tmp != NULL){
       postorden(tmp->izq);
       postorden(tmp->der);
       cout<<tmp->dato<<"->";  
    }
}//Fin del metodo postorden
/***     Fin Elemento                                                       ***/

/***     Elemento: inordeninv
      Descripción: imprime en inorden inverso
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::inordeninv(NodoAVL<T> *tmp){
    if(tmp != NULL){
       inordeninv(tmp->der);
       cout<<tmp->dato<<"->";
       inordeninv(tmp->izq);  
    }
}//Fin del metodo inordeninv
/***     Fin Elemento                                                       ***/

/***     Elemento: preordeninv
      Descripción: imprime en preorden inverso
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::preordeninv(NodoAVL<T> *tmp){
    if(tmp != NULL){
       cout<<tmp->dato<<"->";
       preordeninv(tmp->der);
       preordeninv(tmp->izq);  
    }
}//Fin del metodo preordeninv
/***     Fin Elemento                                                       ***/

/***     Elemento: postordeninv
      Descripción: Imprime en postorden inverso
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::postordeninv(NodoAVL<T> *tmp){
    if(tmp != NULL){
       postordeninv(tmp->der);
       postordeninv(tmp->izq);
       cout<<tmp->dato<<"->";  
    }
}//Fin del metodo postordeninv
/***     Fin Elemento                                                       ***/

/***     Elemento: buscar
      Descripción: busca un elemento en el árbol
          Entrada: ninguna
           Salida: regresa el apuntador del elemento o null si no lo encontró
    Pre-Condicion: arbols inicializado  
   Post-Condicion: ningnuna                                      ***/
template <class T> NodoAVL<T> * AVL<T>::buscar(T e){
    NodoAVL<T> *tmp(raiz);
    if(!vacio()){
      while(e != tmp->dato && tmp != NULL){
         if(e > tmp->dato){
            tmp = tmp->der;  
         }else{
            tmp = tmp->izq;   
         }   
      } 
      if(tmp != NULL){
         return tmp;  
      }else{
         return NULL;   
      }  
    }else{
      return NULL;    
    }
}//Fin del metodo buscar
/***     Fin Elemento                                                       ***/

/***     Elemento: sucesor
      Descripción: busca el sucesor de un elemento
          Entrada: elemento
           Salida: apuntador del sucesor o null si no tiene
    Pre-Condicion: árbol Inicializado
   Post-Condicion: Ninguna                                        ***/
template <class T> NodoAVL<T> * AVL<T>::sucesor(NodoAVL<T> *tmp){
    if(!vacio()){
        if(tmp->izq != NULL){
             tmp = tmp->der;       
             while(tmp->izq != NULL){
                tmp = tmp->izq;     
             }
             return tmp;
        }else{
           return NULL;   
        } 
    }else{
       return NULL;   
    }
}//Fin del metodo sucesor
/***     Fin Elemento                                                       ***/

/***     Elemento: predecesor
      Descripción: encuentra el predecesor de un elemento
          Entrada: elemento
           Salida: el apuntador del elemento o null si no lo encontró
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> NodoAVL<T> * AVL<T>::predecesor(NodoAVL<T> *tmp){
    if(!vacio()){
        if(tmp->izq != NULL){
             tmp = tmp->izq;       
             while(tmp->der != NULL){
                tmp = tmp->der;     
             }
             return tmp;
        }else{
           return NULL;   
        } 
    }else{
       return NULL;   
    }
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: hijos
      Descripción: imprime los hijos de un elemento
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::hijos(T e){
    NodoAVL<T> *tmp;
    tmp = buscar(e);
    if(tmp != NULL){
         if(tmp->der != NULL){
              cout<< tmp->der->dato;
         }
         if(tmp->izq != NULL){
              cout<< tmp->izq->dato;
         }
    }
}//Fin del metodo hijos
/***     Fin Elemento                                                       ***/

/***     Elemento: padre
      Descripción: busca el padre de un elemento
          Entrada: elemento
           Salida: el apuntador del padre o null si no tiene
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> NodoAVL<T> * AVL<T>::padre(T e){
    NodoAVL<T> *tmp(raiz), *aux;
    if(!vacio()){
       if(e != raiz->dato){
         if(e > tmp->dato){
           tmp = tmp->der;   
         }else{
           tmp = tmp->izq;   
         }
         aux = raiz;
         while(e != tmp->dato && tmp != NULL){
            if(e > tmp->dato){
               aux = tmp;
               tmp = tmp->der;  
            }else{
               aux = tmp;
               tmp = tmp->izq;   
            }     
         }
         if(e == tmp->dato){
            return aux;  
         }else{
            return NULL;   
         }
       }else{
         return NULL;    
       }  
    }else{
       return NULL;   
    }
}//Fin del metodo padre
/***     Fin Elemento                                                       ***/

/***     Elemento: altura
      Descripción: indica la altura del árbol
          Entrada: elemento
           Salida: la altura del árbol
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> int AVL<T>::altura(NodoAVL<T> *tmp){
    if(tmp != NULL){
        int a = altura(tmp->izq); 
        int b = altura(tmp->der);
        if(a>b){
           return a+1;  
        }else{
           return b+1;   
        }
    }else{
       return 0;   
    }
}//Fin del metodo altura
/***     Fin Elemento                                                       ***/

/***     Elemento: camino
      Descripción: Indica el camino recorrido para llegar a un nodo
          Entrada: elemento
           Salida: elementos recorridos en pantalla
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::camino(T e){
    NodoAVL<T> *tmp(raiz);
    if(!vacio()){
       while(e != tmp->dato && tmp != NULL){
           cout<<tmp->dato<<"->";
           if(e > tmp->dato){
              tmp = tmp->der;  
           }else{
              tmp = tmp->izq;   
           }  
       }
       if(tmp != NULL){
          cout<<tmp->dato;  
       }else{
          cout<<"No esta";   
       }
    }
}//Fin del metodo camino
/***     Fin Elemento                                                       ***/

/***     Elemento: nivel
      Descripción: indica el nivel en el qué está un elemento
          Entrada: elemento
           Salida: el nivel que tiene
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> int AVL<T>::nivel(T e){
    NodoAVL<T> *tmp(raiz);
    if(!vacio()){
       int c = 1;
       while(e != tmp->dato && tmp != NULL){
          c++;
          if(e > tmp->dato){
             tmp = tmp->der;  
          }else{
             tmp = tmp->izq;   
          }     
       }
       if(tmp != NULL){
          return c;  
       }else{
          return 0;   
       }  
    }else{
       return 0;   
    }
}//Fin del metodo nivel
/***     Fin Elemento                                                       ***/

/***     Elemento: eliminar
      Descripción: elimina los elementos del árbol
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: árbol Inicializado 
   Post-Condicion: árbol sin elementos                                      ***/
template <class T> void AVL<T>::eliminar(NodoAVL<T> *tmp){
    if(tmp != NULL){
       eliminar(tmp->izq);
       eliminar(tmp->der);
       delete tmp;
         
    }
    
}//Fin del metodo eliminar
/***     Fin Elemento                                                       ***/

/***     Elemento: RSD
      Descripción: Rotación simple derecha
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rsd(NodoAVL<T> *a){
    NodoAVL<T> *p,*b;
    p = padre(a->dato);
    b = a->izq;
    if(p != NULL){
       p->izq = b;
       a->izq = b->der;
       b->der = a;  
    }else{
       raiz = b;
       a->izq = b->der;
       b->der = a;   
    }
}//Fin del metodo RSD
/***     Fin Elemento                                                       ***/

/***     Elemento: RSI
      Descripción: Rotación simple izquierda
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rsi(NodoAVL<T> *a){
    NodoAVL<T> *p,*b;
    p = padre(a->dato);
    b = a->der;
    if(p != NULL){
       p->der = b;
       a->der = b->izq;
       b->izq = a;  
    }else{
       raiz = b;
       a->der = b->izq;
       b->izq = a;   
    }
}//Fin del metodo RSI
/***     Fin Elemento                                                       ***/

/***     Elemento: RDD
      Descripción: Rotación doble derecha
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rdd(NodoAVL<T> *a){
    NodoAVL<T> *p,*b,*c, *aux, *aux2;
    p = padre(a->dato);
    b = a->izq;
    c = b->der;
    if(p != NULL){
      p->izq = c;
      aux = c->izq;
      aux2 = c->der;
      c->der = a;
      c->izq = b;
      a->izq = aux2;
      b->der = aux;     
    }else{
      raiz = c;
      aux = c->izq;
      aux2 = c->der;
      c->der = a;
      c->izq = b;
      a->izq = aux2;
      b->der = aux;       
    }
}//Fin del metodo RDD
/***     Fin Elemento                                                       ***/

/***     Elemento: RDI
      Descripción: Rotación doble izquierda
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rdi(NodoAVL<T> *a){
    NodoAVL<T> *p,*b,*c, *aux, *aux2;
    p = padre(a->dato);
    b = a->der;
    c = b->izq;
    if(p != NULL){
      p->der = c;
      aux = c->izq;
      aux2 = c->der;
      c->izq = a;
      c->der = b;
      a->der = aux;
      b->izq = aux2;     
    }else{
      raiz = c;
      aux = c->izq;
      aux2 = c->der;
      c->izq = a;
      c->der = b;
      a->der = aux;
      b->izq = aux2;       
    }
}//Fin del metodo RDI
/***     Fin Elemento                                                       ***/

/***     Elemento: fb
      Descripción: indica cuál es el factor de balanceo y lo asigna al nodo
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::facb(NodoAVL<T> *tmp){
    if(tmp != NULL){
       tmp->fb = altura(tmp->der) - altura(tmp->izq);
       facb(tmp->der);
       facb(tmp->izq);  
    }
}//Fin del metodo fb
/***     Fin Elemento                                                       ***/

/***     Elemento: balanceando
      Descripción: balancea el árbol
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: árbol balanceado                                ***/
template <class T> void AVL<T>::balanceando(NodoAVL<T> *a){
    NodoAVL<T> *b;
    //a = pivote(raiz, c);
    if(a != NULL){
      if(a->fb > 1){
        b = a->der;
        if(b->fb >= 0){
          rsi(a);     
        }else{
          rdi(a);    
        }     
      }else{
        b = a->izq;
        if(b->fb >= 0){
          rdd(a);     
        }else{
          rsd(a);      
        }      
      }
      facb(raiz);
      //balanceando();     
    }
}//Fin del metodo balanceando
/***     Fin Elemento                                                       ***/

/***     Elemento: pivote
      Descripción: encuentra el pivote o el elemento desbalanceado
          Entrada: elemento
           Salida: apuntador del pivote o null si no lo encuentra
    Pre-Condicion: árbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::pivote(NodoAVL<T> *tmp){
    if(tmp != NULL){
      pivote(tmp->der);
      pivote(tmp->izq);
      if(tmp->fb > 1 || tmp->fb < -1){
        balanceando(tmp);      
      }  
    }
}//Fin del metodo pivote
/***     Fin Elemento                                                       ***/
#endif
/*** Fin_Seccion                                                            ***/
