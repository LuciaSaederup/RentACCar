//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "login.h"



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
// centrar un cuadro en la consola
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
    int opcion = 0;
    int num_opciones = 2;
    char tecla;
    setColor(7, 8); // Texto blanco, fondo gris


    do {
        system("cls");
        dibujarCuadro(27, 4, 72, 15);
        gotoxy(30, 5);
        printf("========================================\n");
        gotoxy(30, 6);
        printf("           Bienvenido al Sistema         \n");
        gotoxy(30, 7);
        printf("========================================\n");

        // Mostrar opciones
        for (int i = 0; i < num_opciones; i++) {
            gotoxy(30, 9 + i * 2);
            if (i == opcion) {
                printf("->  "); // Resalta la opción actual
            } else {
                printf("  ");
            }
            if (i == 0) {
                printf("1. Iniciar Sesion\n");
            } else {
                printf("2. Registrarse\n");
            }
        }
        // Obtiene la tecla presionada
        tecla = getch();
        //Manejo teclas
        switch (tecla) {
            case 72: // Flecha arriba
                opcion = (opcion - 1 + num_opciones) % num_opciones;
                break;
            case 80: // Flecha abajo
                opcion = (opcion + 1) % num_opciones;
                break;
        }
    } while (tecla != 13); // Salir con Enter

    // Aquí puedes llamar a la función correspondiente según la opción seleccionada
    if (opcion == 0) {
        system("cls");
        iniciarSesion();// Llamar a la función para iniciar sesión
    } else {
        system("cls");
        registrarPersona();// Llamar a la función para registrarse
    }
}

void menuPrincipal(char rol) {
    int opcion = 0;
    int num_opcionesClientes = 3;
    int num_opcionesAdmin = 3; // Número total de opciones: Iniciar Sesion y Registrarse
    char tecla;
    system("cls");
    setColor(7, 8); // Texto blanco, fondo gris
    system("cls");
    dibujarCuadro(27, 4, 72, 15);


    if (rol == 'C') {

        do {
            gotoxy(30, 5);
            printf("========================================\n");
            gotoxy(30, 6);
            printf("           Menu Principal                \n");
            gotoxy(30, 7);
            printf("========================================\n");

            // Cliente
            int i = 0;

          // Mostrar opciones
          for (int i = 0; i < num_opcionesClientes; i++) {
                gotoxy(30, 9 + i * 2);

                if (i == opcion) {
                    printf("> "); // Resalta la opción actual
                } else {
                    printf("  ");
                }
                if (i == 0) {
                    printf("1. VEHICULOS\n");
                } else if(i == 1) {
                    printf("2. PERSONAS\n");
                }else{
                    printf("3. ALQUILER\n");
                }
            }// Salir con Enter
            tecla = getch(); // Obtiene la tecla presionada

            switch (tecla) {
                case 72: // Flecha arriba
                    opcion = (opcion - 1 + num_opcionesClientes) % num_opcionesClientes;
                    break;
                case 80: // Flecha abajo
                    opcion = (opcion + 1) % num_opcionesClientes;
                    break;
            }
         }while (tecla != 13); // Salir con Enter

    switch (opcion) {
        case 0:
            system("cls");
            dibujarCuadro(27, 4, 72, 15); // Cuadro centrado
            // Acción para la opción 1
            printf("Esta opcion no está desarrollada todavía");
            break;
        case 1:
            menuPersonasCliente();
            break;
        case 2:
            system("cls");
            dibujarCuadro(27, 4, 72, 15); // Cuadro centrado
            // Acción para la opción 3
            printf("Esta opcion no está desarrollada todavía");
            break;
        default:
            // Opción no válida
        printf("Esta opcion no es válida");
            break;
        }

    } else{
        do {
            gotoxy(30, 5);
            printf("========================================\n");
            gotoxy(30, 6);
            printf("           Menu Principal                \n");
            gotoxy(30, 7);
            printf("========================================\n");

            int i = 0;
            gotoxy(30, 5);
            // Mostrar opciones
            for (int i = 0; i < num_opcionesAdmin; i++) {
                    gotoxy(30, 9 + i * 2);

                    if (i == opcion) {
                        printf("> "); // Resalta la opción actual
                    } else {
                        printf("  ");
                    }
                    if (i == 0) {
                        printf("1. GESTIONAR VEHICULOS\n");
                    } else if(i == 1) {
                        printf("2. GESTIONAR PERSONAS\n");
                    }else{
                        printf("3. GESTIONAR ALQUILERES\n");
                    }
                }
            tecla = getch(); // Obtiene la tecla presionada

            switch (tecla) {
                case 72: // Flecha arriba
                    opcion = (opcion - 1 + num_opcionesAdmin) % num_opcionesAdmin;
                    break;
                case 80: // Flecha abajo
                    opcion = (opcion + 1) % num_opcionesAdmin;
                    break;
            }
        }while (tecla != 13); // Salir con Enter

            switch (opcion) {
                case 0:
                    system("cls");
                    dibujarCuadro(10, 5, 70, 15); // Cuadro centrado
                    // Acción para la opción 1
                    printf("Esta opcion no está desarrollada todavía");
                    break;
                case 1:
                    // Acción para la opción 2
                    menuPersonasAdmin();
                    break;
                case 2:
                    system("cls");
                    dibujarCuadro(10, 5, 70, 15); // Cuadro centrado
                    // Acción para la opción 3
                printf("Esta opcion no está desarrollada todavía");

                    break;
                default:
                    system("cls");
                    // Opción no válida
                printf("Esta opcion no es válida");
                    break;
            }

    }

}
