#ifndef PAQUETE_H
#define PAQUETE_H

#include <iostream>
#include <fstream> // Libreria para manipular el flujo de archivos (txt)

using namespace std;

class Paquete
{
    private://Atributos
        int id;
        string origen;
        string destino;
        string peso;

    public://Constructor
        Paquete();
        Paquete(const Paquete& p);
        //Setters
        /*
        void setid(const int& Id);
        void setorigen(const string& Origen);
        void setdestino(const string& Destino);
        void setpeso(const string& Peso);

        //Getters
        int getid()const;
        string getorigen()const;
        string getdestino()const;
        string getpeso()const;*/

/*
        //sobrecarga de operadores
        friend Paquete & operator + (Paquete&,Paquete&);
        bool operator == (const Paquete&)const;
        bool operator != (const Paquete&)const;
        bool operator > (const Paquete&)const;
        bool operator < (const Paquete&)const;
        bool operator <= (const Paquete&)const;
        bool operator >= (const Paquete&)const;
*/
        //sobrecarga de operador de entrada y salida
        friend ostream& operator <<(ostream& ,Paquete&);
        friend istream& operator >>(istream&, Paquete&);
};

#endif // PAQUETE_H
