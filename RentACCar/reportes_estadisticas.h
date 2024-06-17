#ifndef REPORTES_ESTADISTICAS_H_INCLUDED
#define REPORTES_ESTADISTICAS_H_INCLUDED

#include "estructuras.h"

// Funci�n para calcular ingresos en un mes y a�o espec�ficos
float calcularIngresosEnMes(Alquiler* alquileres, int cantidadAlquileres, int mes, int anio);

// Funci�n para calcular el alquiler que gener� mayor ingreso
Alquiler calcularAlquilerMayorIngreso(Alquiler* alquileres, int cantidadAlquileres);

// Funci�n para ver los veh�culos disponibles con menos de 5 a�os, ordenados por antig�edad
void verVehiculosDisponiblesRecientes(Vehiculo* vehiculos, int cantidadVehiculos);

// Funci�n para ver listado de alquileres por cliente
void verAlquileresPorCliente(Alquiler* alquileres, int cantidadAlquileres, int dniCliente);


void setColor(int textColor, int bgColor);
void gotoxy(int x, int y);
void dibujarCuadro(int x1, int y1, int x2, int y2);




#endif // REPORTES_ESTADISTICAS_H_INCLUDED
