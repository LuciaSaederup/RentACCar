#include "reportes_estadisticas.h"
#include "menuReportesEstadisticas.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gotoxy.h"
#include "persona.h"
#include "vehiculos.h"
#define ANIOACTUAL 2024
#define RUTAALQUILERES "Alquileres.bin"
#define RUTAVEHICULOS "Vehiculos.bin"


void calcularIngresosEnMes() {
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    int mes, anio;

    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidadAlquileres);
    float ingresosTotales = 0;

    gotoxy(30, 5);
    printf("Ingrese mes y anio (MM AAAA): ");
    gotoxy(70, 5);
    scanf("%d %d", &mes, &anio);

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (alquileres[i].fechaInicio.mes == mes && alquileres[i].fechaInicio.anio == anio) {
            ingresosTotales += alquileres[i].precioTotal;
        }
    }

        gotoxy(30, 6);
        printf("Ingresos en %02d/%d: %.2f\n", mes, anio, ingresosTotales);
        Sleep(1500);
        mostrarMenuReportesYEstadisticas("A");
}

void calcularAlquilerMayorIngreso() {
    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidadAlquileres);
    int opcion;

    Alquiler alquilerMayorIngreso = alquileres[0];
    for (int i = 1; i < cantidadAlquileres; i++) {
        if (alquileres[i].precioTotal > alquilerMayorIngreso.precioTotal) {
            alquilerMayorIngreso = alquileres[i];
        }
    }

    while(opcion!=27){
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30,5);
    char patente = strcat(alquilerMayorIngreso.vehiculo.patente.letras, alquilerMayorIngreso.vehiculo.patente.numeros);
    printf("Alquiler con mayor ingreso: Fecha Inicio: %d/%d/%d, Patente: %s, Precio Total: %.2f\n",
           alquilerMayorIngreso.fechaInicio.dia, alquilerMayorIngreso.fechaInicio.mes, alquilerMayorIngreso.fechaInicio.anio,
           patente, alquilerMayorIngreso.precioTotal);
    gotoxy(30,6);
    printf("Si desea salir presione ESC");
    gotoxy(30,7);
    opcion = getch();
    }
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

    system("cls");
    Vehiculo* arregloVehiculos;
    int cantidad;
    arregloVehiculos = leerArchVehiculos(&cantidad);
    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;
    int i =20;
    int f = 9;
    dibujarCuadro(25, 3, 100, 30);

    do{
        for (int j = 0; j < num_opciones; j++) {
            gotoxy(i, f + j);
            if (j == opcion) {
                printf("> ");
            } else {
                printf("  ");
            }

            if(arregloVehiculos[j].disponibilidad==1){
                printf("Marca: %s, Modelo: %s, precio %d\n", arregloVehiculos[j].marca, arregloVehiculos[j].modelo, arregloVehiculos[j].precioDeAlquilerDiario);

            }
        }
        tecla = getch();

        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80:
            opcion = (opcion + 1) % num_opciones;
            break;
        }
        }while (tecla != 13);

    muestraVehiculo(arregloVehiculos[opcion]);


}



void verAlquileresPorCliente() {

    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidadAlquileres);
    char dni[8];

    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("Ingrese DNI del cliente: ");
    gotoxy(40, 5);
    fflush(stdin);
    gets(dni);
    dni[strcspn(dni, "\n")] = 0;
    gotoxy(30, 6);
    printf("Fecha Inicio:  Patente:  Fecha Fin:  Precio Total: \n");

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (strcmp(alquileres[i].persona.dni, dni)) {
            char patente = strcat(alquileres[i].vehiculo.patente.letras,alquileres[i].vehiculo.patente.numeros);
            gotoxy(30, 7+i);
            printf("  %i/%i/%i. ",alquileres[i].fechaInicio.dia, alquileres[i].fechaInicio.mes, alquileres[i].fechaInicio.anio);
            printf("   %s. ",patente);
            printf("   %i/%i/%i. ",alquileres[i].fechaFin.dia, alquileres[i].fechaFin.mes, alquileres[i].fechaFin.anio);
            printf("   %.2f\n",alquileres[i].precioTotal);
        }
    }
}


Alquiler* leerArchAlquileres(int* cantidad)
{
    FILE* archivoAlqui;
    archivoAlqui= fopen(RUTAALQUILERES, "rb");
    int i = 0;

    if(archivoAlqui==NULL)
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(30,5);
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

        for (int i = 0; i < cantidadEnArchivo; i++) {
            fread(&arregloAlquileres[i], sizeof(Alquiler), 1, archivoAlqui);
        }

        *cantidad = cantidadEnArchivo;
        fclose(archivoAlqui);
        return arregloAlquileres;

        }

}



