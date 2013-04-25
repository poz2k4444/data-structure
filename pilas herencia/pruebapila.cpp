/***     Sección: Declaración
     Descripción: La declaracion del programa                               ***/

/***     Programa: prueba.cpp
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 10/Febrero/2008 2:18p.m.
      Descripción: Prueba las estructuras                                   ***/


/****  Librerias **************************************************************/
#include <iostream>
#include <cstdlib>
#include "ADT_OBJ_DIN_PILAS.h"
using namespace std;
/**** Programa Principal ******************************************************/
int main(){
    //Variables locales
    Pila<int> v;
    int e;
    int op=0;
	while (op!=12)
	{
		cout<<"________________________________________________________________________________"<<endl
		<<"                                  ADT Pila"<<endl
		<<"________________________________________________________________________________"<<endl<<endl
		<<"             ___________________________________________________________"<<endl
		<<"            |      [ 1 ]  Imprimir                                      |"<<endl
		<<"            |      [ 2 ]  Meter elemento                                |"<<endl
		<<"            |      [ 3 ]  Sacar Elemento                                |"<<endl
		<<"            |      [ 4 ]  Salir                                         |"<<endl
        <<"            |___________________________________________________________|"<<endl<<endl
		<<"             Opcion a Elegir: ";
		
		cin>>op;
		system("cls");

		if (op==1)
		{
			v.imprimir(true);
			system("pause");
			system("cls");
		}

		if (op==2)
		{	
            cout<<"Dame el elemento a buscar: "<<endl<<endl;
            cin>>e;
		    v.meter(e);
		    system("pause");
		    system("cls");
		}
		
		if (op==3)
		{  
		  
		  v.sacar();
		  system("pause");
		  system("cls");
		}
		
    }
         
    system("pause");
    return 0;
    
}//Fin de la funcion principal


/***     Fin_Sección                                                        ***/
