#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

#include "includess.h"
#include "persona.h"


typedef struct
{
    char letras[MAX_LETRAS_PATENTE];
    char numeros[MAX_NUMEROS_PATENTE];
} Patente;


typedef struct
{
    char marca[20];
    char modelo[20];
    int anio;
    int kms;
    float precioDeAlquilerDiario;
    char tipoVehiculo[MAX_TIPO_VEHIC];
    Patente patente;
    int disponibilidad;

} Vehiculo;

void menuVehiculos(Persona* persona);
void cargaUnVehiculo();
void muestraVehiculosDisponibles();
void muestraVehiculo(Vehiculo vehiculo);
void modificarVehiculo();
void busquedaPorPatente();
Vehiculo buscarPatente(Patente patente);
Vehiculo* leerArchVehiculos(int* cantidad);
int validarLetrasPatente(Patente patente);
void ingresarTipoVehiculo(char* tipo);
void confirmarCambiosVehiculo(Vehiculo vehiculo);
int borrarPorPatente(Patente patente);
int validarNumerosPatente(Patente patente);
int modificar_registro_vehiculo ( Vehiculo vehiculo);
int compararPatentes(Patente p1, Patente p2);
void borrarVehiculo();
#endif // VEHICULO_H_INCLUDED
