/***     Secci�n: Declaraci�n
     Descripci�n: La declaracion de la base                                 ***/

/***     Programa: ADT_OBJ_DIN_AVL
    Programa Base: Ninguna
      Programador: Francisco Josu� L�pez Aguilar
            Fecha: 09/Abril/2009 9:34 p.m.
      Descripci�n: Crear la estructura �rbol AVL con objetos
                   con los siguiente m�todos:
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
              + rotaci�n simple derecha
              + rotaci�n simple izquierda
              + rotaci�n doble derecha
              + rotaci�n doble izquierda
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

using namespace std;
/***     Elemento: clase nodo
      Descripci�n: Declara la clase                                      ***/

template <class T> class Nodo{
       public:
          T dato;
          Nodo<T> *der, *izq;
          int fb;
      
       public:
          Nodo(): der(NULL), izq(NULL), fb(0){}
          Nodo(T e): dato(e), der(NULL), izq(NULL), fb(0){}
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase AVL
      Descripci�n: Declara la clase                                      ***/
template <class T> class AVL{
      //Variables de instancia
      private:
          Nodo<T> *raiz;
      //Metodos de la clase 
      public:
          AVL();
          ~AVL();
          bool vacio();
          bool lleno();
          bool meter(T);
          bool sacar(T);
          void inorden(Nodo<T> *);
          void preorden(Nodo<T> *);
          void postorden(Nodo<T> *);
          void inordeninv(Nodo<T> *);
          void preordeninv(Nodo<T> *);
          void postordeninv(Nodo<T> *);
          Nodo<T> * buscar(T);
          Nodo<T> * sucesor(Nodo<T> *);
          Nodo<T> * predecesor(Nodo<T> *);    
          void hijos(T);
          Nodo<T> * padre(T);
          int altura(Nodo<T> *);
          void camino(T);
          int nivel(T);
          void eliminar(Nodo<T> *);
          void rsd(Nodo<T> *);
          void rsi(Nodo<T> *);
          void rdd(Nodo<T> *);
          void rdi(Nodo<T> *);
          void facb(Nodo<T> *);
          void balanceando(Nodo<T> *);
          void pivote(Nodo<T> *);
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
/***     Fin_Secci�n                                                        ***/

/***     Secci�n: Funciones o metodos
     Descripci�n: se declaran los metodos de la clase                       ***/
     
/***     Elemento: Constructor
      Descripci�n: Inicializa el �rbol
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: �rbol Inicializado                                      ***/
template <class T> AVL<T>::AVL(){
    raiz = NULL;
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: destructor
      Descripci�n: destruye el �rbol
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: arbol inicializado  
   Post-Condicion: �rbol destruido                                      ***/
template <class T> AVL<T>::~AVL(){
    eliminar(raiz);
    raiz = NULL;
}//Fin del metodo destructor
/***     Fin Elemento                                                       ***/

/***     Elemento: vacio
      Descripci�n: checa si est� o no vac�o
          Entrada: ninguna
           Salida: T/F si est� o no vac�o
    Pre-Condicion: �rbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> bool AVL<T>::vacio(){
    return raiz == NULL ? true : false;
}//Fin del metodo vacio
/***     Fin Elemento                                                       ***/

/***     Elemento: lleno
      Descripci�n: checa si est� o no lleno
          Entrada: ninguna
           Salida: T/F si est� o no lleno
    Pre-Condicion: �rbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> bool AVL<T>::lleno(){
    Nodo<T> *tmp = new Nodo<T>();
         if(tmp == NULL){
            return true; 
         }
         delete tmp;
    return false;
}//Fin del metodo lleno
/***     Fin Elemento                                                       ***/

/***     Elemento: meter
      Descripci�n: mete un nuevo elemento al �rbol
          Entrada: elemento
           Salida: T/F si lo meti� o no
    Pre-Condicion: arbol inicialiado  
   Post-Condicion: arbol con un elemento nuevo                                      ***/
template <class T> bool AVL<T>::meter(T e){
    //variable locales
    Nodo<T> *tmp, *aux(raiz), *ant(NULL);
    if(!lleno()){
      tmp = new Nodo<T>(e);
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
      Descripci�n: saca un elemento del arbol
          Entrada: elemento
           Salida: T/F si lo pudo sacar o no
    Pre-Condicion: arbol inicializado  
   Post-Condicion: arbol con un elemento menos                                      ***/
template <class T> bool AVL<T>::sacar(T e){
   Nodo<T> *b, *p, *s, *aux;
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
      Descripci�n: Imprime los elementos inorden
          Entrada: raiz
           Salida: elementos inorden en pantalla
    Pre-Condicion: arbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> void AVL<T>::inorden(Nodo<T> *tmp){
    if(tmp != NULL){
       inorden(tmp->izq);
       cout<<tmp->dato<<"->("<<tmp->fb<<")";;
       inorden(tmp->der);  
    }
}//Fin del metodo inorden
/***     Fin Elemento                                                       ***/

/***     Elemento: preorden
      Descripci�n: imprime los elementos en preorden
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: arbol inicializado  
   Post-Condicion: ninguna                                      ***/
template <class T> void AVL<T>::preorden(Nodo<T> *tmp){
    if(tmp != NULL){
       cout<<tmp->dato<<"->";
       preorden(tmp->izq);
       preorden(tmp->der);  
    }
}//Fin del metodo preorden
/***     Fin Elemento                                                       ***/

/***     Elemento: postorden
      Descripci�n: imprime en postorden
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado
   Post-Condicion: Ninguna                                        ***/
template <class T> void AVL<T>::postorden(Nodo<T> *tmp){
    if(tmp != NULL){
       postorden(tmp->izq);
       postorden(tmp->der);
       cout<<tmp->dato<<"->";  
    }
}//Fin del metodo postorden
/***     Fin Elemento                                                       ***/

/***     Elemento: inordeninv
      Descripci�n: imprime en inorden inverso
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::inordeninv(Nodo<T> *tmp){
    if(tmp != NULL){
       inordeninv(tmp->der);
       cout<<tmp->dato<<"->";
       inordeninv(tmp->izq);  
    }
}//Fin del metodo inordeninv
/***     Fin Elemento                                                       ***/

/***     Elemento: preordeninv
      Descripci�n: imprime en preorden inverso
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::preordeninv(Nodo<T> *tmp){
    if(tmp != NULL){
       cout<<tmp->dato<<"->";
       preordeninv(tmp->der);
       preordeninv(tmp->izq);  
    }
}//Fin del metodo preordeninv
/***     Fin Elemento                                                       ***/

/***     Elemento: postordeninv
      Descripci�n: Imprime en postorden inverso
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::postordeninv(Nodo<T> *tmp){
    if(tmp != NULL){
       postordeninv(tmp->der);
       postordeninv(tmp->izq);
       cout<<tmp->dato<<"->";  
    }
}//Fin del metodo postordeninv
/***     Fin Elemento                                                       ***/

/***     Elemento: buscar
      Descripci�n: busca un elemento en el �rbol
          Entrada: ninguna
           Salida: regresa el apuntador del elemento o null si no lo encontr�
    Pre-Condicion: arbols inicializado  
   Post-Condicion: ningnuna                                      ***/
template <class T> Nodo<T> * AVL<T>::buscar(T e){
    Nodo<T> *tmp(raiz);
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
      Descripci�n: busca el sucesor de un elemento
          Entrada: elemento
           Salida: apuntador del sucesor o null si no tiene
    Pre-Condicion: �rbol Inicializado
   Post-Condicion: Ninguna                                        ***/
template <class T> Nodo<T> * AVL<T>::sucesor(Nodo<T> *tmp){
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
      Descripci�n: encuentra el predecesor de un elemento
          Entrada: elemento
           Salida: el apuntador del elemento o null si no lo encontr�
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> Nodo<T> * AVL<T>::predecesor(Nodo<T> *tmp){
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
      Descripci�n: imprime los hijos de un elemento
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::hijos(T e){
    Nodo<T> *tmp;
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
      Descripci�n: busca el padre de un elemento
          Entrada: elemento
           Salida: el apuntador del padre o null si no tiene
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> Nodo<T> * AVL<T>::padre(T e){
    Nodo<T> *tmp(raiz), *aux;
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
      Descripci�n: indica la altura del �rbol
          Entrada: elemento
           Salida: la altura del �rbol
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> int AVL<T>::altura(Nodo<T> *tmp){
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
      Descripci�n: Indica el camino recorrido para llegar a un nodo
          Entrada: elemento
           Salida: elementos recorridos en pantalla
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::camino(T e){
    Nodo<T> *tmp(raiz);
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
      Descripci�n: indica el nivel en el qu� est� un elemento
          Entrada: elemento
           Salida: el nivel que tiene
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> int AVL<T>::nivel(T e){
    Nodo<T> *tmp(raiz);
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
      Descripci�n: elimina los elementos del �rbol
          Entrada: raiz
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado 
   Post-Condicion: �rbol sin elementos                                      ***/
template <class T> void AVL<T>::eliminar(Nodo<T> *tmp){
    if(tmp != NULL){
       eliminar(tmp->izq);
       eliminar(tmp->der);
       delete tmp;
         
    }
    
}//Fin del metodo eliminar
/***     Fin Elemento                                                       ***/

/***     Elemento: RSD
      Descripci�n: Rotaci�n simple derecha
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rsd(Nodo<T> *a){
    Nodo<T> *p,*b;
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
      Descripci�n: Rotaci�n simple izquierda
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rsi(Nodo<T> *a){
    Nodo<T> *p,*b;
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
      Descripci�n: Rotaci�n doble derecha
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rdd(Nodo<T> *a){
    Nodo<T> *p,*b,*c, *aux, *aux2;
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
      Descripci�n: Rotaci�n doble izquierda
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::rdi(Nodo<T> *a){
    Nodo<T> *p,*b,*c, *aux, *aux2;
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
      Descripci�n: indica cu�l es el factor de balanceo y lo asigna al nodo
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::facb(Nodo<T> *tmp){
    if(tmp != NULL){
       tmp->fb = altura(tmp->der) - altura(tmp->izq);
       facb(tmp->der);
       facb(tmp->izq);  
    }
}//Fin del metodo fb
/***     Fin Elemento                                                       ***/

/***     Elemento: balanceando
      Descripci�n: balancea el �rbol
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: �rbol balanceado                                ***/
template <class T> void AVL<T>::balanceando(Nodo<T> *a){
    Nodo<T> *b;
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
      Descripci�n: encuentra el pivote o el elemento desbalanceado
          Entrada: elemento
           Salida: apuntador del pivote o null si no lo encuentra
    Pre-Condicion: �rbol Inicializado  
   Post-Condicion: Ninguna                                      ***/
template <class T> void AVL<T>::pivote(Nodo<T> *tmp){
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
