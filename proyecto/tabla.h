/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: _tabla_H
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 18/mayo/2009 2:10p.m.
      Descripción: ña clase tabla que será la pricipal en elprograman       ***/
#ifndef _tabla_H
#define _tabla_H

/****  Librerias **************************************************************/
#include <iostream>
#include "clases.h"
#include "ADT_OBJ_DIN_LISTADEC.h"
#include "ADT_OBJ_DIN_LISTA.h"
#include "ADT_OBJ_DIN_LISTAC.h"
#include "ADT_OBJ_DIN_AVL.h"
#include <string>

using namespace std;

//prototipos
class Tabla;
ostream& operator<<(ostream&, const Tabla&);


class Tabla{
      //Prototipos
       public:
       ListaDEC<campos> lcampos;
       Lista<datos> ldatos;
       AVL<index> aindex;
       string nombre, descripcion, tipo;
       Tabla(string);
       Tabla();
       ~Tabla();
       void menuc();
       bool operator< (Tabla);
       bool operator> (Tabla);
       bool operator<= (Tabla);
       bool operator>= (Tabla);
       bool operator== (Tabla);
       bool operator!= (Tabla);
       friend ostream& operator <<(ostream&, const Tabla&);
       
        
};//Fin de la clase nodo
/***     Elemento: constructor
      Descripción: crea la clase
          Entrada: ninguno
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
Tabla::Tabla(){}
/***Fin del elemento                                                        ***/
/***     Elemento: constructor sobrecargado
      Descripción: crea la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
Tabla::Tabla(string n){
     nombre = n;                 
}
/***Fin del elemento                                                        ***/
/***     Elemento: destructor
      Descripción: destruye la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: clase inicializada  
   Post-Condicion: clase destruida                                          ***/
Tabla::~Tabla(){}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <
      Descripción: sobrecarga el operador binario <
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  Tabla:: operator< (Tabla t){
     return nombre<t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >
      Descripción: sobrecarga el operador binario >
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  Tabla:: operator> (Tabla t){
     return nombre>t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <=
      Descripción: sobrecarga el operador binario <=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  Tabla:: operator<= (Tabla t){
     return nombre<=t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >=
      Descripción: sobrecarga el operador binario >=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  Tabla:: operator>= (Tabla t){
     return nombre>=t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del ==
      Descripción: sobrecarga el operador binario ==
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  Tabla:: operator== (Tabla t){
     return nombre==t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del !=
      Descripción: sobrecarga el operador binario !=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  Tabla:: operator!= (Tabla t){
     return nombre!=t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <<
      Descripción: sobrecarga el operador binario <<
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
ostream& operator <<(ostream& out, const Tabla& t){
     out<<"Nombre: "<<t.nombre<<endl
        <<"Descripcion: "<<t.descripcion<<endl
        <<"Tipo: "<<t.tipo<<endl<<endl;
     return out;         
}
/***Fin del elemento                                                        ***/
#endif

/***     Fin_Sección                                                        ***/
