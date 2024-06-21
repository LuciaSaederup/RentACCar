#ifndef REPORTESESTADISTICAS_H_INCLUDED
#define REPORTESESTADISTICAS_H_INCLUDED


#include "includess.h"
#include "alquileres.h"
#include "persona.h"
#include "vehiculos.h"


void calcularIngresosEnMes(Persona* persona);
void calcularAlquilerMayorIngreso();
void verVehiculosDisponiblesRecientes();
void ordenarVehiculosPorAnio(Vehiculo* vehiculos, int cantidadVehiculos);
void imprimirVehiculosRecientes(Vehiculo* vehiculos, int cantidadVehiculos);
void verAlquileresPorCliente();




#endif // REPORTESESTADISTICAS_H_INCLUDED
