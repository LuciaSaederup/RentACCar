#ifndef PANTALLAINGRESO_H_INCLUDED
#define PANTALLAINGRESO_H_INCLUDED


#include "persona.h"



void setColor(int textColor, int bgColor);
void setColorError();
void setColorExito();
void setColorGral();
void dibujarCuadro(int x1, int y1, int x2, int y2);
void pantallaBienvenida();
void menuPrincipal(Persona* persona);
void imprimirTitulo(char* titulo);




#endif // PANTALLAINGRESO_H_INCLUDED
