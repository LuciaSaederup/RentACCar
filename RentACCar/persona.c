//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "login.h"


#define RUTAPERSONA "persona.bin"

#define MAX_NOMBRE 50
#define MAX_TELEFONO 20
#define MAX_DIRECCION 100
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_DNI 8


// Función para registrar la estructura Persona
void registrarPersona() {

    static long idIncremental = 1000;
    setColor(7, 8); // Texto blanco, fondo gris

    FILE *file = fopen(RUTAPERSONA, "a + b");

    if (!file) {
        printf("Error al abrir el archivo");
        exit(1);
    }else{
        Persona persona;

        persona.id = idIncremental++;

        dibujarCuadro(23, 3, 75, 17);
        gotoxy(30, 5);
        printf("Ingrese el DNI: ");
        gotoxy(50, 5);
        fflush(stdin);
        fgets(persona.dni, MAX_DNI, stdin);

        gotoxy(30, 7);
        printf("Ingrese el nombre completo: ");
        gotoxy(57, 7);
        fflush(stdin);
        gets(persona.nombre);

        gotoxy(30, 9);
        printf("Ingrese el telefono: ");
        gotoxy(50, 9);
        fflush(stdin);
        gets(persona.telefono);

        gotoxy(30, 11);
        printf("Ingrese la direccion: ");
        gotoxy(52,11);
        fflush(stdin);
        gets(persona.direccion);

        gotoxy(30, 13);
        printf("Ingrese su usuario: ");
        gotoxy(52, 13);
        fflush(stdin);
        gets(persona.usuario);

        gotoxy(30, 15);
        printf("Ingrese su clave: ");
        gotoxy(50, 15);
        fflush(stdin);
        ocultarClave(persona.pasword);

        persona.rol = 'C';

        gotoxy(30, 19);
        printf("Rol asignado por defecto: Cliente (C)\n");

        gotoxy(19, 21);
        printf("Presione 'A' para cambiar a Administrador, cualquier otra tecla para continuar como Cliente: ");
        char ch = getch();

        if (ch == 'A' || ch == 'a') {
            persona.rol = 'A';
        }


        gotoxy(30, 25);
        printf("Informacion de la persona registrada con exito.\n");



        fwrite(&persona, sizeof(Persona), 1, file);
        fclose(file);

        menuPrincipal(persona.rol);


    }


}


//Iniciar sesion
void iniciarSesion(){

        Persona user;
        system("cls");
        setColor(7, 8); // Texto blanco, fondo gris
        dibujarCuadro(23, 3, 75, 17);


        gotoxy(30, 5);
        printf("Ingrese el nombre de usuario: ");
        gotoxy(60, 5);
        fflush(stdin);
        gets(user.usuario);


        gotoxy(30, 7);
        printf("Ingrese la clave: ");
        fflush(stdin);
        gotoxy(60, 7);

        ocultarClave(user.pasword);

        char rolVerif;

        rolVerif = verificarUsuario(user);

        if(rolVerif == "A"  || rolVerif == "C" ){
            gotoxy(40, 9);
            setColor(2, 8); // Texto verde, fondo gris
            printf("Inicio de sesion exitoso!\n");

            menuPrincipal(rolVerif);
        } else {
            gotoxy(40, 9);
            setColor(4, 8); // Texto rojo, fondo gris
            printf("Usuario o clave incorrectos.\n");
        }


}

//ocultar clave
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


// Función para verificar el user de usuario
char verificarUsuario(Persona usuario) {

    Persona user;

    FILE *file = fopen(RUTAPERSONA, "rb");
    if (!file) {
        perror("Error al abrir el archivo");
        return "N";
    }else{

        while (!feof(file)) {

            fread(&user, sizeof(Persona), 1, file);
            system("cls");
            gotoxy(30, 5);
            printf("Estamos verificando su usuario, aguarde por favor...");

            if (strcmp(user.usuario, usuario.usuario) == 0 && strcmp(user.pasword, usuario.pasword) == 0) {
                fclose(file);
                return user.rol;
                gotoxy(30, 5);
                printf("Usuario y claves correctos! ");
                system("cls");
                menuPrincipal(user.rol);
            }else{
                gotoxy(30, 5);
                printf("No encontramos los datos, por favor regístrese o intente nuevamente. ");
                pantallaBienvenida();

            }

        }

        fclose(file);
    }

}

//menu personas que se muestra al admin
void menuPersonasAdmin(){
     int opcion = 0;
     char tecla;
     system("cls");
    setColor(7, 8); // Texto blanco, fondo gris
    system("cls");
    dibujarCuadro(27, 4, 72, 15);
    int num_opciones = 5;
    system("cls");

    do {
            gotoxy(30, 5);
            printf("========================================\n");
            gotoxy(30, 6);
            printf("                Personas                \n");
            gotoxy(30, 7);
            printf("========================================\n");

            int i = 0;
            gotoxy(30, 5);
            // Mostrar opciones
            for (int i = 0; i < num_opciones; i++) {
                    gotoxy(30, 9 + i * 2);

                    if (i == opcion) {
                        printf("> "); // Resalta la opción actual
                    } else {
                        printf("  ");
                    }
                    if (i == 0) {
                        printf("1. Agregar Persona \n");
                    } else if(i == 1) {
                        printf("2. Modificar Persona \n");
                    }else if(i == 2){
                        printf("3. Ver lista de personas \n");
                    }else if(i == 3){
                        printf("4. Buscar persona por DNI\n");
                    }else{
                        printf("5. Borrar persona \n");
                    }
                }
            tecla = getch(); // Obtiene la tecla presionada

            switch (tecla) {
                case 72: // Flecha arriba
                    opcion = (opcion - 1 + num_opciones) % num_opciones;
                    break;
                case 80: // Flecha abajo
                    opcion = (opcion + 1) % num_opciones;
                    break;
            }
        }while (tecla != 13); // Salir con Enter

            switch (opcion) {
                case 0:
                    registrarPersona();
                    break;
                case 1:
                    modificarPersona();
                    break;
                case 2:
                    verListaPersonas();
                    break;
                case 3:
                    buscarPersonaPorDNI();
                break;
                case 4:
                    borrarPersona();
                break;
                default:
                // Opción no válida
                printf("Esta opcion no es válida");
                    break;
            }

}

//funcion modificar persona
void modificarPersona(){

        system("cls");
        int opcion = 0;
        char tecla;
       int num_opciones = 7;
       Persona persona;
       FILE* archivoPersona = fopen(RUTAPERSONA, "r + b");
       char dni[MAX_DNI];
       fflush(stdin);
       printf("Antes de modificar la informacion personal deberá validar su DNI: \n");
       gets(dni);

    if(!archivoPersona){
        printf("Error al abrir el archivo");
        exit(1);
    }else{

        while(persona.dni != dni && !feof(archivoPersona)){
            fread(&persona, sizeof(Persona),1,archivoPersona);
        }

         do {
                gotoxy(30, 5);
                // Mostrar opciones
                for (int i = 0; i < num_opciones; i++) {
                        printf("Que atributo desea modificar? \n");
                        gotoxy(30, 9 + i * 2);

                        if (i == opcion) {
                            printf("> "); // Resalta la opción actual
                        } else {
                            printf("  ");
                        }
                        if (i == 0) {
                            printf(" Nombre \n");
                        } else if(i == 1) {
                            printf(" Telefono \n");
                        }else if(i == 2){
                            printf(" Direccion \n");
                        }else if(i == 3){
                            printf("Rol \n");
                        }else if(opcion == 4){
                            printf("Password \n");
                        }else{
                            printf("Usuario \n");
                        }
                    }
                tecla = getch(); // Obtiene la tecla presionada

                switch (tecla) {
                    case 72: // Flecha arriba
                        opcion = (opcion - 1 + num_opciones) % num_opciones;
                        break;
                    case 80: // Flecha abajo
                        opcion = (opcion + 1) % num_opciones;
                        break;
                }
            }while (tecla != 13); // Salir con Enter

             switch (opcion) {
                    case 0:
                        system("cls");
                        printf("Ingrese el nuevo nombre\n");
                        gets(persona.nombre);
                        break;
                    case 1:
                        system("cls");
                        printf("Ingrese el nuevo telefono\n");
                        gets(persona.telefono);
                    case 2:
                        system("cls");
                        printf("Ingrese la nuevo direccion\n");
                        gets(persona.direccion);
                    case 3:
                        system("cls");
                        printf("Ingrese el nuevo rol\n");
                        persona.rol = getch();
                    case 4:
                        system("cls");
                        printf("Ingrese el nuevo password\n");
                        gets(persona.pasword);
                    break;
                    case 5:
                        system("cls");
                        printf("Ingrese el nuevo usuario\n");
                        gets(persona.usuario);
                    break;
                    default:
                    // Opción no válida
                    printf("Esta opcion no es válida");
                        break;
                }


                int opcGuarda = 2;
                do{
                        for (int i = 0; i < opcGuarda; i++) {
                            printf("Desea guardar los cambios? \n");
                            gotoxy(30, 9 + i * 2);

                            if (i == opcion) {
                                printf("> "); // Resalta la opción actual
                            } else {
                                printf("  ");
                            }
                            if (i == 0) {
                                printf(" Si \n");
                                fseek(archivoPersona, -sizeof(Persona), SEEK_CUR);
                                fwrite(&persona, sizeof(Persona), 1, archivoPersona);
                            } else {
                                printf(" No \n");
                            }
                        }
                            tecla = getch(); // Obtiene la tecla presionada

                    switch (tecla) {
                        case 72: // Flecha arriba
                            opcion = (opcion - 1 + opcGuarda) % opcGuarda;
                            break;
                        case 80: // Flecha abajo
                            opcion = (opcion + 1) % opcGuarda;
                            break;
                    }

            }while (tecla != 13); // Salir con Enter

             switch (opcion) {
                    case 0:
                        fseek(archivoPersona, -sizeof(Persona), SEEK_CUR);
                        fwrite(&persona, sizeof(Persona), 1, archivoPersona);
                        break;
                    case 1:
                        menuPersonasAdmin();
             }
            fclose(archivoPersona);
        }
    }

//menu que se muestra al cliente
void menuPersonasCliente(){
     int opcion = 0;
     char tecla;
     system("cls");
    setColor(7, 8); // Texto blanco, fondo gris
    dibujarCuadro(27, 4, 72, 15);
    int num_opciones = 3;

    do {
            gotoxy(30, 5);
            printf("========================================\n");
            gotoxy(30, 6);
            printf("                Personas                \n");
            gotoxy(30, 7);
            printf("========================================\n");

            int i = 0;
            gotoxy(30, 5);
            // Mostrar opciones
            for (int i = 0; i < num_opciones; i++) {
                    gotoxy(30, 9 + i * 2);

                    if (i == opcion) {
                        printf("> "); // Resalta la opción actual
                    } else {
                        printf("  ");
                    }
                    if (i == 0) {
                        printf("1. Agregar Persona \n");
                    } else if(i == 1) {
                        printf("3. Ver lista de personas \n");
                    }else {
                        printf("4. Buscar persona por DNI\n");
                    }
                }
            tecla = getch(); // Obtiene la tecla presionada

            switch (tecla) {
                case 72: // Flecha arriba
                    opcion = (opcion - 1 + num_opciones) % num_opciones;
                    break;
                case 80: // Flecha abajo
                    opcion = (opcion + 1) % num_opciones;
                    break;
            }
        }while (tecla != 13); // Salir con Enter

            switch (opcion) {
                case 0:
                    registrarPersona();
                    break;
                case 1:
                    verListaPersonas();
                    break;
                case 2:
                    buscarPersonaPorDNI();
                break;
                default:
                // Opción no válida
                printf("Esta opcion no es válida");
                break;
            }

}



void verListaPersonas(){
    FILE* archivoPersona= fopen(RUTAPERSONA, "r+b");

    if(!archivoPersona){

    }else{

        while(!feof(archivoPersona)){

        }

    }



}
