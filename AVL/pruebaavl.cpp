/***     Sección: Declaración
     Descripción: La declaracion del programa                               ***/

/***     Programa: pruebaavl.cpp
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 10/Abril/2009 2:18p.m.
      Descripción: Prueba el árbol                                          ***/


/****  Librerias **************************************************************/
#include <iostream>
#include <cstdlib>
#include "ADT_OBJ_DIN_AVL.h"
using namespace std;
/**** Programa Principal ******************************************************/
int main(){
    //Variables locales
    AVL<int> v;
    int e;
    int op=0;
	while (op!=12)
	{
		cout<<"________________________________________________________________________________"<<endl
		<<"                                 ADT Arbol AVL"<<endl
		<<"________________________________________________________________________________"<<endl<<endl
		<<"             ___________________________________________________________"<<endl
		<<"            |      [ 1 ]  Meter elemento                                |"<<endl
		<<"            |      [ 2 ]  Sacar elemento                                |"<<endl
		<<"            |      [ 3 ]  Inorden                                       |"<<endl
		<<"            |      [ 4 ]  Preorden                                      |"<<endl
		<<"            |      [ 5 ]  Postorden                                     |"<<endl
		<<"            |      [ 6 ]  Inorden Inv.                                  |"<<endl
		<<"            |      [ 7 ]  Preorden Inv                                  |"<<endl
		<<"            |      [ 8 ]  Postorden Inv                                 |"<<endl
		<<"            |      [ 9 ]  Hijos                                         |"<<endl
		<<"            |      [ 10 ]  Camino                                       |"<<endl
		<<"            |      [ 11 ]  Altura                                       |"<<endl
		<<"            |___________________________________________________________|"<<endl<<endl
		<<"             Opcion a Elegir: ";
		
		cin>>op;
		system("cls");

		if (op==1)
		{
                  
            cout<<"Dame un numero a insertar ";          
            cin>>e;           
			v.meter(e);
			system("pause");
			system("cls");
		}
		if (op==2)
		{
                  
            cout<<"Dame un numero a sacar ";          
            cin>>e;           
			v.sacar(e);
			system("pause");
			system("cls");
		}
		if (op==3)
		{            
			v.inord();
			system("pause");
			system("cls");
		}
		if (op==4)
		{
           v.preord();
			system("pause");
			system("cls");
		}
		if (op==5)
		{
            v.postord();
			system("pause");
			system("cls");
		}
		if (op==6)
		{
                  
            v.inordinv();
			system("pause");
			system("cls");
		}
		if (op==7)
		{
                  
            v.preordinv();
			system("pause");
			system("cls");
		}
		if (op==8)
		{
                  
            v.postordinv();
			system("pause");
			system("cls");
		}
		if (op==9)
		{
                  
            cout<<"Dame el número del que quieras los hijos ";          
            cin>>e;           
			v.hijos(e);
			system("pause");
			system("cls");
		}
		if (op==10)
		{
                  
            cout<<"Dame un numero para imprimir el camino recorrido ";          
            cin>>e;           
			v.camino(e);
			system("pause");
			system("cls");
		}
		if (op==11)
		{
                  
            cout<<"La altura"<<endl;          
                       
			cout<<v.alto();
			system("pause");
			system("cls");
		}
		
    }
         
    system("pause");
    return 0;
    
}//Fin de la funcion principal


/***     Fin_Sección                                                        ***/
