#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27
#define RUTAVEHICULOS "Vehiculos.bin"

//Estructura: Patente
typedef struct
{
    char letras[3];
    char numeros[3];
} Patente;

//Estructura: Vehiculo

typedef struct
{
    char marca[20];
    char modelo[20];
    int anio;
    int kms;
    float precioDeAlquilerDiario;
    char tipoVehiculo[20];
    Patente patente;

// 1-Auto,  2-Camioneta, 3-Utilitario

    int disponibilidad;

// 1-disponible, 0-no disponible
} Vehiculo;

void menuVehiculos();
void cargaEstructuraAtuos();
void muestraVehiculos();
void muestraVehiculosDisponibles();
void modificarVehiculo();
void mostrarAuto(Vehiculo v);
void busquedaPorPatente();

#endif // VEHICULOS_H_INCLUDED
