#include "reportes_estadisticas.h"
#include "menuReportesEstadisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include "pantallaIngreso.h"
#include "vehiculos.h"
#define ANIOACTUAL 2024

//Librerias

#include <string.h>
#include <conio.h>
#include <windows.h>


void mostrarMenuReportesYEstadisticas()
{
    int opcion;
    system("cls");
    int num_opciones = 4;
    int tecla;

    do
    {
        system("cls");
        dibujarCuadro(25, 4, 85, 15);


        gotoxy(30, 5);
        printf("====================================================\n");
        gotoxy(30, 6);
        printf("              Reportes y estadisticas                 \n");
        gotoxy(30, 7);
        printf("====================================================\n");

        int i = 0;
        gotoxy(30, 5);
        // Mostrar opciones
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf("> "); // Resalta la opción actual
            }
            else
            {
                printf("  ");
            }
            if(i==0){
               printf("Calcular ingresos en un mes\n");
            }else if(i ==1){
                printf("Calcular alquiler con mayor ingreso\n");
            }else if(i==2){
                printf("Ver vehiculos disponibles con menos de 5 años\n");
            }else if(i==3){
                printf("Ver listado de alquileres por cliente\n");
            }
        }
        tecla = getch();

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }while (tecla != 13);

        switch(opcion)
        {
            case 0:
            {
                calcularIngresosEnMes();
                break;
            }
            case 1:
            {
                calcularAlquilerMayorIngreso();
                break;
            }
            case 2:
            {
                verVehiculosDisponiblesRecientes();
                break;
            }
            case 3:
            {
                verAlquileresPorCliente();
                break;
            }
            default:
                // Opción no válida
                printf("Esta opcion no es válida");
                break;
        }

}


