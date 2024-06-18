#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include <string.h>
#include <conio.h>
#define ESC 27
#include "vehiculos.h"
#include "persona.h"
#define RUTAALQUILERES "Alquileres.bin"



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
void regitrarAlquier();
void muestraUnAlquiler(Alquiler alquiler);
void mostrarAlquieres();
void mostrarAlquilerPorFecha();
Vehiculo verListaVehiculosDisponiblesySeleccionar();
void confirmarAlquiler(Alquiler alquiler);
void menuAlquileresCliente();
void menuAlquileresAdmin();
#endif // ALQUILERES_H_INCLUDED
