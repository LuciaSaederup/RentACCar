
#include "menuReportesEstadisticas.h"

#include "includess.h"
#include "reportes_estadisticas.h"
#include "gotoxy.h"
#include "pantallaIngreso.h"



void mostrarMenuReportesYEstadisticas(Persona* persona)
{
     system("cls");
    setColorGral();
    int opcion;
    int num_opciones = 5;
    int tecla;
    imprimirTitulo("Reportes y estadisticas");
     dibujarCuadro(25, 3, 100, 30);
    do
    {
        gotoxy(30, 9);
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 10 + i * 2);

            if (i == opcion)
            {
                printf(">");
            }
            else
            {
                printf(" ");
            }
            switch(i){
            case 0:printf(" Calcular ingresos en un mes\n");break;
            case 1:printf(" Calcular alquiler con mayor ingreso\n");break;
            case 2:printf(" Ver vehiculos disponibles con menos de 5 años\n");break;
            case 3:printf(" Ver listado de alquileres por cliente\n");break;
            case 4:printf(" Volver al menu anterior");break;
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
                calcularIngresosEnMes(persona);
                break;
            }
            case 1:
            {
                calcularAlquilerMayorIngreso(persona);
                break;
            }
            case 2:
            {
                verVehiculosDisponiblesRecientes(persona);
                break;
            }
            case 3:
            {
                verAlquileresPorCliente(persona);
                break;
            }
            case 4:
                return;
            default:
                printf("Esta opcion no es válida");
                break;
        }

}
