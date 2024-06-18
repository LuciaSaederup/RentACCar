#ifndef REPORTES_ESTADISTICAS_H_INCLUDED
#define REPORTES_ESTADISTICAS_H_INCLUDED
#include "vehiculos.h"
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    Fecha fechaInicio;
    Fecha fechaFin;
    Patente vehiculo;
    int dniCliente;
    float precioTotal;
} Alquiler;

// Funci�n para calcular ingresos en un mes y a�o espec�ficos
void calcularIngresosEnMes();

// Funci�n para calcular el alquiler que gener� mayor ingreso
void calcularAlquilerMayorIngreso();

// Funci�n para ver los veh�culos disponibles con menos de 5 a�os, ordenados por antig�edad
void verVehiculosDisponiblesRecientes();

// Funci�n para ver listado de alquileres por cliente
void verAlquileresPorCliente();

Alquiler* leerArchAlquileres(int* cantidad);

Vehiculo* leerArchVehiculos(int* cantidad);


#endif // REPORTES_ESTADISTICAS_H_INCLUDED
