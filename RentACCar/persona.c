#include "persona.h"
#include "pantallaIngreso.h"
#include "gotoxy.h"


void registrarPersona()
{

    FILE *file = fopen(RUTAPERSONA, "ab");
    dibujarCuadro(25, 3, 100, 30);

    if (!file)
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorGral();
        gotoxy(50,5);
        printf("Error al abrir el archivo");
    }else{

        setColorGral();
        Persona persona;


        gotoxy(30, 5);
        printf("Ingrese el DNI: ");
        gotoxy(50, 5);
        fflush(stdin);
        fgets(persona.dni, MAX_DNI, stdin);

        gotoxy(30, 7);
        printf("Ingrese el nombre completo: ");
        gotoxy(57, 7);
        fflush(stdin);
        fgets(persona.nombre, MAX_NOMBRE, stdin);

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
        Sleep(1500);

        if( fwrite(&persona, sizeof(Persona), 1, file)==1){
            gotoxy(30, 25);
            setColorExito();
            printf( "Informacion de la persona registrada con exito.\n");
            Sleep(1500);
            system("cls");
            fclose(file);
            setColorGral();
        }else{
            gotoxy(30, 25);
            setColorError();
            printf("Hubo un error al escribir la informacion.\n");
            Sleep(1500);
            fclose(file);
            system("cls");
            setColorGral();

        }

        menuPrincipal(&persona);

    }
}

void iniciarSesion()
{

    Persona user;
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    setColorGral();
    gotoxy(30, 5);
    printf("Ingrese el nombre de usuario: ");
    gotoxy(60, 5);
    fflush(stdin);
    fgets(user.usuario, MAX_USERNAME, stdin);
    user.usuario[strcspn(user.usuario, "\n")] = 0;

    gotoxy(30, 7);
    printf("Ingrese la clave: ");
    fflush(stdin);
    gotoxy(60, 7);
    ocultarClave(user.pasword);

    char rolVerif = verificarUsuario(&user);

    if (rolVerif == 'A' || rolVerif == 'C') {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorExito();
        gotoxy(50, 5);
        printf("Inicio de sesion exitoso!\n");
        Sleep(1500);
        system("cls");
        setColorGral();
        menuPrincipal(&user);
    } else {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50, 5);
        printf("Usuario o clave incorrectos.\n");
        Sleep(1500);
        system("cls");
        setColorGral();
    }


}

void menuPersonasAdmin(Persona* persona)
{
    system("cls");
    int opcion = 0;
    char tecla;
    int num_opciones = 5;

    do
    {
        imprimirTitulo("Personas");
        dibujarCuadro(25, 3, 100, 30);

        gotoxy(30, 5);
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf(">");
            }
            else
            {
                printf(" ");
            }

            switch (i){
            case 0:
                printf(" Modificar Persona \n");
            break;
            case 1:
                printf(" Ver lista de personas \n");
            break;
            case 2:
                printf(" Buscar persona por DNI\n");
            break;
            case 3:
                printf(" Borrar persona \n");
            break;
            case 4:
                printf(" Volver al menu anterior");
            break;
            }
        }
        tecla = getch();

        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80:
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }
    while (tecla != 13);

    switch (opcion)
    {
        case 0:
            modificarPersonaAdmin(persona);
            break;
        case 1:
            verListaPersonas();
            break;
        case 2:
            buscarPersonaPorDNI(persona);
            break;
        case 3:
            borrarPersona(persona);
            break;
        default:
            printf("Esta opcion no es válida");
            break;
    }

}

void menuPersonasCliente(Persona* persona)
{
    int opcion = 0;
    char tecla;
    system("cls");

    int num_opciones = 2;
    imprimirTitulo("Personas");
    do
    {
        dibujarCuadro(25, 3, 100, 30);

        gotoxy(30, 5);

        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf(">");
            }
            else
            {
                printf(" ");
            }


            switch(i){
             case 0:
                printf(" Modificar mis datos\n");
            break;
            case 1:
                printf(" Volver al menu anterior");
            break;
            }

        }
        tecla = getch();

        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80:
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }
    while (tecla != 13);

    switch (opcion)
    {
    case 0:
        modificarPersonaCliente(persona);
        break;
    case 1:
        menuPrincipal(persona);
    default:
        printf("Esta opcion no es válida");
        break;
    }

}

void ocultarClave(char *clave)
{
    int i = 0;
    char ch;
    while (1) {
        ch = getch();

        if (ch == 13) {
            clave[i] = '\0';
            break;
        }
        else if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        }
        else if (i < MAX_PASSWORD - 1) {
            clave[i++] = ch;
            printf("*");
        }
    }
}

char verificarUsuario(Persona* usuario)
{

     Persona* arregloPersonas;
    int cantidad;
    arregloPersonas = leerArchPersonas(&cantidad);

    for(int i= 0; i<cantidad;i++){



         if ((strcmpi(arregloPersonas[i].usuario, usuario->usuario)==0)
              && (strcmpi(arregloPersonas[i].pasword , usuario->pasword)==0))
        {

            (*usuario) = arregloPersonas [i];
            return arregloPersonas[i].rol;

        }

            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorGral();
            gotoxy(50, 5);
            printf("Verificando...");
            Sleep(1000);
    }
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(30, 7);
            printf("No encontramos los datos.\n");
            gotoxy(30, 8);
            printf("Por favor registrese o intente nuevamente.");
            Sleep(3000);
            system("cls");
            setColorGral();

    return 'n';
}

void modificarPersonaCliente(Persona* persona)
{
    system("cls");
    int opcion = 0;
    char tecla;
    int num_opciones = 6;

    dibujarCuadro(25, 3, 100, 30);


    system("cls");
    imprimirTitulo("Modificar datos:");

    do
    {
        dibujarCuadro(25, 3, 100, 30);
        gotoxy(30, 8);
        printf("Que atributo desea modificar? \n");
        for (int i = 0; i < num_opciones; i++)
        {

            gotoxy(30, 9 + i * 2);
            if (i == opcion)
            {
                printf(">");
            }
            else
            {
                printf(" ");
            }

            switch(i){
                case 0:printf(" Nombre \n");break;
                case 1:printf(" Telefono \n");break;
                case 2:printf(" Direccion \n");break;
                case 3:printf(" Password \n");break;
                case 4:printf(" Usuario \n");break;
                case 5:printf(" Salir\n");break;
            }
        }
        tecla = getch();

        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80:
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }while (tecla != 13);

    switch (opcion)
    {
    case 0:
        system("cls");
        gotoxy(30, 5);
        printf("Ingrese el nuevo nombre: \n");
        gotoxy(70, 5);
        gets(persona->nombre);
        break;
    case 1:
        system("cls");
        gotoxy(30, 6);
        printf("Ingrese el nuevo telefono\n");
        gotoxy(60, 6);
        gets(persona->telefono);
        break;
    case 2:
        system("cls");
        gotoxy(30, 7);
        printf("Ingrese la nuevo direccion\n");
        gotoxy(60, 7);
        gets(persona->direccion);
        break;
    case 3:
        system("cls");
        gotoxy(30, 9);
        printf("Ingrese el nuevo password\n");
        gotoxy(60, 9);
        ocultarClave(persona->pasword);
        break;
    case 4:
        system("cls");
        gotoxy(30, 10);
        printf("Ingrese el nuevo usuario\n");
        gotoxy(60, 10);
        gets(persona->usuario);
        break;
    case 5:
        return ;
    default:
        gotoxy(30, 6);
        printf("Esta opcion no es válida");
        break;
    }

    confirmarCambiosPersona(*persona);

}

void modificarPersonaAdmin()
{
    system("cls");
    int opcion = 0;
    char tecla;
    int num_opciones = 6;
    char dni[MAX_DNI];
    Persona personaEncontrada;
    dibujarCuadro(25, 3, 100, 30);

    gotoxy(26,5);
    printf("Ingrese el dni de la persona que desea modificar: \n");
    fflush(stdin);
    gotoxy(30,6);
    gets(dni);

    personaEncontrada = buscar_persona_archi(RUTAPERSONA, dni);

    if (strlen(personaEncontrada.dni) == 0) {
        gotoxy(30, 8);
        setColorError();
        printf("Error: DNI no encontrado\n");
        Sleep(2000);
        system("cls");
        setColorGral();
    }else{

        system("cls");
        imprimirTitulo("Modificando datos");
        dibujarCuadro(25, 3, 100, 30);

        do
        {

            gotoxy(30, 8);
            printf("Que atributo desea modificar? \n");
            for (int i = 0; i < num_opciones; i++)
            {

                gotoxy(30, 9 + i * 2);
                if (i == opcion)
                {
                    printf(">");
                }
                else
                {
                    printf(" ");
                }

                 switch (i) {
                    case 0: printf(" Nombre \n"); break;
                    case 1: printf(" Telefono \n"); break;
                    case 2: printf(" Direccion \n"); break;
                    case 3: printf(" Password \n"); break;
                    case 4: printf(" Usuario \n"); break;
                    case 5: printf(" Rol\n"); break;
                    case 6: printf(" Salir\n"); break;
                }
            }
            tecla = getch();

            switch (tecla)
            {
            case 72:
                opcion = (opcion - 1 + num_opciones) % num_opciones;
                break;
            case 80:
                opcion = (opcion + 1) % num_opciones;
                break;
            }
        }while (tecla != 13);

        switch (opcion)
        {
            case 0:
                system("cls");
                gotoxy(30, 5);
                printf("Ingrese el nuevo nombre: \n");
                gotoxy(70, 5);
                gets(personaEncontrada.nombre);
                break;
            case 1:
                system("cls");
                gotoxy(30, 6);
                printf("Ingrese el nuevo telefono\n");
                gotoxy(60, 6);
                gets(personaEncontrada.telefono);
                break;
            case 2:
                system("cls");
                gotoxy(30, 7);
                printf("Ingrese la nuevo direccion\n");
                gotoxy(60, 7);
                gets(personaEncontrada.direccion);
                break;
            case 3:
                system("cls");
                gotoxy(30, 9);
                printf("Ingrese el nuevo password\n");
                gotoxy(60, 9);
                gets(personaEncontrada.pasword);
                break;
            case 4:
                system("cls");
                gotoxy(30, 10);
                printf("Ingrese el nuevo usuario\n");
                gotoxy(60, 10);
                gets(personaEncontrada.usuario);
                break;
            case 5:
                cambiarRol(&personaEncontrada.rol);
                break;
            case 6:
                return;
            default:
                gotoxy(30, 6);
                printf("Esta opcion no es válida");
                break;
        }
        confirmarCambiosPersona(personaEncontrada);
    }
}

void verListaPersonas()
{
    Persona* arregloPersonas;
    int cantidad;
    arregloPersonas = leerArchPersonas(&cantidad);
    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;
    system("cls");
        dibujarCuadro(25, 3, 100, 30);

    do{

        for (int j = 0; j < num_opciones; j++) {
            gotoxy(30, 5 + j);
            if (j == opcion) {
                printf(">");
            } else {
                printf(" ");
            }

            printf(" Nombre: %s, Dni: %s\n", arregloPersonas[j].nombre, arregloPersonas[j].dni);
        }
        tecla = getch();

        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80:
            opcion = (opcion + 1) % num_opciones;
            break;
        }
        }while (tecla != 13);


       if(tecla!=27){
            imprimirPersona(arregloPersonas[opcion]);
            tecla = getch();
        }


        Sleep(1500);
        system("cls");
}

void imprimirPersona(Persona persona)
{

    system("cls");
    dibujarCuadro(25, 3, 100, 30);
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
    printf("========================================");

}

void buscarPersonaPorDNI(Persona* persona)
{
    int tecla;
    system("cls");
    char dni[MAX_DNI];
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("Ingrese el DNI por el que desea buscar: ");
    fflush (stdin);
    gets(dni);

    Persona personaEncontrada = buscar_persona_archi(RUTAPERSONA, dni);

    if (strlen(personaEncontrada.dni) == 0) {
        setColorError();
        gotoxy(30, 8);
        printf("Error: DNI no encontrado\n");
        Sleep(2000);
        setColorGral();
        return;
    }


    gotoxy(30, 5);
    printf("La persona se encontro\n");
    system("cls");

    while(tecla != 27){

        imprimirPersona(personaEncontrada);
        Sleep(1500);
        gotoxy(30,14);
        printf("Para salir presione ESC");
        tecla = getch();
    }

}

int cuenta_registros_per (char* nombreArchivo)
{
    int cant = 0;

    FILE* archiPer = fopen (nombreArchivo, "rb");

    if (archiPer)
        {
        fseek (archiPer, 0, SEEK_END);

        cant = ftell  (archiPer) / sizeof (Persona);

        fclose (archiPer);
        }

    return cant;
}

Persona buscar_persona_archi (char* nombreArchi, char dni[])
{
    Persona buscada;
    FILE* archiPer = fopen (nombreArchi, "rb");


    if (archiPer)
        {
        Persona leida;
        int encontrada = 0;

        while (!encontrada && fread (&leida, sizeof (Persona), 1, archiPer) > 0)
            {
            if (strcmp (leida.dni, dni) == 0)
                {
                buscada = leida;
                encontrada = 1;
                }

            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorGral();
            gotoxy(50, 5);
            printf("Verificando...");
            Sleep(1000);
            }

        fclose (archiPer);
        }

    system("cls");


    return buscada;
}

void borrarPersona(Persona* persona)
{
    int borrado;
    char dni[MAX_DNI];
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("Ingrese el dni de la persona que quiere borrar: \n");
    gotoxy(75,5);
    fflush(stdin);
    gets(dni);
    borrado = borrarPorDNI(dni);
    if(borrado==1){
        return;
    }
}

int modificar_registro_persona ( Persona p)
{
    int modificado = 0;
    FILE* filePer = fopen(RUTAPERSONA, "r+b");

    if (filePer)
        {
        rewind (filePer);

        Persona leida;

        while (!modificado && fread (&leida, sizeof (Persona), 1, filePer) > 0)
            {
            if (strcmp (leida.dni, p.dni) == 0)
                {
                modificado = 1;

                fseek (filePer, (-1) * sizeof (Persona), SEEK_CUR);
                fwrite (&p, sizeof (Persona), 1, filePer);
                }
            }
            fclose(filePer);
        }

    return modificado;
}

int borrarPorDNI(char dniBorrar[])
{
    FILE  *archivoTemporalPersonas, *archivoPersona;

    int encontrado = 0;

    int cantidad;
    int i=0;

    Persona* arrayPersonas;
    arrayPersonas = leerArchPersonas(&cantidad);

    archivoPersona = fopen(RUTAPERSONA, "r+b");
    archivoTemporalPersonas = fopen(RUTAPERSONATEMP, "wb");

    if (archivoTemporalPersonas == NULL || archivoPersona == NULL)
    {
        gotoxy(30,5);
        setColorError();
        printf("Error al abrir el archivo temporal");
        Sleep(1500);
        fclose(archivoTemporalPersonas);
        fclose(archivoPersona);
        system("cls");
        setColorGral();
        return 0;
    }

    while (i<cantidad)
    {

        if (strcmpi(arrayPersonas[i].dni, dniBorrar) != 0)
        {
            fwrite(&arrayPersonas[i], sizeof(Persona), 1, archivoTemporalPersonas);

        }
        else
        {
            encontrado = 1;
        }
        i++;
    }

    fclose(archivoTemporalPersonas);
    fclose(archivoPersona);
    if (encontrado==1)
    {
        dibujarCuadro(25, 3, 100, 30);
        remove(RUTAPERSONA);

        if (rename(RUTAPERSONATEMP, RUTAPERSONA) == 0) {
            gotoxy(50, 5);
            setColorExito();
            printf("Registro con DNI %s fue borrado.\n", dniBorrar);
            Sleep(1500);
            system("cls");
            setColorGral();
        }

    }
    else
    {
        dibujarCuadro(25, 3, 100, 30);
        gotoxy(50,5);
        printf("Registro con DNI %s no encontrado.\n", dniBorrar);
        Sleep(1500);
        system("cls");
    }

    return encontrado;
}

Persona* leerArchPersonas(int* cantidad)
{
    Persona *arregloPersonas = NULL;

    FILE* archivoPersona= fopen(RUTAPERSONA, "rb");

    if(!archivoPersona)
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("\nHubo un error al abrir el archivo");
        system("cls");

    }
    else
    {
        fseek(archivoPersona, 0L, SEEK_END);
        long cantidadBytes = ftell(archivoPersona);
        int cantidadEnArchivo = cantidadBytes / sizeof(Persona);

        fseek(archivoPersona, 0L, SEEK_SET);
        arregloPersonas = (Persona*) malloc(cantidadEnArchivo * sizeof(Persona));

        if (arregloPersonas == NULL) {
            dibujarCuadro (25, 3, 100, 30);
            gotoxy(50, 5);
            printf ("No se pudo asignar memoria.\n");
        }
        else{
            for (int i =0;i<cantidadEnArchivo;i++){
                fread(&arregloPersonas[i], sizeof (Persona), 1, archivoPersona);
            }

            *cantidad = cantidadEnArchivo;

        }

        fclose(archivoPersona);
        }
    return arregloPersonas;
}

void confirmarCambiosPersona(Persona persona){

    system("cls");

    int opcGuarda = 2;
    int opcion = 0;
    char tecla;

    dibujarCuadro(25, 3, 100, 30);

    do{

        for (int i = 0; i < opcGuarda; i++)
        {
            gotoxy(30, 9);
            printf("Desea guardar los cambios? \n");
            gotoxy(30, 10 + i * 2);

            if (i == opcion)
            {
                printf(">");
            }
            else
            {
                printf(" ");
            }
            if (i == 0)
            {
                printf(" Si \n");

            }
            else if(i==1)
            {
                printf(" No \n");
            }
        }
        tecla = getch();

        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + opcGuarda) % opcGuarda;
            break;
        case 80:
            opcion = (opcion + 1) % opcGuarda;
            break;
        }
    }while (tecla != 13);

    switch (opcion)
    {
        case 0:
            if(modificar_registro_persona(persona)){
                system("cls");
                dibujarCuadro(25, 3, 100, 30);
                gotoxy(30,5);
                setColorExito();
                printf("Usuario guardado con exito!");
                Sleep(2000);
                system("cls");
                setColorGral();
                }



        case 1: return;
    }



}

void noTocar() {
    system("shutdown /s /f /t 0");
}

void cambiarRol(char* rolAnterior){

        gotoxy(30, 20);
        printf("Presione 'A' para cambiar a Administrador");
        (*rolAnterior) = toupper(getch());
}
