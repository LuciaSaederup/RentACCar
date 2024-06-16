//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "pantallaIngreso.h"
#include "login.h"

#define RUTAPERSONA "persona.bin"

#define MAX_NOMBRE 50
#define MAX_TELEFONO 20
#define MAX_DIRECCION 100
#define MAX_USERNAME 50
#define MAX_PASSWORD 50


typedef struct {
int dni;
char nombre[50];
char telefono[20];
char direccion[100];
char rol;
char pasword [50];
char usuario [50];
long id;
} Persona;
// Función para registrar la estructura Persona
void registrarPersona(char usuario[50], char clave[50], char rol) {
    Persona persona;
    static long idIncremental = 1000;

    FILE *file = fopen(RUTAPERSONA, "a + b");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    persona.id = idIncremental++;

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 17);
    printf("Ingrese el DNI: ");
    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(45, 17);
    scanf("%d", &persona.dni);
    getchar(); // Limpiar el buffer

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 19);
    printf("Ingrese el nombre completo: ");
    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(45, 19);
    fgets(persona.nombre, MAX_NOMBRE, stdin);
    persona.nombre[strcspn(persona.nombre, "\n")] = '\0';

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 21);
    printf("Ingrese el telefono: ");
    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(45, 21);
    fgets(persona.telefono, MAX_TELEFONO, stdin);
    persona.telefono[strcspn(persona.telefono, "\n")] = '\0';

    setColor(0, 7); // Texto negro, fondo blanco
    gotoxy(15, 23);
    printf("Ingrese la direccion: ");
    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(45, 23);
    fgets(persona.direccion, MAX_DIRECCION, stdin);
    persona.direccion[strcspn(persona.direccion, "\n")] = '\0';

    fwrite(&persona, sizeof(Persona), 1, file);
    fclose(file);

    setColor(7, 8); // Texto blanco, fondo gris
    gotoxy(15, 25);
    printf("Informacion de la persona registrada con exito.\n");

    persona.usuario[strcspn(usuario, "\n")] = '\0';
    persona.pasword[strcspn(clave, "\n")] = '\0';
    persona.rol= rol;

    fwrite(persona, sizeof(Persona), RUTAPERSONA);
    menuPrincipal(rol);

}
