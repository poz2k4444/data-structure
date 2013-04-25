/***     Sección: Declaración
     Descripción: La declaracion del programa                               ***/

/***     Programa: prueba.cpp
    Programa Base: Ninguno
      Programador: Francisco Josué López Aguilar
            Fecha: 10/Febrero/2008 2:18p.m.
      Descripción: Prueba las estructuras                                   ***/


/****  Librerias **************************************************************/
#include <iostream>
#include "ADT_OBJ_DIN_LISTA.h"
#include "ADT_OBJ_DIN_LISTAC.h"
#include "ADT_OBJ_DIN_LISTADEC.h"
#include "ADT_OBJ_DIN_AVL.h"
#include "Tabla.h"
#include "clases.h"
#include "nodos.h"
#include <string>
using namespace std;
/**** Programa Principal ******************************************************/
int main(){
    //Variables locales
    string nombreT;
    Lista<Tabla> v;
    ListaDEC<campos> *aux;
    Lista<datos> *aux2;
    Lista<valores> *aux3;
    AVL<index> *aux4;
    NodoAVL<index> *i;
    Nodo<Tabla> *n;
    NodoC<campos> *c;
    Nodo<datos> *d;
    Nodo<valores> *va;
    campos lcampos;
    campos *cam;
    Tabla e;
    Tabla *t;
    datos dat;
    datos *dat1;
    valores val;
    valores *val1;
    index ind;
    index *ind1;
    int op=0;
	while (op!=5)
	{
		cout<<"________________________________________________________________________________"<<endl
		<<"                                    BASE DE DATOS"<<endl
		<<"________________________________________________________________________________"<<endl<<endl
		<<"             ___________________________________________________________"<<endl
		<<"            |      [ 1 ]  Imprimir Tablas                               |"<<endl
		<<"            |      [ 2 ]  Crear una Tabla                               |"<<endl
		<<"            |      [ 3 ]  Modificar una tabla                           |"<<endl
		<<"            |      [ 4 ]  Eliminar una tabla                            |"<<endl
		<<"            |      [ 5 ]  Salir                                         |"<<endl
        <<"            |___________________________________________________________|"<<endl<<endl
		<<"             Opcion a Elegir: ";
		
		cin>>op;
		int num = 1;
		system("cls");

		if (op==1)
		{	
		    v.print();
		    system("pause");
		    system("cls");
		}
		
		if (op==3)
		{
          cout<<"¿Que tabla desea modificar?: ";
          cin>>nombreT;
          n = v.search(nombreT);
          t = &n->dato;
          if(n!=NULL){
              
              int opc;
         	  while (opc!=9)
           	  {
		        cout<<"________________________________________________________________________________"<<endl
		            <<"                         Modificar la tabla "<<t->nombre<<endl
	             	<<"________________________________________________________________________________"<<endl<<endl
	              	<<"             ___________________________________________________________"<<endl
		            <<"            |      [ 1 ]  Modificar nombre                              |"<<endl
		            <<"            |      [ 2 ]  Modificar descripción                         |"<<endl
		            <<"            |      [ 3 ]  Modificar tipo                                |"<<endl
                 	<<"            |      [ 4 ]  Modificar los campos                          |"<<endl
                 	<<"            |      [ 5 ]  Crear un registro nuevo                       |"<<endl
		            <<"            |      [ 6 ]  Eliminar un registro                          |"<<endl
		            <<"            |      [ 7 ]  Imprimir los registros                        |"<<endl
		            <<"            |      [ 8 ]  Modificar un registro                         |"<<endl
		            <<"            |      [ 9 ]  Index                                         |"<<endl
		            <<"            |      [ 0 ]  Salir                                         |"<<endl
                    <<"            |___________________________________________________________|"<<endl<<endl
	            	<<"             Opcion a Elegir: ";
		
	           cin>>opc;
	           n = v.search(nombreT);
               t = &n->dato;
		       system("cls");
               
	           if (opc==1)
		       {
                  n = v.search(nombreT);
                  t = &n->dato;        	
		          string n;
                  cout<<"Dame el nuevo nombre de la tabla: ";
                  cin>>n;
                  t->nombre = n;
                  nombreT = n;
		          system("pause");
		          system("cls");
		       }
               if (opc==2)
		       {	
                  n = v.search(nombreT);
                  t = &n->dato;
		          string n;
                  cout<<"Dame una descripcion nueva de la tabla: ";
                  cin>>n;
                  t->descripcion = n;
		          system("pause");
		          system("cls");
		       }
               if (opc==3)
		       {
                  n = v.search(nombreT);
                  t = &n->dato;        	
		          string ti;
                  cout<<"Dame el nuevo tipo de la tabla: ";
                  do{
                      cout<<endl<<"Tipo de la tabla(fila/pila/lista): ";
                      cin>>ti;
                  }while(ti!="FILA" && ti!="fila" && ti!="PILA" && ti!="pila" && ti!="LISTA" && ti!="lista");
		          system("pause");
		          system("cls");
		       }
               if (opc==4)
		       {
                  n = v.search(nombreT);
                  t = &n->dato;        	
		          aux = &t->lcampos;
		          int opci=0;
         	      while (opci!=5)
           	      {
		               cout<<"________________________________________________________________________________"<<endl
		                   <<"             Modificar los campos de la tabla: "<<t->nombre<<endl
	             	       <<"________________________________________________________________________________"<<endl<<endl
	              	       <<"             ___________________________________________________________"<<endl
		                   <<"            |      [ 1 ]  Imprimir los campos                           |"<<endl
		                   <<"            |      [ 2 ]  Nuevo campo                                   |"<<endl
		                   <<"            |      [ 3 ]  Modificar los valores de un campo             |"<<endl
                 	       <<"            |      [ 4 ]  Borrar un campo                               |"<<endl
		                   <<"            |      [ 5 ]  Salir                                         |"<<endl
                           <<"            |___________________________________________________________|"<<endl<<endl
	            	       <<"             Opcion a Elegir: ";
		
                      cin>>opci;
                      n = v.search(nombreT);
                      t = &n->dato;
		              system("cls");

	                 if (opci==1)
		             {	
		                  aux->print();
		                  system("pause");
		                  system("cls");
                     }
                     if (opci==2)
		             {	
		                  string n,d,o,t;
                          cout<<"Dame el nombre del nuevo campo: ";
                          cin>>n;
                          lcampos.nombre = n;
                          cout<<"Dame una breve descripcion: ";
                          cin>>d;
                          lcampos.descripcion = d;
                          cout<<"Dame el orden del campo: ";
                          cin>>o;
                          lcampos.orden = o;
                          cout<<"Dame el tipo del campo: ";
                          cin>>t;
                          lcampos.tipo = t;
                          aux->setOrd(lcampos);
		                  system("pause");
		                  system("cls");
		             }
                     if (opci==3)
		             {	
                          string nombre; 
                          cout<<"¿Que campo desea modificar?: \n";
                          cin>>nombre;
                          c = aux->search(nombre);
                          cam = &c->dato;
                          if(c!=NULL){
                          int opcio;
		                       while (opcio!=6)
           	                   {
		                           cout<<"________________________________________________________________________________"<<endl
		                               <<"             Modificar los valores del campo: "<<cam->nombre<<", de la tabla: "<<t->nombre<<endl
	             	                   <<"________________________________________________________________________________"<<endl<<endl
	              	                   <<"             ___________________________________________________________"<<endl
		                               <<"            |      [ 1 ]  Imprimir los valores actuales del campo       |"<<endl
		                               <<"            |      [ 2 ]  Modificar el nombre                           |"<<endl
		                               <<"            |      [ 3 ]  Modificar la descripcion                      |"<<endl
                 	                   <<"            |      [ 4 ]  Modificar el orden                            |"<<endl
		                               <<"            |      [ 5 ]  Modificar el tipo                             |"<<endl
		                               <<"            |      [ 6 ]  Salir                                         |"<<endl
                                       <<"            |___________________________________________________________|"<<endl<<endl
	            	                   <<"             Opcion a Elegir: ";
                                    cin>>opcio;
                                    n = v.search(nombreT);
                                    t = &n->dato;
                                    system("cls");
                                    if (opcio==1)
		                            {	
		                                 cout<<"Nombre: "<<cam->nombre<<endl
		                                     <<"Descripcion: "<<cam->descripcion<<endl
                                             <<"Orden: "<<cam->orden<<endl
                                             <<"Tipo: "<<cam->tipo<<endl;
		                                 system("pause");
		                                 system("cls");
                                    }
                                    if (opcio==2)
		                            {	
		                                 string n;
                                         cout<<"El nuevo nombre del campo: "<<endl;
		                                 cin>>n;
		                                 cam->nombre = n;
		                                 system("pause");
		                                 system("cls");
                                    }
                                    if (opcio==3)
		                            {	
		                                 string n;
                                         cout<<"La nueva descripcion del campo: "<<endl;
		                                 cin>>n;
		                                 cam->descripcion = n;
		                                 system("pause");
		                                 system("cls");
                                    }
                                    if (opcio==4)
		                            {	
		                                 string n;
                                         cout<<"El nuevo orden del campo: "<<endl;
		                                 cin>>n;
		                                 cam->orden = n;
		                                 system("pause");
		                                 system("cls");
                                    }
                                    if (opcio==5)
		                            {	
		                                 string n;
                                         cout<<"El nuevo tipo del campo: "<<endl;
		                                 cin>>n;
		                                 cam->tipo = n;
		                                 system("pause");
		                                 system("cls");
                                    }
		                            
		                   
                               }    
                          }
                     }
                     if (opci==4)
		             {	
                          string nombrecampo, des;       
		                  cout<<"¿Que campo desea eliminar: ";
		                  cin>>nombrecampo;
		                  c = aux->search(nombrecampo);
		                  if(c!=NULL){
		                      cout<<"Seguro que quiere eliminar este campo[S/N]: ";
		                      cin>>des;
		                      if(des == "S" || des == "s"){
                                   aux->getElem(c->dato);
                                   cout<<"Se ha eliminado correctamente el campo"<<endl;  
                              }else{
                                   cout<<"No ha habido cambios"<<endl;      
                              }
                          }else{
                              cout<<"No hay ningún campo con ese nombre"<<endl;      
                          }
		                  system("pause");
		                  system("cls");
		             }    
               }
		          system("pause");
		          system("cls");
		       }
               if (opc==5)
		       {
                  n = v.search(nombreT);
                  t = &n->dato;
                  aux = &t->lcampos;
		          aux2 = &t->ldatos;
		          cam = &aux->dato;
		          dat.posicion = num;
                  aux2->setFin(dat);
                  d = aux2->search(dat);
                  dat1 = &d->dato;
                  aux3 = &dat1->lvalor;
                  c = aux->ini();
                  cout<<"En la tabla: "<<t->nombre<<", se creara el registro numero: "<<dat1->posicion<<endl;
                  if(c!=NULL){
		              do{
                          string z;   
                          cam = &c->dato; 
                          cout<<cam->nombre<<": "<<endl;
                          cin>>z;
                          val.valor = z;  
                          aux3->setFin(val);
                          c = c->sig;  
                      }while(c!=aux->ini());
                  }else{
                      cout<<"No hay campos, no se puede crear un registro... por favor crea un campo."<<endl;      
                  }
                  num++;
		          system("pause");
		          system("cls");
		       }
		       if (opc==6)
		       {
                  n = v.search(nombreT);
                  t = &n->dato;        	
                  int nom; 
		          aux2 = &t->ldatos;
                  d = aux2->ini();
                  while(d!=NULL){
                     dat1 = &d->dato;
                     aux3 = &dat1->lvalor;
                     va = aux3->ini();
                     val1 = &va->dato;
                     cout<<"contenido del regitro #"<<dat1->posicion<<"  ";
                     cout<<val1->valor<<endl;
                     d = d->sig;              
                  }
                  cout<<"¿Que registro desea borrar[numero de registro]: ";
                  cin>>nom;
                  d = aux2->search(nom);
                  if(d!=NULL){
                      dat1 = &d->dato; 
                      aux3 = &dat1->lvalor;
                      aux3->~Lista();   
                      aux2->getElem(nom);
                      cout<<"Se ha eliminado el registro"<<endl;
                  }else{
                      cout<<"No existe dicho registro"<<endl;      
                  }
		          system("pause");
		          system("cls");
		       }
		       if (opc==7)
		       {
                  cout<<nombreT<<endl;        	
                  n = v.search(nombreT);
                  t = &n->dato;
                  aux = &t->lcampos;
		          aux2 = &t->ldatos;
		          c = aux->ini();
                  d = aux2->ini();
                  if(d!=NULL){
                  cout<<"# de Reg.\t";
                  do{
                      cam = &c->dato;           
                      cout<<cam->nombre<<"\t";
                      c = c->sig;             
                  }while(c!=aux->ini());
                  cout<<endl;
                  cout<<"_______________________________________________________";
                  cout<<endl<<endl;
                  while(d!=NULL){
                     dat1 = &d->dato;
                     aux3 = &dat1->lvalor;
                     cout<<"   "<<dat1->posicion<<"\t\t";
                     aux3->print();
                     cout<<endl;
                     d = d->sig;      
                  }
                  }else{
                      cout<<endl<<"No hay registros..."<<endl;      
                  }
		          system("pause");
		          system("cls");
		       }
		       if (opc==8)
               {
                  int numR;
                  n = v.search(nombreT);
                  t = &n->dato;        	 
		          aux2 = &t->ldatos;
		          cout<<"Que registro desea modificar??: ";
		          cin>>numR;
		          d = aux2->search(numR);
		          if(d!=NULL){
                      string valM;
                      dat1 = &d->dato;        
                      aux3 = &dat1->lvalor;
                      aux3->print();
                      cout<<endl;
                      cout<<"Qué valor desea modificar?: ";
                      cin>>valM;
                      va = aux3->search(valM);
                      if(va!=NULL){
                           string nVal;
                           val1 = &va->dato;
                           cout<<"Escriba el nuevo valor que contendrá este registro: ";
                           cin>>nVal;
                           val1->valor = nVal;  
                      }else{
                           cout<<"Este registro no tiene es valor..."<<endl;      
                      }
                  }else{
                      cout<<"Ese registro no existe..."<<endl;      
                  }
                  system("pause");
		          system("cls");
               }
               if(opc==9){
                  int op2;
         	      while (op2!=5)
           	      {
		            cout<<"________________________________________________________________________________"<<endl
		                <<"                         Index de la tabla "<<t->nombre<<endl
	             	    <<"________________________________________________________________________________"<<endl<<endl
	              	    <<"             ___________________________________________________________"<<endl
		                <<"            |      [ 1 ]  Crear index                                   |"<<endl
		                <<"            |      [ 2 ]  Modificar index                               |"<<endl
		                <<"            |      [ 3 ]  Eliminar el index                             |"<<endl
                 	    <<"            |      [ 4 ]  Imprimir index                                |"<<endl
		                <<"            |      [ 5 ]  Salir                                         |"<<endl
                        <<"            |___________________________________________________________|"<<endl<<endl
	            	    <<"             Opcion a Elegir: ";
		
	                 cin>>op2;
	                 n = v.search(nombreT);
                     t = &n->dato;
                     system("cls");
                     if(op2==1){
                          string nomI;      
                          aux4 = &t->aindex;
                          aux2 = &t->ldatos;
                          d = aux2->ini();
                          cout<<"Con que campos quieres que se haga el index: ";
                          cin>>nomI;
                          dat1 = &d->dato;
                          aux3 = &dat1->lvalor;
                          va = aux3->search(nomI);
                          if(va != NULL){
                              while(d!=NULL){
                                 dat1 = &d->dato;
                                 ind.pdatos = dat1->posicion;
                                 aux3 = &dat1->lvalor;
                                 va = aux3->search(nomI);
                                 val1 = &va->dato;
                                 ind.cosa = val1->valor;
                                 aux4->meter(ind);
                                 d = d->sig;
                              }  
                              aux4->inord();
                          }  
                          system("cls");        
                          system("pause");  
                     }
                     if(op2==2){
                          aux4 = &t->aindex;
                          aux4->~AVL();
                          string nomI;      
                          aux4 = &t->aindex;
                          aux2 = &t->ldatos;
                          d = aux2->ini();
                          cout<<"Con que campos quieres que se haga el index: ";
                          cin>>nomI;
                          dat1 = &d->dato;
                          aux3 = &dat1->lvalor;
                          va = aux3->search(nomI);
                          if(va != NULL){
                              while(d!=NULL){
                                 dat1 = &d->dato;
                                 ind.pdatos = dat1->posicion;
                                 aux3 = &dat1->lvalor;
                                 va = aux3->search(nomI);
                                 val1 = &va->dato;
                                 ind.cosa = val1->valor;
                                 aux4->meter(ind);
                                 d = d->sig;
                              }  
                              aux4->inord();
                          }
                          system("cls");        
                          system("pause"); 
                     }
                     if(op2==3){
                          aux4 = &t->aindex;
                          aux4->~AVL();     
                          system("cls");        
                          system("pause");
                     }
                     if(op2==4){
                          aux4 = &t->aindex;
                          aux4->inord();      
                          system("cls");        
                          system("pause");
                     }
                   }
		           system("cls");        
                   system("pause");
		          
               }
             }  
             
           
          }else{
               cout<<"No existe una tabla con ese nombre"<<endl;      
          }
		  system("pause");
		  system("cls");
  }

		if (op==2)
		{
          
          string n,d,t;
          cout<<"Dame el nombre de la tabla: ";
          cin>>n;
          cout<<endl<<"Describe dicha tabla: ";
          cin>>d;
          do{
               cout<<endl<<"Tipo de la tabla(fila/pila/lista): ";
               cin>>t;
          }while(t!="FILA" && t!="fila" && t!="PILA" && t!="pila" && t!="LISTA" && t!="lista");
          e.nombre = n;
		  e.descripcion = d;
		  e.tipo = t;
		  v.setOrd(e);
		  system("pause");
		  system("cls");
		  
		}
        if (op==4)
		{
          string nom, des;
          cout<<"¿Que tabla desea eliminar?: ";
          cin>>nom;
          n = v.search(nom);
          
          if(n!=NULL){
              t = &n->dato;
              
              cout<<"Esta seguro de eliminar dicha tabla[S/N]: ";
              cin>>des;
              if(des == "S" || des == "s"){
                   aux = &t->lcampos;
                   aux2 = &t->ldatos;
                   aux4 = &t->aindex;
                   d = aux2->ini();
                   while(d!=NULL){
                      dat1 = &d->dato;
                      aux3 = &dat1->lvalor;
                      aux3->~Lista();
                      cout<<endl;
                      d = d->sig;              
                   }
                   aux3 =NULL;
                   aux2->~Lista();
                   aux->~ListaDEC();
                   aux = NULL;
                   aux2 =NULL;
                   aux4->~AVL();
                   aux4=NULL;
                   v.getElem(n->dato);  
                   cout<<"Se ha eliminado dicha tabla"<<endl;
              }else{
                   cout<<"No hay cambios en la base de datos"<<endl;      
              }
          }else{
              cout<<"La tabla no existe"<<endl;      
          }
		  system("pause");
		  system("cls");
		  
		}		
    }
         
    system("pause");
    return 0;
    
}//Fin de la funcion principal


/***     Fin_Sección                                                        ***/
