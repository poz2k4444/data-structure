/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/

/***     Programa: _clases_H
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 18/mayo/2009 2:10p.m.
      Descripción: la clases que van a ir después de la tabla               ***/
#ifndef _clases_H
#define _clases_H

/****  Librerias **************************************************************/
#include <iostream>
#include "ADT_OBJ_DIN_LISTA.h"
#include <string>

using namespace std;
/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/
class campos;
ostream& operator<<(ostream&, const campos&);

class valores;
ostream& operator<<(ostream&, const valores&);

class datos;
ostream& operator<<(ostream&, const datos&);

class index;
ostream& operator<<(ostream&, const index&);


class campos{
       public:
          string nombre, descripcion, orden, tipo;   
          campos();
          campos(string);
          ~campos();
          friend ostream& operator <<(ostream&, const campos&);
          bool operator< (campos);
          bool operator> (campos);
          bool operator<= (campos);
          bool operator>= (campos);
          bool operator== (campos);
          bool operator!= (campos);
  
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/

class valores{
       public:
          string valor;
          int orden; 
          valores();
          valores(string);
          ~valores();  
          friend ostream& operator <<(ostream&, const valores&);
          bool operator< (valores);
          bool operator> (valores);
          bool operator<= (valores);
          bool operator>= (valores);
          bool operator== (valores);
          bool operator!= (valores);
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/

class datos{
       private:
          
       public:
          int posicion;
          datos();
          datos(int);
          ~datos();
          Lista<valores> lvalor;  
          friend ostream& operator <<(ostream&, const datos&);
          bool operator< (datos);
          bool operator> (datos);
          bool operator<= (datos);
          bool operator>= (datos);
          bool operator== (datos);
          bool operator!= (datos);
      
  
};//Fin de la clase nodo

/***     Fin Elemento                                                       ***/

/***     Elemento: clase nodo
      Descripción: Declara la clase                                      ***/
class index{
      public:
          string cosa;
          int pdatos;
          index();
          index(int);
          ~index();
          friend ostream& operator <<(ostream&, const index&);
          bool operator< (index);
          bool operator> (index);
          bool operator<= (index);
          bool operator>= (index);
          bool operator== (index);
          bool operator!= (index);
      
};
//Fin de la clase nodo

/***     Fin Elemento                                                       ***/
/***     Elemento: constructor
      Descripción: crea la clase
          Entrada: ninguno
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
campos::campos(){}
/*** Fin del elemento                                                       ***/
/***     Elemento: constructor sobrecargado
      Descripción: crea la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
campos::campos(string n){
    nombre = n;                      
}
/***Fin del elemento                                                        ***/
/***     Elemento: destructor
      Descripción: destruye la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: clase inicializada  
   Post-Condicion: clase destruida                                          ***/
campos::~campos(){}
/***Fin del elemento                                                        ***/
/***     Elemento: constructor
      Descripción: crea la clase
          Entrada: ninguno
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
valores::valores(){}
/*** Fin del elemento                                                       ***/
/***     Elemento: constructor sobrecargado
      Descripción: crea la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
valores::valores(string n){
     valor = n;                        
}
/***Fin del elemento                                                        ***/
/***     Elemento: destructor
      Descripción: destruye la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: clase inicializada  
   Post-Condicion: clase destruida                                          ***/
valores::~valores(){}
/***Fin del elemento                                                        ***/
/***     Elemento: constructor
      Descripción: crea la clase
          Entrada: ninguno
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
datos::datos(){}
/*** Fin del elemento                                                       ***/
/***     Elemento: destructor
      Descripción: destruye la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: clase inicializada  
   Post-Condicion: clase destruida                                          ***/
datos::~datos(){}
/***Fin del elemento                                                        ***/
/***     Elemento: constructor sobrecargado
      Descripción: crea la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
datos::datos(int n){
     posicion = n;                  
}
/***Fin del elemento                                                        ***/
/***     Elemento: constructor
      Descripción: crea la clase
          Entrada: ninguno
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
index::index(){}
/*** Fin del elemento                                                       ***/
/***     Elemento: constructor sobrecargado
      Descripción: crea la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: ninguna  
   Post-Condicion: clase inicializada                                       ***/
index::index(int n){
    pdatos = n;            
}
/***Fin del elemento                                                        ***/
/***     Elemento: destructor
      Descripción: destruye la clase
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: clase inicializada  
   Post-Condicion: clase destruida                                          ***/
index::~index(){}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <
      Descripción: sobrecarga el operador binario <
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  campos:: operator< (campos t){
     return nombre<t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >
      Descripción: sobrecarga el operador binario >
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  campos:: operator> (campos t){
     return nombre>t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <=
      Descripción: sobrecarga el operador binario <=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  campos:: operator<= (campos t){
     return nombre<=t.nombre;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >=
      Descripción: sobrecarga el operador binario >=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  campos:: operator>= (campos t){
     return nombre>=t.nombre;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del ==
      Descripción: sobrecarga el operador binario ==
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  campos:: operator== (campos t){
     return nombre==t.nombre;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del !=
      Descripción: sobrecarga el operador binario !=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  campos:: operator!= (campos t){
     return nombre!=t.nombre;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <<
      Descripción: sobrecarga el operador binario <<
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
ostream& operator <<(ostream& out, const campos& t){
     out<<"Nombre: "<<t.nombre<<endl
        <<"Descripcion: "<<t.descripcion<<endl
        <<"Orden: "<<t.orden<<endl
        <<"Tipo: "<<t.tipo<<endl<<endl;
     return out;         
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <
      Descripción: sobrecarga el operador binario <
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  valores:: operator< (valores t){
     return valor<t.valor;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >
      Descripción: sobrecarga el operador binario >
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  valores:: operator> (valores t){
     return valor>t.valor;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <=
      Descripción: sobrecarga el operador binario <=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  valores:: operator<= (valores t){
     return valor<=t.valor;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >=
      Descripción: sobrecarga el operador binario >=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  valores:: operator>= (valores t){
     return valor>=t.valor;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del ==
      Descripción: sobrecarga el operador binario ==
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  valores:: operator== (valores t){
     return valor==t.valor;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del !=
      Descripción: sobrecarga el operador binario !=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  valores:: operator!= (valores t){
     return valor!=t.valor;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <<
      Descripción: sobrecarga el operador binario <<
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
ostream& operator <<(ostream& out, const valores& t){
     out<<t.valor;
     return out;         
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <
      Descripción: sobrecarga el operador binario <
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  datos:: operator< (datos t){
     return posicion<t.posicion;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >
      Descripción: sobrecarga el operador binario >
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  datos:: operator> (datos t){
     return posicion>t.posicion;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <=
      Descripción: sobrecarga el operador binario <=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  datos:: operator<= (datos t){
     return posicion<=t.posicion;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >=
      Descripción: sobrecarga el operador binario >=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  datos:: operator>= (datos t){
     return posicion>=t.posicion;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del ==
      Descripción: sobrecarga el operador binario ==
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  datos:: operator== (datos t){
     return posicion==t.posicion;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del !=
      Descripción: sobrecarga el operador binario !=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  datos:: operator!= (datos t){
     return posicion!=t.posicion;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <<
      Descripción: sobrecarga el operador binario <<
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
ostream& operator <<(ostream& out, const datos& t){
     out<<"Posicion #: "<<t.posicion<<endl<<endl;
     return out;         
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <
      Descripción: sobrecarga el operador binario <
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  index:: operator< (index t){
     return pdatos<t.pdatos;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >
      Descripción: sobrecarga el operador binario >
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  index:: operator> (index t){
     return pdatos>t.pdatos;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <=
      Descripción: sobrecarga el operador binario <=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  index:: operator<= (index t){
     return pdatos<=t.pdatos;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del >=
      Descripción: sobrecarga el operador binario >=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  index:: operator>= (index t){
     return pdatos>=t.pdatos;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del ==
      Descripción: sobrecarga el operador binario ==
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  index:: operator== (index t){
     return pdatos==t.pdatos;
}
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del !=
      Descripción: sobrecarga el operador binario !=
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
bool  index:: operator!= (index t){
     return pdatos!=t.pdatos;
}
/***Fin del elemento                                                        ***/
/***Fin del elemento                                                        ***/
/***     Elemento: sobrecarga del <<
      Descripción: sobrecarga el operador binario <<
          Entrada: clase
           Salida: T/F
    Pre-Condicion: clase inicializada  
   Post-Condicion: ninguna                                                  ***/
ostream& operator <<(ostream& out, const index& t){
     out<<"# de registro: "<<t.pdatos<<endl;
     out<<"valor del registro: "<<t.cosa<<endl<<endl;
     return out;         
}
/***Fin del elemento                                                        ***/
#endif
/***     Fin_Sección                                                        ***/
