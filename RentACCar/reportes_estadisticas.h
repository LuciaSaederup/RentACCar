#ifndef REPORTES_ESTADISTICAS_H_INCLUDED
#define REPORTES_ESTADISTICAS_H_INCLUDED

#include "estructuras.h"

// Función para calcular ingresos en un mes y año específicos
float calcularIngresosEnMes(Alquiler* alquileres, int cantidadAlquileres, int mes, int anio);

// Función para calcular el alquiler que generó mayor ingreso
Alquiler calcularAlquilerMayorIngreso(Alquiler* alquileres, int cantidadAlquileres);



#endif // REPORTES_ESTADISTICAS_H_INCLUDED
