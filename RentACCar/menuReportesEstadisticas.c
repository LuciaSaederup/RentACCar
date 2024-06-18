#include "reportes_estadisticas.h"
#include "menuReportesEstadisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include "pantallaIngreso.h"
#include "vehiculos.h"
#define ANIOACTUAL 2024
#include "gotoxy.h"
//Librerias

#include <string.h>
#include <conio.h>
#include <windows.h>


void mostrarMenuReportesYEstadisticas(char rol)
{
    setColorGral();
    int opcion;
    system("cls");
    int num_opciones = 4;
    int tecla;
    dibujarCuadro(25, 3, 100, 30);
    imprimirTitulo("Reportes y estadisticas");
    do
    {

        int i = 0;
        gotoxy(30, 5);
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf("> ");
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
        case 72:
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80:
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
                printf("Esta opcion no es válida");
                break;
        }

}


