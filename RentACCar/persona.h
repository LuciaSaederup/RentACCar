#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "login.h"

typedef struct {
    char dni[8];
    char nombre[50];
    char telefono[20];
    char direccion[100];
    char rol;
    char pasword [50];
    char usuario [50];
    long id;
} Persona;

void registrarPersona();
void iniciarSesion();
void ocultarClave(char *clave);
char verificarUsuario(Persona user);
void modificarPersona();
void menuPersonasAdmin();
void menuPersonasCliente();
#endif // PERSONA_H_INCLUDED
