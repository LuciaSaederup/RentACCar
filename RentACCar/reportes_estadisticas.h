#ifndef REPORTES_ESTADISTICAS_H_INCLUDED
#define REPORTES_ESTADISTICAS_H_INCLUDED

#include "estructuras.h"

// Funci�n para calcular ingresos en un mes y a�o espec�ficos
float calcularIngresosEnMes(Alquiler* alquileres, int cantidadAlquileres, int mes, int anio);

// Funci�n para calcular el alquiler que gener� mayor ingreso
Alquiler calcularAlquilerMayorIngreso(Alquiler* alquileres, int cantidadAlquileres);



#endif // REPORTES_ESTADISTICAS_H_INCLUDED
