//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "login.h"


#define RUTAPERSONA "persona.bin"
#define RUTAPERSONATEMP "personaTemp.bin"
#define MAX_NOMBRE 50
#define MAX_TELEFONO 20
#define MAX_DIRECCION 100
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_DNI 8


// Funci�n para registrar la estructura Persona
void registrarPersona()
{

    static long idIncremental = 1000;
    setColor(7, 8); // Texto blanco, fondo gris

    FILE *file = fopen(RUTAPERSONA, "ab");

    if (!file)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

        Persona persona;

        persona.id = idIncremental++;

        dibujarCuadro(23, 3, 75, 17);
        gotoxy(30, 5);
        printf("Ingrese el DNI: ");
        gotoxy(50, 5);
        fflush(stdin);
        gets(persona.dni);

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

        if (ch == 'A' || ch == 'a')
        {
            persona.rol = 'A';
        }


        gotoxy(30, 25);
        printf("Informacion de la persona registrada con exito.\n");


        fwrite(&persona, sizeof(Persona), 1, file);


        menuPrincipal(persona.rol);
        fclose(file);

    }


//Iniciar sesion
void iniciarSesion()
{

        Persona user;
    system("cls");
    setColor(7, 8); // Texto blanco, fondo gris
    dibujarCuadro(23, 3, 75, 17);

    gotoxy(30, 5);
    printf("Ingrese el nombre de usuario: ");
    gotoxy(60, 5);
    fflush(stdin);
    fgets(user.usuario, MAX_USERNAME, stdin);
    user.usuario[strcspn(user.usuario, "\n")] = 0; // Remover el salto de l�nea

    gotoxy(30, 7);
    printf("Ingrese la clave: ");
    fflush(stdin);
    gotoxy(60, 7);
    ocultarClave(user.pasword);

    char rolVerif = verificarUsuario(user);

    if (rolVerif == 'A' || rolVerif == 'C') {
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
void ocultarClave(char *clave)
{
    int i = 0;
    char ch;
    while (1) {
        ch = getch();

        if (ch == 13) {  // Enter key
            clave[i] = '\0';  // Null-terminate the string
            break;
        } else if (ch == 224) {
                i--;
                printf("\b \b");  // Mueve el cursor hacia atr�s, imprime un espacio, y vuelve a mover el cursor hacia atr�s
        } else if (i < MAX_PASSWORD - 1) {
            clave[i++] = ch;  // Almacena el car�cter
            printf("*");  // Muestra un asterisco
        }

    }

}


// Funci�n para verificar el user de usuario
char verificarUsuario(Persona usuario)
{

     Persona* arregloPersonas;
    int cantidad;
    arregloPersonas = leerArchPersonas(&cantidad);

    for(int i= 0; i<cantidad;i++){

        arregloPersonas[i].usuario[strcspn(arregloPersonas[i].usuario, "\n")]==0;

        arregloPersonas[i].pasword[strcspn(arregloPersonas[i].pasword, "\n")]==0;
        usuario.pasword[strcspn(usuario.pasword, "\n")==0];
        usuario.usuario[strcspn(usuario.usuario, "\n")==0];

         if ((strcmpi(arregloPersonas[i].usuario, usuario.usuario)==0)
              && (strcmpi(arregloPersonas[i].pasword , usuario.pasword)==0))
        {

            system("cls");
            gotoxy(30, 5);
            printf("Usuario y claves correctos! ");
            Sleep(1500);
            menuPrincipal(usuario.rol);
            }

            system("cls");
            dibujarCuadro(23, 3, 75, 17);
            gotoxy(30, 5);
            printf("Verificando...");
            Sleep(1000);
    }
            system("cls");
            dibujarCuadro(23, 3, 75, 17);
            gotoxy(30, 7);
            printf("No encontramos los datos.\n ");
            gotoxy(30, 8);
            printf("Por favor registrese o intente nuevamente.");
            Sleep(3000);
            pantallaBienvenida();

}

//menu personas que se muestra al admin
void menuPersonasAdmin()
{
    int opcion = 0;
    char tecla;
    system("cls");
    setColor(7, 8); // Texto blanco, fondo gris
    system("cls");

    int num_opciones = 5;
    system("cls");

    do
    {
        dibujarCuadro(27, 4, 72, 20);
        gotoxy(30, 5);
        printf("========================================\n");
        gotoxy(30, 6);
        printf("                Personas                \n");
        gotoxy(30, 7);
        printf("========================================\n");

        int i = 0;
        gotoxy(30, 5);
        // Mostrar opciones
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf("> "); // Resalta la opci�n actual
            }
            else
            {
                printf("  ");
            }

             if(i == 0)
            {
                printf("Modificar Persona \n");
            }
            else if(i == 1)
            {
                printf("Ver lista de personas \n");
            }
            else if(i == 2)
            {
                printf("Buscar persona por DNI\n");
            }
            else if(i==3)
            {
                printf("Borrar persona \n");
            }
        }
        tecla = getch(); // Obtiene la tecla presionada

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }
    while (tecla != 13);  // Salir con Enter

    switch (opcion)
    {
        case 0:
            modificarPersona();
            break;
        case 1:
            verListaPersonas();
            break;
        case 2:
            buscarPersonaPorDNI();
            break;
        case 3:
            borrarPersona();
            break;
        default:
            // Opci�n no v�lida
            printf("Esta opcion no es v�lida");
            break;
    }

}

//funcion modificar persona
void modificarPersona()
{
    system("cls");
    int opcion = 0;
    char tecla;
    int num_opciones = 6;
    char dni[MAX_DNI];
    Persona persona;


    gotoxy(20,5);
    printf("Antes de modificar la informacion personal debera validar su DNI: \n");
    gotoxy(30,6);
    fflush(stdin);
    gets(dni);
    dni[strcspn(dni, "\n")] = 0;
    persona = buscarPersona(dni);
    system("cls");


    do
    {

        dibujarCuadro(20, 4, 90, 27);
        gotoxy(30, 5);
        printf("Que atributo desea modificar? \n");
        for (int i = 0; i < num_opciones; i++)
        {

            gotoxy(30, 8 + i * 2);
            if (i == opcion)
            {
                printf("> "); // Resalta la opci�n actual
            }
            else
            {
                printf("  ");
            }

            if (i == 0)
            {
                printf("Nombre \n");
            }
            else if(i == 1)
            {
                printf("Telefono \n");
            }
            else if(i == 2)
            {
                printf("Direccion \n");
            }
            else if(i == 3)
            {
                printf("Rol \n");
            }
            else if(i == 4)
            {
                printf("Password \n");
            }
            else if(i == 5)
            {
                printf("Usuario \n");
            }
        }
        tecla = getch(); // Obtiene la tecla presionada

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }while (tecla != 13);  // Salir con Enter

    switch (opcion)
    {
    case 0:
        system("cls");
        gotoxy(30, 5);
        printf("Ingrese el nuevo nombre: \n");
        gotoxy(70, 5);
        gets(persona.nombre);
        break;
    case 1:
        system("cls");
        gotoxy(30, 6);
        printf("Ingrese el nuevo telefono\n");
        gotoxy(60, 6);
        gets(persona.telefono);
        break;
    case 2:
        system("cls");
        gotoxy(30, 7);
        printf("Ingrese la nuevo direccion\n");
        gotoxy(60, 7);
        gets(persona.direccion);
        break;
    case 3:
        system("cls");
        gotoxy(30, 8);
        printf("Ingrese el nuevo rol\n");
        gotoxy(60, 8);
        persona.rol = getch();
        break;
    case 4:
        system("cls");
        gotoxy(30, 9);
        printf("Ingrese el nuevo password\n");
        gotoxy(60, 9);
        gets(persona.pasword);
        break;
    case 5:
        system("cls");
        gotoxy(30, 10);
        printf("Ingrese el nuevo usuario\n");
        gotoxy(60, 10);
        gets(persona.usuario);
        break;
    default:
        gotoxy(30, 6);
        printf("Esta opcion no es v�lida");
        break;
    }
    confirmarCambiosPersona(persona);
}


//menu que se muestra al cliente
void menuPersonasCliente()
{
    int opcion = 0;
    char tecla;
    system("cls");
    setColor(7, 8); // Texto blanco, fondo gris

    int num_opciones = 3;

    do
    {
        dibujarCuadro(27, 4, 72, 15);
        gotoxy(30, 5);
        printf("========================================\n");
        gotoxy(30, 6);
        printf("                Personas                \n");
        gotoxy(30, 7);
        printf("========================================\n");

        int i = 0;
        gotoxy(30, 5);
        // Mostrar opciones
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf("> "); // Resalta la opci�n actual
            }
            else
            {
                printf("  ");
            }
            if (i == 0)
            {
                printf("1. Agregar Persona \n");
            }
            else if(i == 1)
            {
                printf("3. Ver lista de personas \n");
            }
            else
            {
                printf("4. Buscar persona por DNI\n");
            }
        }
        tecla = getch(); // Obtiene la tecla presionada

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }
    while (tecla != 13);  // Salir con Enter

    switch (opcion)
    {
    case 0:
        system("cls");
        registrarPersona();
        break;
    case 1:
        system("cls");
        verListaPersonas();
        break;
    case 2:
        system("cls");
        buscarPersonaPorDNI();
        break;
    default:
        // Opci�n no v�lida
        printf("Esta opcion no es v�lida");
        break;
    }

}

//mostrar la lista de personas
void verListaPersonas()
{
    Persona* arregloPersonas;
    int cantidad;
    arregloPersonas = leerArchPersonas(&cantidad);
    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;

    int i =20;
    int f = 9;

    do{
        system("cls");
        setColor(7, 8);
        // Mostrar opciones
        for (int j = 0; j < num_opciones; j++) {
            gotoxy(i, f + j);
            if (j == opcion) {
                printf("> "); // Resalta la opci�n actual
            } else {
                printf("  ");
            }
            // Print name and DNI
            printf("Nombre: %s, Dni: %s\n", arregloPersonas[j].nombre, arregloPersonas[j].dni);
        }
        tecla = getch(); // Obtiene la tecla presionada

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % num_opciones;
            break;
        }
        }while (tecla != 13);  // Salir con Enter


       if(tecla!=27){
            imprimirPersona(arregloPersonas[opcion]);
            tecla = getch();
        }

        menuPersonasAdmin();
        Sleep(1500);
        system("cls");



}

//imprime una persona
void imprimirPersona(Persona persona)
{

system("cls");
    setColor(7, 8);
    // dibujarCuadro(27, 8, 70, 17); // Descomentar si tienes esta funci�n definida

    gotoxy(30, 5);
    printf("========================================");

    gotoxy(30, 6);
    printf("Nombre: %s", persona.nombre);

    gotoxy(30, 7);
    printf("DNI: %s", persona.dni);

    gotoxy(30, 8);
    printf("Telefono: %s", persona.telefono);

    gotoxy(30, 9);
    printf("Direccion: %s", persona.direccion);

    gotoxy(30, 10);
    printf("Rol: %c", persona.rol);

    gotoxy(30, 11);
    printf("Usuario: %s", persona.usuario);

    gotoxy(30, 12);
    printf("Clave: %s", persona.pasword);

    gotoxy(30, 13);
    printf("Id: %ld", persona.id);

    gotoxy(30, 14);
    printf("========================================");
}



//buscar  persona por dni
void buscarPersonaPorDNI()
{
    system("cls");
    setColor(7, 8);
    char dni[MAX_DNI];

    dibujarCuadro(27, 4, 80, 20);
    gotoxy(30, 5);
    printf("Ingrese el DNI por el que desea buscar: ");
    fgets(dni, MAX_DNI, stdin);

    size_t len = strlen(dni);
    if (len > 0 && dni[len-1] == '\n') {
        dni[len-1] = '\0';
    }

    Persona persona = buscarPersona(dni);

    gotoxy(30, 5);
    printf("La persona se encontro: \n");
    imprimirPersona(persona);
}


Persona buscarPersona(char dni[])
{
    Persona* arregloPersonas;
    int cantidad;
    arregloPersonas = leerArchPersonas(&cantidad);


    for(int i = 0; i<cantidad; i++)
    {

        arregloPersonas[i].dni[strcspn(arregloPersonas[i].dni, "\n")]==0;

        if(strcmpi(arregloPersonas[i].dni, dni)== 0)
        {

            return arregloPersonas[i];
        }
    }


}


void borrarPersona()
{
    int borrado;
    char dni[MAX_DNI];
    printf("Ingrese el dni de la persona que quiere borrar: \n");
    fflush(stdin);
    gets(dni);
    borrado = borrarPorDNI(dni);
}


int borrarPorDNI(char dniBorrar[])
{
    FILE  *archivoTemporalPersonas, *archivoPersona;

    Persona persona;
    int encontrado = 0;
    dniBorrar[strcspn(dniBorrar, "\n")] = 0;
    int cantidad;
    int i=0;
    Persona* arrayPersonas;
    arrayPersonas = leerArchPersonas(&cantidad);

    archivoPersona = fopen(RUTAPERSONA, "rb");
    // Abre un archivo temporal en modo escritura binaria
    archivoTemporalPersonas = fopen(RUTAPERSONATEMP, "wb");

    if (archivoTemporalPersonas == NULL || archivoPersona == NULL)
    {
        printf("Error al abrir el archivo temporal");
        fclose(archivoTemporalPersonas);
        fclose(archivoPersona);
        return 0;
    }

    // Lee los registros del archivo original y escribe en el archivo temporal
    while (i<cantidad)
    {
        arrayPersonas[i].dni[strcspn(arrayPersonas[i].dni, "\n")] = 0;

        if (strcmpi(arrayPersonas[i].dni, dniBorrar) != 0)
        {
            fwrite(&persona, sizeof(Persona), 1, archivoTemporalPersonas);
        }
        else
        {
            encontrado = 1;
        }
        i++;
    }

    // Cierra ambos archivos
    fclose(archivoTemporalPersonas);
    fclose(archivoPersona);

    // Si se encontr� el registro a borrar, reemplaza el archivo original
    if (encontrado)
    {
        unlink(RUTAPERSONA);

        rename(RUTAPERSONATEMP, RUTAPERSONA);
        printf("Registro con DNI %s fue borrado.\n", dniBorrar);
        Sleep(1500);
    }
    else
    {
        // Si no se encontr� el registro, elimina el archivo temporal
        unlink(RUTAPERSONATEMP);
        printf("Registro con DNI %s no encontrado.\n", dniBorrar);
    }

    return encontrado;
}


Persona* leerArchPersonas(int* cantidad)
{
    FILE* archivoPersona= fopen(RUTAPERSONA, "rb");
    int i = 0;
    if(!archivoPersona)
    {
        printf("\nHubo un error al abrir el archivo");
    }
    else
    {
        fseek(archivoPersona, 0L, SEEK_END);
        long cantidadBytes = ftell(archivoPersona);
        int cantidadEnArchivo = cantidadBytes / sizeof(Persona);
        Sleep(1500);

        fseek(archivoPersona, 0L, SEEK_SET);
        Persona *arregloPersonas;
        arregloPersonas = (Persona*) malloc(cantidadEnArchivo * sizeof(Persona));

        if (arregloPersonas == NULL) {
            printf("No se pudo asignar memoria.\n");
            fclose(archivoPersona);
            return NULL;
        }

        for (int i = 0; i < cantidadEnArchivo; i++) {
            fread(&arregloPersonas[i], sizeof(Persona), 1, archivoPersona);
        }

        *cantidad = cantidadEnArchivo;
        fclose(archivoPersona);
        return arregloPersonas;

        }
}


void confirmarCambiosPersona(Persona persona){


    int opcGuarda = 2;
    int opcion = 0;
    char tecla;
    FILE* archivoPersona;

    do{
        for (int i = 0; i < opcGuarda; i++)
        {
            gotoxy(30, 6);
            printf("Desea guardar los cambios? \n");
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf("> ");
            }
            else
            {
                printf("  ");
            }
            if (i == 0)
            {
                printf("Si \n");

            }
            else if(i==1)
            {
                printf("No \n");
            }
        }
        tecla = getch(); // Obtiene la tecla presionada

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + opcGuarda) % opcGuarda;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % opcGuarda;
            break;
        }
    }while (tecla != 13);  // Salir con Enter

    switch (opcion)
    {
        case 0:
            borrarPorDNI(persona.dni);

            archivoPersona = fopen(RUTAPERSONA, "ab");
            system("cls");
            if(!archivoPersona)
                {
                    printf("Error al abrir el archivo");
                    exit(1);
                }

            fwrite(&persona, sizeof(Persona), 1, archivoPersona);
            fclose(archivoPersona);
            printf("\n Usuario guardado con exito!");
            Sleep(2000);
            menuPersonasAdmin();

        case 1:
            menuPersonasAdmin();
    }



}