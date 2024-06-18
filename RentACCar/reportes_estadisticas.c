#include "reportes_estadisticas.h"
#include "menuReportesEstadisticas.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gotoxy.h"
#define ANIOACTUAL 2024
#define RUTAALQUILERES "Alquileres.bin"
#define RUTAVEHICULOS "Vehiculos.bin"


void calcularIngresosEnMes() {
    system("cls");
    dibujarCuadro(25, 4, 85, 13);
    int mes, anio;
    gotoxy(30, 5);
    printf("Ingrese mes y anio (MM AAAA): ");
    gotoxy(60, 5);
    scanf("%d %d", &mes, &anio);
    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidadAlquileres);

    float ingresosTotales = 0;

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (alquileres[i].fechaInicio.mes == mes && alquileres[i].fechaInicio.anio == anio) {
            ingresosTotales += alquileres[i].precioTotal;
        }
    }

         gotoxy(35, 8);
        printf("Ingresos en %02d/%d: %.2f\n", mes, anio, ingresosTotales);
}

void calcularAlquilerMayorIngreso() {
    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidadAlquileres);

    Alquiler alquilerMayorIngreso = alquileres[0];
    for (int i = 1; i < cantidadAlquileres; i++) {
        if (alquileres[i].precioTotal > alquilerMayorIngreso.precioTotal) {
            alquilerMayorIngreso = alquileres[i];
        }
    }
    system("cls");
    dibujarCuadro(15, 4, 115, 12);
    printf("Alquiler con mayor ingreso: Fecha Inicio: %d/%d/%d, Patente: %s, Precio Total: %.2f\n",
           alquilerMayorIngreso.fechaInicio.dia, alquilerMayorIngreso.fechaInicio.mes, alquilerMayorIngreso.fechaInicio.anio,
           alquilerMayorIngreso.vehiculo.letras, alquilerMayorIngreso.precioTotal);
    gotoxy(20, 9);
    system("pause");
}

void verVehiculosDisponiblesRecientes() {

    int cantVehiculos;
    Vehiculo* vehiculos;
    vehiculos = leerArchVehiculos(&cantVehiculos);
    Vehiculo* vehiculosRecientes = (Vehiculo*) malloc(cantVehiculos*sizeof(Vehiculo));
    int contador = 0;
    int cantidadRecientes= 0;

    for (int i = 0; i < cantVehiculos; i++) {
        if (vehiculos[i].disponibilidad == 1 && (ANIOACTUAL - vehiculos[i].anio) < 5) {
            vehiculosRecientes[contador++] = vehiculos[i];
            cantidadRecientes++;
        }
    }

    ordenarVehiculosPorAnio(vehiculosRecientes, cantidadRecientes);
    imprimirVehiculosRecientes(vehiculosRecientes, cantidadRecientes);
}


void ordenarVehiculosPorAnio(Vehiculo* vehiculos, int cantidadVehiculos) {
    for (int i = 0; i < cantidadVehiculos - 1; i++) {
        for (int j = i + 1; j < cantidadVehiculos; j++) {
            if (vehiculos[i].anio > vehiculos[j].anio) {
                Vehiculo temp = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = temp;
            }
        }
    }
}
void imprimirVehiculosRecientes(Vehiculo* vehiculos, int cantidadVehiculos) {
    for (int i = 0; i < cantidadVehiculos; i++) {
        system("cls");
        dibujarCuadro(25, 4, 90, 20);
        printf("\n");
        printf("Marca: %s.\n", vehiculos[i].marca);
        printf("Modelo: %s.\n", vehiculos[i].modelo);
        printf("Patente: %s.\n", vehiculos[i].patente.letras);
        printf("Año: %i.\n", vehiculos[i].anio);
    }
}

/*void verVehiculosDisponiblesRecientes(Vehiculo* vehiculos, int cantidadVehiculos) {
    int cantidadRecientes = 0;
    Vehiculo* vehiculosRecientes = filtrarVehiculosRecientes(vehiculos, cantidadVehiculos, &cantidadRecientes);



    free(vehiculosRecientes);
}*/





void verAlquileresPorCliente() {

    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidadAlquileres);
    int dniCliente;

    system("cls");
    dibujarCuadro(25, 4, 90, 20);
    gotoxy(30, 5);
    printf("Ingrese DNI del cliente: ");
    gotoxy(40, 6);
    scanf("%d", &dniCliente);
    gotoxy(30, 6);
    printf("Fecha Inicio:  Patente:  Fecha Fin:  Precio Total: \n");

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (alquileres[i].dniCliente == dniCliente) {
            gotoxy(30, 7+i);
            printf("  %i/%i/%i. ",alquileres[i].fechaInicio.dia, alquileres[i].fechaInicio.mes, alquileres[i].fechaInicio.anio);
            printf("   %s. ", alquileres[i].vehiculo.letras);
            printf("   %i/%i/%i. ",alquileres[i].fechaFin.dia, alquileres[i].fechaFin.mes, alquileres[i].fechaFin.anio);
            printf("   %.2f\n",alquileres[i].precioTotal);
        }
    }
}


Alquiler* leerArchAlquileres(int* cantidad)
{
    FILE* archivoAlqui= fopen(RUTAALQUILERES, "rb");
    int i = 0;
    if(!archivoAlqui)
    {
        printf("\nHubo un error al abrir el archivo");
    }
    else
    {
        fseek(archivoAlqui, 0L, SEEK_END);
        long cantidadBytes = ftell(archivoAlqui);
        int cantidadEnArchivo = cantidadBytes / sizeof(Alquiler);
        Sleep(1500);

        fseek(archivoAlqui, 0L, SEEK_SET);
        Alquiler *arregloAlquileres;
        arregloAlquileres = (Alquiler*) malloc(cantidadEnArchivo * sizeof(Alquiler));

        if (arregloAlquileres == NULL) {
            printf("No se pudo asignar memoria.\n");
            fclose(archivoAlqui);
            return NULL;
        }

        for (int i = 0; i < cantidadEnArchivo; i++) {
            fread(&arregloAlquileres[i], sizeof(Alquiler), 1, archivoAlqui);
        }

        *cantidad = cantidadEnArchivo;
        fclose(archivoAlqui);
        return arregloAlquileres;

        }
}



