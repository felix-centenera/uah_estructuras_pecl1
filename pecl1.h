#ifndef PECL1_H_INCLUDED
#define PECL1_H_INCLUDED
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
#define Nc 8        // Número de cajas por furgoenetas.
#define Nrep 10     // Número de cajas repartidas entre camiones.
#define Ncam 20     // Número de cajas en camión.

using namespace std;

void printMenu(int &opcion);
string generadorIDCaja(string origen);
string randomProductos ();
string fechaCaducidad(string producto);
bool aleatorio_50_50();

struct Caja
{
    string Id;
    string CentroRef;
    string Contenido;
    string FechaConsumo;
};

struct Estadistica
{
    int marruecosDestino;
    int libiaDestino;
    int greciaDestino;
    int daganzoOrigen;
    int mecoOrigen;
    int loechesOrigen;
    int torrejonOrigen;
    int harina;
    int pasta;
    int galletas;
    int legumbres;
    int leche;
    int medicinas;
    int higiene;
    int agua;
    int aceite;
    int sal;
    int azucar;
    int latas_cons;
    int iluminacion;
    int herramientas;
    int combustible;
    int tiendas_camp;
    int ropa;
    int mantas;
    int limpieza;

};

class Nodo
{
private:
    Caja valor;
    Nodo *siguiente;
    friend class Cola;
    friend class Pila;
public:
    Nodo(Caja v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;


class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(Caja v);
    Caja desencolar();
    Caja mostrarPrimero();
    bool vacia();
    int contarElementosCola();
private:
    pNodo frente, final;
};


class Pila
{
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(Caja v);
    Caja desapilar();
    Caja mostrarCima();
    bool vacia();
    int contarElementosPila();
};

Pila *copiarPila(Pila *pilaOriginal);
void simulacionCentroRecogida(int numSimulaciones,string CentroRegociga,Pila* furgoneta,Estadistica *estadistica);
void actualizareEstadisitcas(Caja caja, Estadistica* estadistica);
void printDatosCamiones(Pila* camion1,Pila* camion2,Pila* camion3);
void printDatosFurgonetas(Pila* furgoneta1,Pila* furgoneta2,Pila* furgoneta3, Pila* furgoneta4);
void printDatosCentroClasificacion(Cola* centroDeClasificacion1);
Pila* invertirPila(Pila* pilaOriginal);
void printEstadisticas(Estadistica* estadistica);
Cola* copiarCola(Cola* colaOriginal);
#endif // PECL1_H_INCLUDED
