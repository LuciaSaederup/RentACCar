//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "login.h"
#include "gotoxy.h"
#include "menuReportesEstadisticas.h"


void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = textColor + (bgColor * 16);
    SetConsoleTextAttribute(hConsole, colorAttribute);
}

void setColorError(){
    setColor(4,0);
}

void setColorExito(){
    setColor(2,7);
}

void setColorGral(){
    setColor(7,3);
}


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

void pantallaBienvenida() {
     system("cls");
     setColorGral();
    int opcion = 0;
    int num_opciones = 2;
    char tecla;
    dibujarCuadro(25, 3, 100, 30);
    imprimirTitulo("Bienvenido a RentACar");
    do {



        for (int i = 0; i < num_opciones; i++) {
            gotoxy(50, 9 + i * 2);
            if (i == opcion) {
                printf(">");
            } else {
                printf(" ");
            }
            if (i == 0) {
                printf(" Iniciar Sesion");
            } else {
                printf(" Registrarse");
            }
        }

        tecla = getch();
        switch (tecla) {
            case 72:
                opcion = (opcion - 1 + num_opciones) % num_opciones;
                break;
            case 80:
                opcion = (opcion + 1) % num_opciones;
                break;
        }
    } while (tecla != 13);

    if (opcion == 0) {
        system("cls");
        iniciarSesion();
    } else {
        system("cls");
        registrarPersona();
    }
}

void menuPrincipal(char rol) {
    int opcion = 0;
    int num_opcionesClientes = 4;
    int num_opcionesAdmin = 5;
    char tecla;
    system("cls");
    setColorGral();
    dibujarCuadro(25, 3, 100, 30);

    imprimirTitulo("Menu Principal");
    toupper(rol);
    if (rol == 'C') {

        do {
            int i = 0;
            for (int i = 0; i < num_opcionesClientes; i++) {
                gotoxy(40, 9 + i * 2);

                if (i == opcion) {
                    printf(">");
                } else {
                    printf(" ");
                }
                if (i == 0) {
                    printf(" Vehiculos\n");
                } else if(i == 1) {
                    printf(" Personas\n");
                }else if(i==2){
                    printf(" Alquileres\n");
                }else if(i==3){
                    printf(" Salir");
                }
            }
            tecla = getch();

            switch (tecla) {
                case 72:
                    opcion = (opcion - 1 + num_opcionesClientes) % num_opcionesClientes;
                    break;
                case 80:
                    opcion = (opcion + 1) % num_opcionesClientes;
                    break;
            }
         }while (tecla != 13);

    switch (opcion) {
        case 0:
            menuVehiculos("C");
            break;
        case 1:
            menuPersonasCliente("C");
            break;
        case 2:
            menuAlquileresCliente("C");
        case 3:
            pantallaBienvenida();
        default:
            printf("Esta opcion no es válida");
            break;
        }

    } else if(rol=='A'){
        do {
            int i = 0;
            gotoxy(30, 5);
            for (int i = 0; i < num_opcionesAdmin; i++) {
                    gotoxy(30, 9 + i * 2);

                    if (i == opcion) {
                        printf(">");
                    } else {
                        printf(" ");
                    }
                    if (i == 0) {
                        printf(" Vehiculos\n");
                    } else if(i == 1) {
                        printf(" Personas\n");
                    }else if(i==2){
                        printf(" Alquileres\n");
                    }else if(i==3){
                        printf(" Reportes y estadisticas\n");
                    }else if(i==4){
                        printf(" Salir");
                    }
                }
            tecla = getch();

            switch (tecla) {
                case 72:
                    opcion = (opcion - 1 + num_opcionesAdmin) % num_opcionesAdmin;
                    break;
                case 80:
                    opcion = (opcion + 1) % num_opcionesAdmin;
                    break;
            }
        }while (tecla != 13);

            switch (opcion) {
                case 0:
                    menuVehiculos("A");
                    break;
                case 1:
                    menuPersonasAdmin("A");
                    break;
                case 2:
                    menuAlquileresAdmin("A");
                    break;
                case 3:
                    mostrarMenuReportesYEstadisticas("A");
                    break;
                case 4:
                    pantallaBienvenida();
                    break;
                default:
                    system("cls");
                printf("Esta opcion no es válida");
                    break;
            }

    }

}


void imprimirTitulo(char* titulo){

    gotoxy(30, 5);
    printf("===================================================================\n");
    gotoxy(20, 6);
    printf("                               %s                                  \n", titulo);
    gotoxy(30, 7);
    printf("===================================================================\n");


}
