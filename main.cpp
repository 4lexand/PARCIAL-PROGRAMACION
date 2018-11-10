
//Programa hecho por: Edwin Alexander Benitez Granados
//Carnet: BG18016

//Parcial de programacion I
//Ejercicio a resolver, ejercicio Numeroº2 ¨Sistema de colas¨
//El siguiente programa genera un sistema de colas para ususarios

#include <iostream> //Libreria principal de c++ de entras y salida de datos
#include <windows.h>//Libreria necesaria para repodrocir funciones de windows entre ellas reproducir audio
using namespace std;


/*                Estructura de los nodos de la cola
------------------------------------------------------------------------*/
struct nodo
{
    int nro;
    struct nodo *sgte;
};


/*                      Estructura de la cola
------------------------------------------------------------------------*/
struct cola
{
    nodo *delante;
    nodo *atras  ;
};


/*                        Encolar elemento
------------------------------------------------------------------------*/
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);

     aux->nro = valor;
     aux->sgte = NULL;

     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;

     q.atras = aux;        // puntero que siempre apunta al ultimo elemento

}

/*                        Desencolar elemento
------------------------------------------------------------------------*/
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;

     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux

     return num;
}

/*                        Mostrar Cola
------------------------------------------------------------------------*/
void muestraCola( struct cola q )
{
     struct nodo *aux;

     aux = q.delante;

     while( aux != NULL )
     {
            cout<<"   "<< aux->nro<<endl ;
            aux = aux->sgte;
     }
}

/*              Eliminar todos los elementos de la Cola
------------------------------------------------------------------------*/
void vaciaCola( struct cola &q)
{
     struct nodo *aux;

     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;

}

/*                        Menu de opciones
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t MENU PRINCIPAL DE REGISTRO DE TICKETS\n\n";
    cout<<" 1. ASIGNAR NUMERO                              "<<endl;
    cout<<" 2. TURNO DEL CLIENTE                            "<<endl;
    cout<<" 3. MOSTRAR LISTA DE ESPERA                        "<<endl;
    cout<<" 4. VACIAR LISTA DE ESPERA                           "<<endl;
    cout<<" 5. SALIR                                 "<<endl;

    cout<<"\n INGRESE OPCION: ";

}

/*                        Funcion Principal
------------------------------------------------------------------------*/
int main()
{
    struct cola q;

    q.delante = NULL;
    q.atras   = NULL;


    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop

    system("color 0b");

PlaySound(TEXT("inicio.wav"),NULL,SND_ASYNC);
  cout<<"-------------------------------------------------------------------"<<endl;
  cout<<"BIENVENIDO A NUESTROS SERVICIOS LA ASISTENTE LE ENTREGARA SU TICKET"<<endl;
  cout<<"-------------------------------------------------------------------"<<endl;
  system("pause");
  system("cls");
PlaySound(TEXT("paus.wav"),NULL,SND_ASYNC);

    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:
 				 system("cls");
                 cout<< "\n NUMERO A PASAR EN ESPERA: "; cin>> dato;

                 encolar( q, dato );
                 cout<<"\n\n\t\tTICKET NUMERO: " << dato << " ASIGNADO...\n\n"; //YA ESTA EN LISTA DE ESPERA

            break;

            case 2:
                PlaySound(TEXT("turnoCLie.wav"),NULL,SND_ASYNC);
 				 system("cls");
                 x = desencolar( q );
                 cout<<"\n\n\t\tTurno del cliente # "<< x <<" pasar a caja porfavor...\n\n";
            break;


            case 3:
 				 system("cls");
                 cout << "\n\n MOSTRANDO CLIENTE EN ESPERA\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tNo hay usuarios esperando...!"<<endl;
            break;


            case 4:
 				 system("cls");
                 vaciaCola( q );
                 cout<<"\n\n\t\tSe ha reiniciado su sistema...\n\n";
            break;

         }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=5);


    return 0;
}
