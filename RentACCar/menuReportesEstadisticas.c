#include "reportes_estadisticas.h"
#include "menuReportesEstadisticas.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#define ANIOACTUAL 2024

//Librerias

#include <string.h>
#include <conio.h>
#include <windows.h>


void mostrarMenuReportesYEstadisticas(Vehiculo* vehiculos, int cantidadVehiculos, Alquiler* alquileres, int cantidadAlquileres)
{
    int opcion;
    system("cls");
    setColor(7, 8); // Texto blanco, fondo gris
    system("cls");


    do
    {
        system("cls");
        dibujarCuadro(25, 4, 85, 15);

        gotoxy(30, 5);
        printf("====================================================\n");
        gotoxy(30, 6);
        printf("          Menu de Repoertes y estadisticas          \n");
        gotoxy(30, 7);
        printf("====================================================\n");

        gotoxy(30, 9);
        printf("1. Calcular ingresos en un mes\n");
        gotoxy(30, 10);
        printf("2. Calcular alquiler con mayor ingreso\n");
        gotoxy(30, 11);
        printf("3. Ver vehiculos disponibles con menos de 5 años\n");
        gotoxy(30, 12);
        printf("4. Ver listado de alquileres por cliente\n");
        gotoxy(30, 13);
        printf("0. Volver al menu principal\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
        {
            system("cls");
            dibujarCuadro(25, 4, 85, 13);
            int mes, anio;
            gotoxy(35, 7);
            printf("Ingrese mes y anio (MM AAAA): ");
            scanf("%d %d", &mes, &anio);
            float ingresos = calcularIngresosEnMes(alquileres, cantidadAlquileres, mes, anio);
            gotoxy(35, 8);
            printf("Ingresos en %02d/%d: %.2f\n", mes, anio, ingresos);
            gotoxy(35, 10);
            system("pause");

            break;
        }
        case 2:
        {
            system("cls");
            dibujarCuadro(15, 4, 115, 12);
            Alquiler mayorIngreso = calcularAlquilerMayorIngreso(alquileres, cantidadAlquileres);
            gotoxy(20, 7);
            printf("Alquiler con mayor ingreso: Fecha Inicio: %d/%d/%d, Patente: %s, Precio Total: %.2f\n",
                   mayorIngreso.fechaInicio.dia, mayorIngreso.fechaInicio.mes, mayorIngreso.fechaInicio.anio,
                   mayorIngreso.vehiculo.letras, mayorIngreso.precioTotal);
            gotoxy(20, 9);
            system("pause");

            break;
        }
        case 3:
        {
            system("cls");

            gotoxy(20, 7);
            verVehiculosDisponiblesRecientes(vehiculos, cantidadVehiculos);
            gotoxy(20, 5);
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            dibujarCuadro(25, 4, 90, 20);
            int dniCliente;
            gotoxy(41, 5);
            printf("Ingrese DNI del cliente: ");
            scanf("%d", &dniCliente);
            gotoxy(35, 6);
            verAlquileresPorCliente(alquileres, cantidadAlquileres, dniCliente);
            gotoxy(35, 19.5);
            system("pause");
            break;
        }
        case 0:
        {
            printf("MENU PRINCIPAL\n");
            ///PONER FUNCION DE MENU PRINCIPAL
            break;
        }
        default:
        {
            printf("Opcion no valida. Intente nuevamente.\n");
            break;
        }
        }

    }
    while (opcion != 0);
    system("cls");
}


