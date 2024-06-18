#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27
#define RUTAVEHICULOS "Vehiculos.bin"
#define MAX_TIPO_VEHIC 20
#define RUTAVEHICULOSTEMPORAL "VehiculosTemporal.bin"

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
    char tipoVehiculo[MAX_TIPO_VEHIC];
    Patente patente;

// 1-Auto,  2-Camioneta, 3-Utilitario

    int disponibilidad;

// 1-disponible, 0-no disponible
} Vehiculo;

void menuVehiculos(char rol);
void cargaUnVehiculo();
void muestraVehiculosDisponibles();
void muestraVehiculo(Vehiculo vehiculo);
void modificarVehiculo();
void busquedaPorPatente();
Vehiculo buscarPatente(char patente);
Vehiculo* leerArchVehiculos(int* cantidad);
int validarLetrasPatente(Patente patente);
int validarNumerosPatente(Patente patente);
void ingresarTipoVehiculo(char* tipo);
void confirmarCambiosVehiculo(Vehiculo vehiculo);
int borrarPorPatente(char patente);


#endif // VEHICULOS_H_INCLUDED
