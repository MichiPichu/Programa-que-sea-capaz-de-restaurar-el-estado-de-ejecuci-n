#include "Paquete.h"
#include <iostream>
#include <fstream> // Libreria para manipular el flujo de archivos (txt)
using namespace std;

///Implementacion

// Constructores de la clase paquete //

Paquete::Paquete(){}

Paquete::Paquete(const Paquete& p)
{
    id = p.id;
    origen = p.origen+"\n";
    destino = p.destino+"\n";
    peso = p.peso+"\n";
};
/*
//set
void Paquete::setid(const int& Id){
    id=Id;
}
void Paquete::setorigen(const string& Origen){
    origen=Origen;
}
void Paquete::setdestino(const string& Destino){
    destino=Destino;
}
void Paquete::setpeso(const string& Peso){
    peso=Peso;
}

//get
int Paquete::getid()const{
    return id;
}
string Paquete::getorigen()const{
    return origen;
}
string Paquete::getdestino()const{
    return destino;
}
string Paquete::getpeso()const{
    return peso;
}

*/
/*
//sobrecarga de operadores
Paquete & operator + (Paquete&p1, Paquete&p2){
    p1.id = p1.id + p2.id;
    p1.origen = p1.origen + p2.origen;
    p1.destino = p1.destino + p2.destino;
    p1.peso = p1.peso + p2.peso;

    return p1;
}

bool Paquete::operator==(const Paquete& p) const{
    return (id == p.id);
}
bool Paquete::operator!=(const Paquete& p) const{
    return (id != p.id);
}
bool Paquete::operator>(const Paquete& p) const{
    return (id > p.id);
}
bool Paquete::operator<(const Paquete& p) const{
    return (id < p.id);
}
bool Paquete::operator<=(const Paquete& p) const{
    return (id <= p.id);
}
bool Paquete::operator>=(const Paquete& p) const{
    return (id >= p.id);
}
*/

// Sobrecarga de operadores de entrada y salida

ostream& operator << (ostream& o,Paquete& p2)
{
    cout<<"\nId: ";
    o<<p2.id;
    cout<<"\n\nOrigen: ";
    o<<p2.origen;
    cout<<"\nDestino: ";
    o<<p2.destino;
    cout<<"\nPeso: ";
    o<<p2.peso;
    cout<<endl;
    return o;
}

istream& operator>>(istream& o,Paquete& p2)
{
    cout<<endl;
    cout<<"Ingresa id: ";
    o>>p2.id;
    fflush(stdin);
    cout<<"Ingresa origen: ";
    getline(o, p2.origen);
    fflush(stdin);
    cout<<"Ingresa destino: ";
    getline(o, p2.destino);
    fflush(stdin);
    cout<<"Ingresa peso: ";
    getline(o, p2.peso);
    fflush(stdin);
    return o;
}
