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
#include "ADT_OBJ_DIN_LISTA.h"
#include "clases.h"
using namespace std;
/**** Programa Principal ******************************************************/
int main(){
    //Variables locales
    Lista<int> v;
    int e;
    int op=0;
	while (op!=12)
	{
		cout<<"________________________________________________________________________________"<<endl
		<<"                 M E T O D O S    D E    O R D E N A M I E N T O"<<endl
		<<"________________________________________________________________________________"<<endl<<endl
		<<"             ___________________________________________________________"<<endl
		<<"            |      [ 1 ]  Ordenar                                       |"<<endl
		<<"            |      [ 2 ]  Imprimir la lista                             |"<<endl
		<<"            |      [ 3 ]  Buscar un elemento en la lista                |"<<endl
		<<"            |      [ 4 ]  Eliminar un elemento de la lista              |"<<endl
		<<"            |      [ 5 ]  Eliminar el primer elemento de la lista       |"<<endl//***
		<<"            |      [ 6 ]  Eliminar el primer ultimo de la lista         |"<<endl
		<<"            |      [ 7 ]  Insertar en la primera posicion               |"<<endl//****
		<<"            |      [ 8 ]  Insertar en la ultima posicion                |"<<endl
		<<"            |      [ 9 ]  Eliminar todos los elementos de la lista      |"<<endl//***
		<<"            |      [ 10]  Insertar un elemento de forma ordenada        |"<<endl
		<<"            |      [ 11]  Longitud de la lista                          |"<<endl
		<<"            |      [ 12]  Salir                                         |"<<endl
        <<"            |___________________________________________________________|"<<endl<<endl
		<<"             Opcion a Elegir: ";
		
		cin>>op;
		system("cls");

		if (op==1)
		{
			v.ordenar();
			system("pause");
			system("cls");
		}

		if (op==2)
		{	
		    v.print();
		    system("pause");
		    system("cls");
		}
		
		if (op==3)
		{  
		  cout<<"Dame el elemento a buscar: "<<endl<<endl;
		  cin>>e;
		  v.search(e);
		  system("pause");
		  system("cls");
		}
		
		if (op==4)
		{
          cout<<"Dame el elemento a eliminar: "<<endl<<endl;
		  cin>>e;        
		  v.getElem(e);
		  system("pause");
		  system("cls");
		}

		if (op==5)
		{
			v.getIni(e);
			system("pause");
			system("cls");
		}
		if (op==6)
		{
			v.getFin(e);
			system("pause");
			system("cls");
		}
		if (op==7)
		{
          cout<<"Dame el elemento a insertar: "<<endl<<endl;
		  cin>>e;        
		  v.setIni(e);
		  system("pause");
		  system("cls");
		}
		if (op==8)
		{
          cout<<"Dame el elemento a insertar: "<<endl<<endl;
		  cin>>e;        
		  v.setFin(e);
		  system("pause");
		  system("cls");
		}
		if (op==9)
		{
		  v.eliminar();
		  system("pause");
		  system("cls");
		}
		if (op==10)
		{
          cout<<"Dame el elemento a insertar: "<<endl<<endl;
		  cin>>e;
		  v.setOrd(e);
		  system("pause");
		  system("cls");
		  
		}
        if (op==11)
		{
          cout<<"Esta es la longitud de la lista "<<v.length()<<endl<<endl;
		  system("pause");
		  system("cls");
		}		
    }
         
    system("pause");
    return 0;
    
}//Fin de la funcion principal


/***     Fin_Sección                                                        ***/
