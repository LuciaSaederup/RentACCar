//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "login.h"

//variables globales
#define MAX_USERNAME 50
#define MAX_PASSWORD 50


// Pantalla de bienvenida
void pantallaBienvenida() {
    char opcion;
    setColor(7, 8); // Texto blanco, fondo gris
    system("cls");

    gotoxy(30, 5);
    printf("========================================\n");
    gotoxy(30, 6);
    printf("           Bienvenido al Sistema         \n");
    gotoxy(30, 7);
    printf("========================================\n");
    gotoxy(30, 9);
    printf("1. Iniciar Sesion\n");
    gotoxy(30, 11);
    printf("2. Registrarse\n");
    gotoxy(30, 13);
    printf("Seleccione una opcion (1 o 2): ");
    opcion = getch();

    if (opcion == '1') {
        char usuario[MAX_USERNAME];
        char clave[MAX_PASSWORD];

        system("cls");
        setColor(7, 8); // Texto blanco, fondo gris

        dibujarCuadro(10, 5, 70, 15); // Cuadro centrado
        setColor(0, 7); // Texto negro, fondo blanco
        gotoxy(20, 7);
        printf("Ingrese el nombre de usuario: ");
        setColor(7, 8); // Texto blanco, fondo gris
        gotoxy(50, 7);
        fgets(usuario, MAX_USERNAME, stdin);
        usuario[strcspn(usuario, "\n")] = '\0';

        setColor(0, 7); // Texto negro, fondo blanco
        gotoxy(20, 9);
        printf("Ingrese la clave: ");
        setColor(7, 8); // Texto blanco, fondo gris
        gotoxy(50, 9);
        ocultarClave(clave);

        if (verificarUsuario(usuario, clave)) {
            gotoxy(20, 11);
            setColor(2, 8); // Texto verde, fondo gris
            printf("Inicio de sesion exitoso!\n");
        } else {
            gotoxy(20, 11);
            setColor(4, 8); // Texto rojo, fondo gris
            printf("Usuario o clave incorrectos.\n");
        }
    } else if (opcion == '2') {
        system("cls");
        setColor(7, 8); // Texto blanco, fondo gris

        dibujarCuadro(10, 5, 70, 15); // Cuadro centrado
        registrarUsuario();

    } else {
        gotoxy(30, 15);
        setColor(4, 8); // Texto rojo, fondo gris
        printf("Opcion no valida.\n");
    }
}

void menuPrincipal(char rol) {
    char opcion;
    system("cls");
    setColor(7, 8); // Texto blanco, fondo gris

    gotoxy(30, 5);
    printf("========================================\n");
    gotoxy(30, 6);
    printf("           Menu Principal          \n");
    gotoxy(30, 7);
    printf("========================================\n");

    if (rol == 'C') {
        // Cliente
        gotoxy(30, 9);
        printf("1. VEHICULOS\n");
        gotoxy(30, 10);
        printf("2. PERSONAS\n");
        gotoxy(30, 11);
        printf("3. ALQUILER\n");
        gotoxy(30, 13);
        printf("Seleccione una opcion (1-3): ");
        opcion = getch();
    } else if (rol == 'A') {
        // Administrador
        gotoxy(30, 9);
        printf("1. GESTIONAR VEHICULOS\n");
        gotoxy(30, 10);
        printf("2. GESTIONAR PERSONAS\n");
        gotoxy(30, 11);
        printf("3. GESTIONAR ALQUILERES\n");
        gotoxy(30, 13);
        printf("Seleccione una opcion (1-3): ");
        opcion = getch();
    }

    switch (opcion) {
        case '1':
            // Acción para la opción 1
            printf("Esta opcion no está desarrollada todavía");
            break;
        case '2':
            // Acción para la opción 2
            printf("Esta opcion no está desarrollada todavía");
            break;
        case '3':
            // Acción para la opción 3
        printf("Esta opcion no está desarrollada todavía");

            break;
        default:
            // Opción no válida
        printf("Esta opcion no es válida");
            break;
    }
}

