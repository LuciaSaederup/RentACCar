#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "login.h"

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

void registrarPersona(char usuario[50], char clave[50], char rol);
#endif // PERSONA_H_INCLUDED
