#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


#include "includess.h"

////Librerias
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <windows.h>
//
//
//#include "pantallaIngreso.h"
//#include "gotoxy.h"
//
//
//
//#define RUTAPERSONA "persona.bin"
//#define RUTAPERSONATEMP "personaTemp.bin"
//#define MAX_NOMBRE 50
//#define MAX_TELEFONO 20
//#define MAX_DIRECCION 100
//#define MAX_USERNAME 50
//#define MAX_PASSWORD 50




typedef struct
{
    char dni[8];
    char nombre[50];
    char telefono[20];
    char direccion[100];
    char rol;
    char pasword [50];
    char usuario [50];
}Persona;




void registrarPersona();
void iniciarSesion();
void ocultarClave(char *clave);
char verificarUsuario(Persona* usuario);
void menuPersonasAdmin(Persona* persona);
void modificarPersonaCliente();
void modificarPersonaAdmin();
void menuPersonasCliente(Persona* persona);
void verListaPersonas();
void imprimirPersona(Persona persona);
void buscarPersonaPorDNI(Persona* persona);
Persona buscarPersona(char dni[]);
Persona buscar_persona_archi (char* nombreArchi, char dni[]);
void borrarPersona(Persona* persona);
int borrarPorDNI(char dniBorrar[]);
Persona* leerArchPersonas(int* cantidad);
void confirmarCambiosPersona(Persona persona);
void noTocar();
void cambiarRol(char* rolAnterior);


#endif // PERSONA_H_INCLUDED
