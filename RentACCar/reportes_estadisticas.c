#include "reportes_estadisticas.h"
#include "menuReportesEstadisticas.h"
#include <windows.h>
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#define ANIOACTUAL 2024


// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para cambiar el color de fondo y texto
void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor << 4)));
}


// Función para centrar un cuadro en la consola
void dibujarCuadro(int x1, int y1, int x2, int y2) {
    int i;
    for (i = x1; i <= x2; i++) {
        gotoxy(i, y1);
        printf("-");
        gotoxy(i, y2);
        printf("-");
    }
    for (i = y1; i <= y2; i++) {
        gotoxy(x1, i);
        printf("|");
        gotoxy(x2, i);
        printf("|");
    }
    gotoxy(x1, y1); printf("+");
    gotoxy(x2, y1); printf("+");
    gotoxy(x1, y2); printf("+");
    gotoxy(x2, y2); printf("+");
}



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

Vehiculo* filtrarVehiculosRecientes(Vehiculo* vehiculos, int cantidadVehiculos, int* cantidadRecientes) {
    Vehiculo* vehiculosRecientes = (Vehiculo*)malloc(cantidadVehiculos * sizeof(Vehiculo));
    int contador = 0;

    for (int i = 0; i < cantidadVehiculos; i++) {
        if (vehiculos[i].disponibilidad == 1 && (ANIOACTUAL - vehiculos[i].anio) < 5) {
            vehiculosRecientes[contador++] = vehiculos[i];
        }
    }

    *cantidadRecientes = contador;
    return vehiculosRecientes;
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
        ///
        printf("\n");
        printf("Marca: %s.\n", vehiculos[i].marca);
        printf("Modelo: %s.\n", vehiculos[i].modelo);
        printf("Patente: %s.\n", vehiculos[i].patente.letras);
        printf("Año: %i.\n", vehiculos[i].anio);
    }
}

void verVehiculosDisponiblesRecientes(Vehiculo* vehiculos, int cantidadVehiculos) {
    int cantidadRecientes = 0;
    Vehiculo* vehiculosRecientes = filtrarVehiculosRecientes(vehiculos, cantidadVehiculos, &cantidadRecientes);

    ordenarVehiculosPorAnio(vehiculosRecientes, cantidadRecientes);
    imprimirVehiculosRecientes(vehiculosRecientes, cantidadRecientes);

    free(vehiculosRecientes);
}





void verAlquileresPorCliente(Alquiler* alquileres, int cantidadAlquileres, int dniCliente) {
    printf("Fecha Inicio:  Patente:  Fecha Fin:  Precio Total: \n");

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (alquileres[i].dniCliente == dniCliente) {
            gotoxy(35, 8+i);
            printf("  %i/%i/%i. ",alquileres[i].fechaInicio.dia, alquileres[i].fechaInicio.mes, alquileres[i].fechaInicio.anio);
            printf("   %s. ", alquileres[i].vehiculo.letras);
            printf("   %i/%i/%i. ",alquileres[i].fechaFin.dia, alquileres[i].fechaFin.mes, alquileres[i].fechaFin.anio);
            printf("   %.2f\n",alquileres[i].precioTotal);
        }
    }
}
