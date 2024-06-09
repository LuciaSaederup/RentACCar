//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "persona.h"
//variables globalles
// Secuencias de escape ANSI para colores

#define MAX_USERNAME 50
#define MAX_PASSWORD 50
//Rutas de archivos
#define RUTALOGIN "registroLogin.bin"
#define RUTAPERSONA "persona.bin"



// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ocultarClave(char *clave) {
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else if (ch != '\b') {
            printf("*");
            clave[i++] = ch;
        }
    }
    clave[i] = '\0';
    printf("\n");
}

// Función para cambiar el color de fondo y texto
void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor << 4)));
}

// Función para verificar las credenciales de usuario
int verificarUsuario(char *usuario, char *clave) {
    Usuario user;
    FILE *file = fopen(RUTALOGIN, "rb");
    if (!file) {
        perror("Error al abrir el archivo");
        return 0;
    }

    while (fread(&user, sizeof(Usuario), 1, file)) {
        if (strcmp(user.usuario, usuario) == 0 && strcmp(user.clave, clave) == 0) {
            fclose(file);
            menuPrincipal(user.rol);

            return 1; // Usuario y clave correctos
        }
    }

    fclose(file);
    return 0; // Usuario o clave incorrectos
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



// Pantalla de bienvenida
// Función para registrar un usuario
void registrarUsuario() {
    Usuario user;
    FILE *file = fopen(RUTALOGIN, "ab");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 7);
    printf("Ingrese el nombre de usuario: ");
    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(45, 7);
    fgets(user.usuario, MAX_USERNAME, stdin);
    user.usuario[strcspn(user.usuario, "\n")] = '\0';

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 9);
    printf("Ingrese la clave: ");
    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(45, 9);
    ocultarClave(user.clave);

    user.rol = 'C'; // Rol por defecto: Cliente
    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 11);
    printf("Rol asignado por defecto: Cliente (C)\n");

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 13);
    printf("Presione 'A' para cambiar a Administrador, cualquier otra tecla para continuar como Cliente: ");
    setColor(7, 8); // Texto blanco, fondo gris
    char ch = getch();
    if (ch == 'A' || ch == 'a') {
        user.rol = 'A';
    }

    fwrite(&user, sizeof(Usuario), 1, file);
    fclose(file);

    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(15, 15);
    printf("Usuario registrado con exito.\n");

    // Registrar información adicional de persona
    registrarPersona(user.clave, user.rol, user.usuario);
}

