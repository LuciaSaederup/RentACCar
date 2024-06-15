#include "reportes_estadisticas.h"
#include <stdio.h>
#include <stdlib.h>

float calcularIngresosEnMes(Alquiler* alquileres, int cantidadAlquileres, int mes, int anio) {
    float ingresosTotales = 0;
    for (int i = 0; i < cantidadAlquileres; i++) {
        if (alquileres[i].fechaInicio.mes == mes && alquileres[i].fechaInicio.anio == anio) {
            ingresosTotales += alquileres[i].precioTotal;
        }
    }
    return ingresosTotales;
}

Alquiler calcularAlquilerMayorIngreso(Alquiler* alquileres, int cantidadAlquileres) {
    Alquiler alquilerMayorIngreso = alquileres[0];
    for (int i = 1; i < cantidadAlquileres; i++) {
        if (alquileres[i].precioTotal > alquilerMayorIngreso.precioTotal) {
            alquilerMayorIngreso = alquileres[i];
        }
    }
    return alquilerMayorIngreso;
}
