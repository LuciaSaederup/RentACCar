#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
typedef struct {
    char usuario[MAX_USERNAME];
    char clave[MAX_PASSWORD];
    char rol; // 'A' para Administrador, 'C' para Cliente

} Usuario;

void ocultarClave(char *clave);
void registrarUsuario();
void setColor(int textColor, int bgColor);
void gotoxy(int x, int y);
int verificarUsuario(char *usuario, char *clave);
void dibujarCuadro(int x1, int y1, int x2, int y2);

#endif // LOGIN_H_INCLUDED
