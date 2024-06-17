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
void verListaPersonas();
void imprimirPersona(Persona persona, int y, int x);
Persona buscarPersona(char dni[]);
void borrarPersona();
int borrarPorDNI(char dniBorrar);
Persona leerArchPersonas(int* cantidad);


#endif // PERSONA_H_INCLUDED
