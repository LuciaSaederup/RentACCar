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

// Función para calcular ingresos en un mes y año específicos
void calcularIngresosEnMes();

// Función para calcular el alquiler que generó mayor ingreso
void calcularAlquilerMayorIngreso();

// Función para ver los vehículos disponibles con menos de 5 años, ordenados por antigüedad
void verVehiculosDisponiblesRecientes();

// Función para ver listado de alquileres por cliente
void verAlquileresPorCliente();

Alquiler* leerArchAlquileres(int* cantidad);

Vehiculo* leerArchVehiculos(int* cantidad);


#endif // REPORTES_ESTADISTICAS_H_INCLUDED
