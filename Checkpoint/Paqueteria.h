#ifndef PAQUETERIA_H
#define PAQUETERIA_H
#include <iostream>
#include <exception>
#include <fstream> // Libreria para manipular el flujo de archivos (txt)
#include <string.h>
#include "Paquete.h"

using namespace std;

template<class T>
class mazo  //  LISTA SIMPLEMENTE LIGADA  //
{
    private:
        class Nodo{  // CLASE NODO //;
            private:
                T dato;
                Nodo *sig; // Sig = Siguiente
            public:
                Nodo():sig(nullptr){};
                friend class mazo; // Nodo y Paqueteria Clases amigas
                };

        Nodo* ancla; // cabecera


        bool posicionValida( Nodo* )const;

    public:
        class Exception : public std::exception{
            private:
                std::string msg;
                public:
                    explicit Exception(const char* message) : msg(message){}

                    explicit Exception(const std::string& message) : msg(message){}

                    virtual ~Exception() throw (){}

                    virtual const char* what() const throw(){
                        return msg.c_str();
                        }
                };


        mazo():ancla(nullptr){}; //Nulo = nullptr / incializar en nulo
        virtual ~mazo(){
        anula();
        };
        //Paqueteria():cont(0) {};// Inicializa

        // Metodos
        bool vacia()const; //no modifica atributos de la clase constante
        void inserta(T, Nodo*); //Puntero nodo //inserta al inicio
        bool elimina(Nodo*);
        Nodo* anterior(Nodo*)const;
        Nodo* primero()const;
        Nodo* ultimo()const;
        Nodo* siguiente(Nodo*)const;
        Nodo* localiza(T)const;
        void recupera(Nodo*)const;
        void anula();
        void imprime()const;
        void ordenar();
        void guardar(string)const;
        void recuperar(string);
};



//   IMPLEMENTACION   //
/*
Paqueteria::Paqueteria(){
    anula();
}
*/
template <class T>
bool mazo<T>::posicionValida(Nodo* pos) const {
    Nodo* aux(ancla);

    while(aux != nullptr){
        if(aux == pos){
            return true;
        }

        aux = aux ->sig;
    }
    return false;
}


template<class T>
bool mazo<T>::vacia()const{
    if(ancla == nullptr)
        return true;
    return false;
}

template<class T>
void mazo<T>::inserta(T elem, Nodo* pos)
{
    Nodo* aux=new Nodo; //Crea nuevo nodo con new
    aux -> dato = elem; //Pase por valor
    if(pos==nullptr) // Inserta al principio
    {
        aux -> sig = ancla;
        ancla = aux;
        cout<< "\nPaquete registrado exitosamente :)";
    }
    else // Inserta en cualquier otro lugar
    {
        aux -> sig = pos -> sig;
        pos -> sig = aux;
        cout<< "\nPaquete registrado exitosamente";
    }

}

template<class T>
bool mazo<T>::elimina(Nodo* pos){
    if(vacia()){
        cout<<"\nPaqueteria vacia";
        return false;
    }
    else
    if(pos==nullptr) // Valida posicion
    {
        cout<<"\nPaquete no registrado";
        return false;
    }
    if(pos==ancla) // Elimina al principio
    {
        ancla=ancla->sig;
        cout<<"\nEl paquete que se encontraba al inicio ha sido eliminado...";

    }
    else // Elimina en cualquier otro lugar
        anterior(pos)->sig=pos->sig;
    //free
    delete(pos);
    //cout<<"\nSocio eliminado";
    return true;
}

template<class T>
typename mazo<T>::Nodo* mazo<T>::anterior(Nodo* pos)const
{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    Nodo* aux=ancla;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
typename mazo<T>::Nodo* mazo<T>::primero()const
{
    return ancla;
}
template<class T>
typename mazo<T>::Nodo* mazo<T>::ultimo()const
{
    if(vacia()){
        return nullptr;
    }
    Nodo* aux=ancla;
    while(aux->sig!=nullptr){ //Recorre
        aux=aux->sig;
    }
    return aux;
}

template<class T>
typename mazo<T>::Nodo* mazo<T>::siguiente(Nodo* pos)const{
    if(vacia() || pos==nullptr)
        return nullptr;
    return pos->sig;
}

template<class T>
typename mazo<T>::Nodo* mazo<T>::localiza(T elem)const{
    Nodo* aux=ancla;
    while(aux!=nullptr && aux->dato!=elem){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
void mazo<T>::recupera(Nodo* pos)const{
    if(!posicionValida(pos)){
        throw Exception ("Posicion invalida");
    }
    cout<<"\nPaquete encontrado: \n"<<pos->dato;
        //Excepciones
}

template<class T>
void mazo<T>::anula(){
    Nodo* aux;
    while(ancla != nullptr){
        aux= ancla;
        ancla= ancla->sig;
        delete(aux);
    }
}

template<class T>
void mazo<T>::imprime()const{
    if(vacia()){
        cout<<"\nPaqueteria vacia";
        return;}

    Nodo* aux =ancla;
    while(aux!=nullptr){
        std::cout<<aux->dato;
        aux=aux->sig;
    }
}

template<class T>
void mazo<T>::ordenar(){ // Metodo de burbuja
   Nodo *j = ancla, *temp = nullptr;
    T aux;
    if (ancla == nullptr) {
        return;
    }else {
        while (j != nullptr) {
            temp = j->sig;
            while (temp != nullptr) {
            if (j->dato > temp->dato) { // intercambio
                aux = j->dato;
                j->dato = temp->dato; //j+1
                temp->dato = aux;
            }
            temp = temp->sig;
        }
        j = j->sig;
        }
    }
}

template<class T>
void mazo<T>::guardar(string nomArch)const{
   // Crear el archivo de texto y escribir
    ofstream archivo; //ofstream es para escribir

    archivo.open(nomArch.c_str(),ios::out); // .c_str() es para copiar el nombre del archivo

    Nodo* aux =ancla;
    while(aux!=nullptr){
        archivo<<aux->dato<<"\n";
        aux=aux->sig;
    }

    //archivo<<txt; //Ingresar texto en mi archivo txt

    archivo.close(); // Cerrar el archivo

}

template<class T>
void mazo<T>::recuperar(string nomArch){
    ifstream archivo; //ifstream es para leer
    Paquete b;

    archivo.open(nomArch,ios::in); // Abrimos el archivo en modo lectura
            if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            return ;
            }

            while(!archivo.eof()){ // Mientras no sea el final del archivo
            archivo >> b;
            //getline(archivo,texto); // Copiar lo del txt a texto
            //cout<<texto<<endl;
            //b=Milista.recuperar(nombreArchivo);
            inserta(b,ultimo());
            }
            elimina(ultimo());

            archivo.close(); // Cerramos el archivo txt
}

#endif // PAQUETERIA_H
