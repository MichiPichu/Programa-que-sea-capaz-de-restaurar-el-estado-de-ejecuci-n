#include <iostream>
#include <conio.h>
#include "Paquete.h"
#include "Paqueteria.h"
#include <fstream> // Libreria para manipular el flujo de archivos (txt)

using namespace std;

int main()
{
    // VARIABLES
    char opc; // Opcion
    string nombreArchivo;
    //ifstream archivo; //ifstream es para leer

    mazo<Paquete> Milista;
    Paquete a, b; // a = objeto / b = aux


    // MENU
    while(1) //ciclo mientras para que el programa continue sin cerrarse
    {
        cout<<"\t--------------";
        cout<<"\n\t  Paqueteria"<<endl;
        cout<<"\t--------------";

        cout<<"\n\n------------------------------------";
        cout<<"\n 1) Agregar paquete\n 2) Eliminar paquete\n 3) Mostrar\n 4) Guardar\n 5) Recuperar\n 6) Salir\n";
        cout<<"------------------------------------";

        cout<<"\nIngrese un numero para elegir la opcion\n-> ";
        cin>>opc;

        system("cls");//limpiar pantalla

        switch(opc)
        {
        case '1':
            cout<<"\t------------------------";
            cout<<"\n\t    Agregar paquete"<<endl;
            cout<<"\t------------------------"<<endl<<endl;

            cin>>a;
            Milista.inserta(a,Milista.anterior(Milista.primero()));

            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            break;

        case '2':
            cout<<"\t--------------------";
            cout<<"\n\t  Eliminar paquete"<<endl;
            cout<<"\t--------------------"<<endl<<endl;

            Milista.elimina(Milista.primero());

            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");

            break;

        case '3':
            cout<<"\t---------------";
            cout<<"\n\t   Mostrar"<<endl;
            cout<<"\t---------------";

            cout<<"\n\nDatos de la paqueteria"<<endl;
            Milista.imprime();


            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            break;

        case '4':
            cout<<"\t-----------------";
            cout<<"\n\t    Guardar"<<endl;
            cout<<"\t-----------------"<<endl<<endl;

            cout<<"Ingrese el nombre de su respaldo"<<endl;
            fflush(stdin);
            getline(cin,nombreArchivo);
            nombreArchivo = nombreArchivo+".txt";
            fflush(stdin);



            Milista.guardar(nombreArchivo);
            cout<<"\n Respaldo guardado con exito encuentre su archivo .txt en la ruta de este programa"<<endl;

            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            break;

        case '5':
            cout<<"\t---------------";
            cout<<"\n\t    Recuperar"<<endl;
            cout<<"\t---------------"<<endl<<endl;

            cout<<"Ingrese el nombre de su respaldo"<<endl;
            fflush(stdin);
            getline(cin,nombreArchivo);
            nombreArchivo = nombreArchivo+".txt";
            fflush(stdin);


            Milista.recuperar(nombreArchivo);

/*
            archivo.open(nombreArchivo,ios::in); // Abrimos el archivo en modo lectura
            if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            return 0;
            }

            while(!archivo.eof()){ // Mientras no sea el final del archivo
            archivo >> b;
            //getline(archivo,texto); // Copiar lo del txt a texto
            //cout<<texto<<endl;
            //b=Milista.recuperar(nombreArchivo);
            Milista.inserta(b,Milista.ultimo());
            }
            Milista.elimina(Milista.ultimo());

            archivo.close(); // Cerramos el archivo txt
*/


            cout<<"\n Respaldo cargado con exito"<<endl;


            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            break;

        case '6':
            exit(EXIT_SUCCESS);
            break;

        default:
            cout<<"Opcion invalida"<<endl;
            cout<<"\nPresiona una tecla para continuar...";
            getch();
            system("cls");
        }

    }

    return 0;
}
