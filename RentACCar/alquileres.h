#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include <string.h>
#include <conio.h>
#define ESC 27
#include "vehiculos.h"

#define RUTAALQUILERES "ARCHIVOALQUILRES.bin"



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
    int dniCliente;
    float precioTotal;
} Alquiler;

Alquiler cargaUnAlquiler();
void regitrarAlquier();
void muestraUnAlquiler(alquiler);
void mostrarAlquieres();

#endif // ALQUILERES_H_INCLUDED
