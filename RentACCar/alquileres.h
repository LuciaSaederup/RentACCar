#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED


#include "includess.h"
#include "vehiculos.h"


typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

//Estructura: Alquiler

typedef struct
{
    Fecha fechaInicio;
    Fecha fechaFin;
    Patente patente;
    Persona persona;
    float precioTotal;
    Vehiculo vehiculo;

} Alquiler;



void cargaUnAlquiler();
void mostrarAlquieres();
void muestraUnAlquiler(Alquiler a);
void mostrarAlquilerPorFecha();
Vehiculo verListaVehiculosDisponiblesySeleccionar();
void confirmarAlquiler(Alquiler alquiler);
void menuAlquileresCliente(Persona* persona);
void menuAlquileresAdmin(Persona* persona);
Alquiler* leerArchivoAlquileres(int* cantidad);





#endif // ALQUILER_H_INCLUDED
