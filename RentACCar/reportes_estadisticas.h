#ifndef REPORTES_ESTADISTICAS_H_INCLUDED
#define REPORTES_ESTADISTICAS_H_INCLUDED

#include "estructuras.h"

// Función para calcular ingresos en un mes y año específicos
float calcularIngresosEnMes(Alquiler* alquileres, int cantidadAlquileres, int mes, int anio);

// Función para calcular el alquiler que generó mayor ingreso
Alquiler calcularAlquilerMayorIngreso(Alquiler* alquileres, int cantidadAlquileres);

// Función para ver los vehículos disponibles con menos de 5 años, ordenados por antigüedad
void verVehiculosDisponiblesRecientes(Vehiculo* vehiculos, int cantidadVehiculos);

// Función para ver listado de alquileres por cliente
void verAlquileresPorCliente(Alquiler* alquileres, int cantidadAlquileres, int dniCliente);


void setColor(int textColor, int bgColor);
void gotoxy(int x, int y);
void dibujarCuadro(int x1, int y1, int x2, int y2);




#endif // REPORTES_ESTADISTICAS_H_INCLUDED
