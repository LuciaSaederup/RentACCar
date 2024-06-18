#include "vehiculos.h"
#include <conio.h>
#include <windows.h>
#include "gotoxy.h"

#define MAX_LETRAS_PATENTE 3
void menuVehiculos()
{
    system("cls");
    int opcion;
    int num_opciones = 3;
    int tecla;
    dibujarCuadro(25, 3, 100, 30);
    setColorGral();

    do
    {



        gotoxy(30, 5);
        printf("====================================================\n");
        gotoxy(30, 6);
        printf("                       Vehiculos                   \n");
        gotoxy(30, 7);
        printf("====================================================\n");

        int i = 0;
        gotoxy(30, 5);
        // Mostrar opciones
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf("> "); // Resalta la opción actual
            }
            else
            {
                printf("  ");
            }
            if(i==0){
               printf("Cargar un nuevo vehiculo\n");
            }else if(i ==1){
                printf("Ver Vehiculos disponibles\n");
            }else if(i==2){
                printf("Modificar un vehiculo\n");

            }else if(i==3){
                printf("Volver al menu anterior");
            }
        }
        tecla = getch();

        switch (tecla)
        {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % num_opciones;
            break;
        }
    }while (tecla != 13);

        switch(opcion)
        {
            case 0:
            {
                cargaUnVehiculo();
                break;
            }
            case 1:
            {
                muestraVehiculosDisponibles();
                break;
            }
            case 2:
            {
                modificarVehiculo();
                break;
            }
            default:
                // Opción no válida
                printf("Esta opcion no es válida");
                break;
        }

}


void cargaUnVehiculo()
{
     system("cls");
     FILE *archivo;
    archivo=fopen(RUTAVEHICULOS,"ab");
    char opcion = 0;
    int flagTipo = 0;
    int num_opciones = 3;
    int tecla;
    Vehiculo v;

    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("Ingrese la marca del vehiculo:");
    fflush(stdin);
    gotoxy(70, 5);
    gets(v.marca);

    gotoxy(30, 7);
    printf("Ingrese el modelo:");
    gotoxy(57, 7);
    fflush(stdin);
    gets(v.modelo);

    gotoxy(30, 8);
    printf("Ingrese el anio:");
    gotoxy(47, 8);
    fflush(stdin);
    scanf("%i", &v.anio);

    gotoxy(30, 9);
    printf("Ingrese los Kms que tiene el vehiculo:");
    gotoxy(70, 9);
    fflush(stdin);
    scanf("%i", &v.kms);

    gotoxy(30, 10);
    printf("Ingrese el precio del alquiler diario:");
    gotoxy(70, 10);
    fflush(stdin);
    scanf("%f", &v.precioDeAlquilerDiario);

    char tipoVehiculo[MAX_TIPO_VEHIC];
    ingresarTipoVehiculo(&tipoVehiculo);

    Sleep(1500);
    strcpy(v.tipoVehiculo, tipoVehiculo);
    gotoxy(30, 18);
    printf("Ingrese las letras de la patente:");
    gotoxy(70, 18);
    fflush(stdin);
    fgets(v.patente.letras, MAX_LETRAS_PATENTE + 1, stdin);
    validarLetrasPatente(v.patente);

    gotoxy(30, 19);
    printf("Ingrese los numeros de la patente:");
    gotoxy(70, 19);
    fflush(stdin);
    gets(v.patente.numeros);
    validarNumerosPatente(v.patente);

    gotoxy(30, 20);
    printf("El vehiculo se cargara como DISPONIBLE (1).\nEn caso de querer cambiarlo, se carga");
    v.disponibilidad = 1;
    if(archivo!=NULL)
    {
    fwrite(&v,sizeof(Vehiculo),1,archivo);
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    setColorExito();
    gotoxy(30,21);
    printf("Vehiculo cargado con exito!");
    Sleep(1500);
    system("cls");
    menuVehiculos();
    }
    else
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(30,5);
        printf("\nError al abrir el archivo");
    }
    fclose(archivo);
}


void muestraVehiculosDisponibles()
{
    system("cls");
   Vehiculo* arregloVehiculos;
    int cantidad;
    arregloVehiculos = leerArchVehiculos(&cantidad);
    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;
    int i =20;
    int f = 9;
    dibujarCuadro(25, 3, 100, 30);

    do{
        for (int j = 0; j < num_opciones; j++) {
            gotoxy(i, f + j);
            if (j == opcion) {
                printf("> "); // Resalta la opción actual
            } else {
                printf("  ");
            }
            // Print name and DNI
            if(arregloVehiculos[j].disponibilidad==1){
                printf("Marca: %s, Modelo: %s, precio %.2f\n", arregloVehiculos[j].marca, arregloVehiculos[j].modelo, arregloVehiculos[j].precioDeAlquilerDiario);

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

        if(tecla!=27){
            system("cls");
            muestraVehiculo(arregloVehiculos[opcion]);
            Sleep(1500);
            gotoxy(30, 15);
            printf("Presione ESC para volver al menu");
            tecla = getch();
        }

        menuVehiculos();
        system("cls");


}

void muestraVehiculo(Vehiculo vehiculo)
{

    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("========================================");

    gotoxy(30, 6);
    printf("Marca: %s", vehiculo.marca);

    gotoxy(30, 7);
    printf("Modelo: %s", vehiculo.modelo);

    gotoxy(30, 8);
    printf("Anio: %i", vehiculo.anio);

    gotoxy(30, 9);
    printf("Kms: %i", vehiculo.kms);

    gotoxy(30, 10);
    printf("Precio de alquiler diario: %.2f", vehiculo.precioDeAlquilerDiario);

    gotoxy(30, 11);
    printf("Tipo Vehiculo: %s", vehiculo.tipoVehiculo);

    gotoxy(30, 12);

    printf("Patente: %s", strcat(vehiculo.patente.letras,vehiculo.patente.numeros));

    gotoxy(30, 13);
    printf("========================================");

}

void modificarVehiculo()
{
    system("cls");
    int opcion = 0;
    char tecla;
    int num_opciones = 6;
    Vehiculo vehiculo;
    char patente[6];
    dibujarCuadro(25, 3, 100, 30);

    gotoxy(30,5);
    printf("Antes de modificar la informacion del vehiculo debera validar la patente: \n");
    gotoxy(50,6);
    fflush(stdin);
    fgets(patente, 6, stdin);

    size_t len = strlen(patente);
    if (len > 0 && patente[len-1] == '\n') {
        patente[len-1] = '\0';
    }

    vehiculo= buscarPatente(patente);
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    do
    {

        gotoxy(30, 5);
        printf("Que atributo desea modificar? \n");
        for (int i = 0; i < num_opciones; i++)
        {

            gotoxy(30, 8 + i * 2);
            if (i == opcion)
            {
                printf("> "); // Resalta la opción actual
            }
            else
            {
                printf("  ");
            }

            if (i == 0)
            {
                printf("Marca \n");
            }
            else if(i == 1)
            {
                printf("Modelo \n");
            }
            else if(i == 2)
            {
                printf("Tipo Vehiculo \n");
            }
            else if(i == 3)
            {
                printf("Anio \n");
            }
            else if(i == 4)
            {
                printf("Kms \n");
            }else if(i==5){
                printf("Volver atras");
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
    }while (tecla != 13);

     switch (opcion)
    {
        case 0:
            system("cls");
            gotoxy(30, 5);
            printf("Ingrese la nueva marca: \n");
            gotoxy(70, 5);
            gets(vehiculo.marca);
            break;
        case 1:
            system("cls");
            gotoxy(30, 6);
            printf("Ingrese el nuevo modelo\n");
            gotoxy(60, 6);
            gets(vehiculo.modelo);
            break;
        case 2:
            system("cls");
            gotoxy(30, 7);
            char tipoVehiculo[MAX_TIPO_VEHIC];
            ingresarTipoVehiculo(&tipoVehiculo);
            Sleep(1500);
            strcpy(vehiculo.tipoVehiculo, tipoVehiculo);
            break;
        case 3:
            system("cls");
            gotoxy(30, 8);
            printf("Ingrese los anios\n");
            gotoxy(60, 8);
            gets(vehiculo.anio);
            break;
        case 4:
            system("cls");
            gotoxy(30, 9);
            printf("Ingrese los kms\n");
            gotoxy(60, 9);
            gets(vehiculo.kms);
            break;
        case 5:
            menuVehiculos();
        default:
            gotoxy(30, 6);
            printf("Esta opcion no es válida");
            break;
    }
    confirmarCambiosVehiculo(vehiculo);
}


void busquedaPorPatente()
{

     system("cls");
    char patente[6];
    dibujarCuadro(25, 3, 100, 30);

    gotoxy(30, 5);
    printf("Ingrese la patente por la que desea buscar: ");
    fgets(patente, 6, stdin);

    size_t len = strlen(patente);
    if (len > 0 && patente[len-1] == '\n') {
        patente[len-1] = '\0';
    }

    Vehiculo vehiculo= buscarPatente(patente);

    if(strcmpi(strcat(vehiculo.patente.letras,vehiculo.patente.numeros), patente))
   {
       system("cls");
       dibujarCuadro(25, 3, 100, 30);
       setColorExito();
        gotoxy(30, 5);
        printf("La persona se encontro: \n");
        Sleep(1500);
        system("cls");
        muestraVehiculo(vehiculo);

   }

}

Vehiculo buscarPatente(char patente){
    Vehiculo* arregloVehiculos;
    int cantidad;
    arregloVehiculos = leerArchVehiculos(&cantidad);
    char patenteArreglo;

    for(int i = 0; i<cantidad; i++)
    {
        patenteArreglo = strcat(arregloVehiculos[i].patente.letras, arregloVehiculos[i].patente.numeros);

        if(strcmpi(patenteArreglo, patente)== 0)
        {

            return arregloVehiculos[i];
        }
    }

}

Vehiculo* leerArchVehiculos(int* cantidad){

    FILE* archivoVehiculos= fopen(RUTAVEHICULOS, "rb");

    if(!archivoVehiculos)
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("\nHubo un error al abrir el archivo");
        exit(1);
    }
    else
    {
        fseek(archivoVehiculos, 0L, SEEK_END);
        long cantidadBytes = ftell(archivoVehiculos);
        int cantidadEnArchivo = cantidadBytes / sizeof(Vehiculo);

        fseek(archivoVehiculos, 0L, SEEK_SET);
        Vehiculo *arregloVehiculos;
        arregloVehiculos = (Vehiculo*) malloc(cantidadEnArchivo * sizeof(Vehiculo));

        if (arregloVehiculos == NULL) {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(50,5);
            printf("No se pudo asignar memoria.\n");
            fclose(archivoVehiculos);
            return NULL;
        }

        for (int i = 0; i < cantidadEnArchivo; i++) {
            fread(&arregloVehiculos[i], sizeof(Vehiculo), 1, archivoVehiculos);
        }

        *cantidad = cantidadEnArchivo;
        fclose(archivoVehiculos);
        return arregloVehiculos;

        }

}


int validarLetrasPatente(Patente patente) {
    int len = strlen(patente.letras);

    if (len != 3) {
        gotoxy(30,22);
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("\Las letras no son correctas, debería ingresar 3 letras.\n");
        Sleep(1500);
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isalpha(patente.letras[i])) {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(50,5);
            printf("\nLas letras no son correctas, solo debe ingresar letras\n");
            Sleep(1500);
            return 0;
        }
    }

    return 1;
}

int validarNumerosPatente(Patente patente) {
    int len = strlen(patente.numeros);

    if (len != 3) {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("\Los numeros no son correctos, debería ingresar 3 números.\n");
        Sleep(1500);
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isdigit(patente.numeros[i])) {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(50,5);
            printf("\nLos numeros no son correctos, solo debe ingresar numeros.\n");
            Sleep(1500);
            return 0;
        }
    }

    return 1;
}

void ingresarTipoVehiculo(char* tipo){

    int num_opciones = 3;
    int tecla;
    int opcion;
    char* tipoVehiculo[MAX_TIPO_VEHIC];
    do{
        gotoxy(30,11);
        printf("Ingrese el tipo del auto: ");
        for (int i = 0; i < num_opciones; i++) {
            gotoxy(31, 12 + i);

            if (i == opcion) {
                printf("> "); // Resalta la opción actual
            } else {
                printf("  ");
            }
            if (i == 0) {
                printf("Auto");
            } else if (i == 1) {
                printf("Camioneta");
            } else if (i == 2) {
                printf("Utilitario");
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
    } while (tecla != 13);

     switch (opcion) {
        case 0:
            *tipo= "Auto";
            break;
        case 1:
            strcpy(*tipo, "Camioneta");
            break;
        case 2:
            strcpy(*tipo, "Utilitario");
            break;
    }


}


void confirmarCambiosVehiculo(Vehiculo vehiculo){
    system("cls");
    int opcGuarda = 2;
    int opcion = 0;
    char tecla;
    FILE* archivoVehiculos;
    char  patenteVehic;
    dibujarCuadro(25, 3, 100, 30);


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
            patenteVehic = strcat(vehiculo.patente.letras, vehiculo.patente.numeros);

            borrarPorPatente(patenteVehic);

            archivoVehiculos = fopen(RUTAVEHICULOS, "ab");
            if(!archivoVehiculos)
                {
                    system("cls");
                    dibujarCuadro(25, 3, 100, 30);
                    setColorError();
                    gotoxy(50,5);
                    printf("Error al abrir el archivo");
                    exit(1);
                }

            fwrite(&vehiculo, sizeof(Vehiculo), 1, archivoVehiculos);
            fclose(archivoVehiculos);
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorExito();
            gotoxy(50,5);
            printf("\n Vehiculo modificado con exito!");
            Sleep(2000);
            menuVehiculos();

        case 1:
            menuVehiculos();
    }

}

int borrarPorPatente(char patente){
    FILE  *archivoTemporalVehiculos, *archivoVehiculos;

    Vehiculo vehiculo;
    int encontrado = 0;
    int cantidad;
    int i=0;
    Vehiculo* arregloVehiculos;
    arregloVehiculos = leerArchVehiculos(&cantidad);

    archivoVehiculos = fopen(RUTAVEHICULOS, "rb");
    archivoTemporalVehiculos = fopen(RUTAVEHICULOSTEMPORAL, "wb");

    if (archivoVehiculos == NULL || archivoTemporalVehiculos == NULL)
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("Error al abrir el archivo temporal");
        fclose(archivoTemporalVehiculos);
        fclose(archivoVehiculos);
        return 0;
    }

    // Lee los registros del archivo original y escribe en el archivo temporal
    while (i<cantidad)
    {
        char patenteArreglo = strcat(arregloVehiculos[i].patente.letras, arregloVehiculos[i].patente.numeros);

        if(strcmpi(patenteArreglo, patente)!= 0)
        {
            fwrite(&vehiculo, sizeof(Vehiculo), 1, archivoTemporalVehiculos);
        }
        else
        {
            encontrado = 1;
        }
        i++;
    }

    // Cierra ambos archivos
    fclose(archivoTemporalVehiculos);
    fclose(archivoVehiculos);

    // Si se encontró el registro a borrar, reemplaza el archivo original
    if (encontrado)
    {
        unlink(RUTAVEHICULOS);

        rename(RUTAVEHICULOSTEMPORAL, RUTAVEHICULOS);
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorExito();
        gotoxy(50,5);
        printf("Registro con patente %s fue borrado.\n", patente);
        Sleep(1500);
    }
    else
    {
        // Si no se encontró el registro, elimina el archivo temporal
        unlink(RUTAVEHICULOSTEMPORAL);
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("Registro con patente %s no encontrado.\n", patente);
    }

    return encontrado;



}
