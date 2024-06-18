#include "alquileres.h"
#include "vehiculos.h"
#include "persona.h"
#define MAX_DNI 8
void cargaUnAlquiler()
{
    system("cls");
    char opcion = 0;
    int flagTipo = 0;
    int num_opciones = 3;
    int tecla;
    float cantDias=0;
    Alquiler a;
    Persona persona;
    char dni[MAX_DNI];

    dibujarCuadro(23, 3, 75, 17);
    gotoxy(30, 5);
    printf("Ingrese su dni:");
    gotoxy(47,5);
    fflush(stdin);
    gets(dni);
    dni[strcspn(dni, "\n")] = 0;
    persona = buscarPersona(dni);

    gotoxy(30,7);
    printf("\nIngrese el dia de inicio del alquiler\n");
    gotoxy(50,7);
    fflush(stdin);
    scanf("%i",&a.fechaInicio.dia);

    gotoxy(30, 8);
    printf("\nIngrese el mes de inicio del alquiler\n");
    gotoxy(50,8);
    fflush(stdin);
    scanf("%i",&a.fechaInicio.mes);

    gotoxy(30, 9);
    printf("\nIngrese el anio de inicio del alquiler\n");
    gotoxy(50,9);
    fflush(stdin);
    scanf("%i",&a.fechaInicio.anio);

    gotoxy(30, 10);
    printf("\nIngrese el dia de fin del alquiler\n");
    gotoxy(50,10);
    fflush(stdin);
    scanf("%i",&a.fechaFin.dia);

    gotoxy(30,11);
    printf("\nIngrese el mes de fin del alquiler\n");
    gotoxy(50,11);
    fflush(stdin);
    scanf("%i",&a.fechaFin.mes);

    gotoxy(30,12);
    printf("\nIngrese el anio de fin del alquiler\n");
    gotoxy(50,12);
    fflush(stdin);
    scanf("%i",&a.fechaFin.anio);

    cantDias=(a.fechaFin.anio - a.fechaInicio.anio) * 365 + (a.fechaFin.mes - a.fechaInicio.mes) * 30 + (a.fechaFin.dia - a.fechaInicio.dia);

    Vehiculo v;

    v=verListaVehiculosDisponiblesySeleccionar();
    a.patente=v.patente;

    a.precioTotal = cantDias * v.precioDeAlquilerDiario ;
    printf("El precio total del alquiler es: %0.2f", a.precioTotal);

    confirmarAlquiler(a);


}


void mostrarAlquieres()
{
    Alquiler* arregloAlquileres;
    int cantidad;
    arregloAlquileres = leerArchAlquileres(&cantidad);

    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;

    int i =20;
    int f = 9;

    do{
        system("cls");
        // Mostrar opciones
        for (int j = 0; j < num_opciones; j++) {
            gotoxy(i, f + j);
            if (j == opcion) {
                printf("> "); // Resalta la opción actual
            } else {
                printf("  ");
            }
            // Print name and DNI
            printf("fecha inicio: %i/%i/%i\nfecha fin: %i/%i/%i \nprecio total: %ld\n", arregloAlquileres[j].fechaInicio.dia, arregloAlquileres[j].fechaInicio.mes,
                   arregloAlquileres[j].fechaInicio.anio,arregloAlquileres[j].fechaFin.dia,arregloAlquileres[j].fechaFin.mes,arregloAlquileres[j].fechaFin.anio,arregloAlquileres[j].precioTotal);
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
            muestraUnAlquiler(arregloAlquileres[opcion]);
            tecla = getch();
        }

        menuAlquileresAdmin();
        Sleep(1500);
        system("cls");


}

void muestraUnAlquiler(Alquiler a)
{
      system("cls");
    dibujarCuadro(27, 8, 70, 17); // Descomentar si tienes esta función definida

    gotoxy(30, 5);
    printf("========================================");

    gotoxy(30, 6);
    printf("\n Fecha de inicio: %d / %d / %d \n", a.fechaInicio.dia,a.fechaInicio.mes,a.fechaInicio.anio);

    gotoxy(30, 7);
    printf("\n Fecha de devolucion: %d / %d / %d \n", a.fechaFin.dia,a.fechaFin.mes,a.fechaFin.anio);


    gotoxy(30, 8);
    printf("\n Precio: %0.2f \n", a.precioTotal);

    gotoxy(30, 9);
    printf("\n DNI: %d \n", a.persona.dni);

    gotoxy(30, 10);
    printf("\n Patente vehiculo %s%s",a.patente.letras,a.patente.numeros);

    gotoxy(30, 11);
    printf("========================================");





}

void mostrarAlquilerPorFecha()
{

    int cantidad;
    Alquiler* alquileres;
    alquileres = leerArchAlquileres(&cantidad);
    Alquiler a;

    int dia=0;
    int mes=0;
    int anio=0;

    printf("\nIngrese el dia de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&dia);

    printf("\nIngrese el mes de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&mes);

    printf("\nIngrese el anio de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&anio);

    for(int i = 0; i < cantidad;i++){
        if(alquileres[i].fechaInicio.anio == anio){
            if(alquileres[i].fechaInicio.mes == mes){
                if(alquileres[i].fechaInicio.anio == anio){
                    muestraUnAlquiler(alquileres[i]);
                }
            }
        }else{
            printf("\n No se encontraron alquileres con esa fecha, vuelva a intentarlo");
            Sleep(1500);
            menuAlquileresAdmin();

        }

    }


}



Vehiculo verListaVehiculosDisponiblesySeleccionar(){

    Vehiculo* arregloVehiculos;
    int cantidad;
    arregloVehiculos = leerArchVehiculos(&cantidad);
    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;

    int i =20;
    int f = 9;

    do{
        system("cls");
        printf("\ESTOY EN ELEGIR");
        for (int j = 0; j < num_opciones; j++) {
                printf("estoy en el for");
            gotoxy(i, f + j);
            if (j == opcion) {
                printf("> "); // Resalta la opción actual
            } else {
                printf("  ");
            }
            // Print name and DNI
            if(arregloVehiculos[j].disponibilidad==1){
                printf("Marca: %s, Modelo: %s, precio %d\n", arregloVehiculos[j].marca, arregloVehiculos[j].modelo, arregloVehiculos[j].precioDeAlquilerDiario);

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

    return arregloVehiculos[opcion];

}


void confirmarAlquiler(Alquiler alquiler){

    int opcGuarda = 2;
    int opcion = 0;
    char tecla;
    FILE* archivoAlquiler;

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
    }while (tecla != 13);

    switch (opcion)
    {
        case 0:
            archivoAlquiler = fopen(RUTAALQUILERES, "ab");
            system("cls");
            if(!archivoAlquiler)
                {
                    printf("Error al abrir el archivo");
                    exit(1);
                }

            fwrite(&alquiler, sizeof(Alquiler), 1, archivoAlquiler);
            fclose(archivoAlquiler);
            printf("\n Alquilado con exito!\Lo esperamos en nuestra oficina para retirar el vehiculo");
            Sleep(2000);
            menuAlquileresCliente();

        case 1:
            menuAlquileresCliente();
    }



}

void menuAlquileresCliente(){

     int opcion = 0;
    char tecla;

    int num_opciones = 1;
    system("cls");

    do
    {
        dibujarCuadro(27, 4, 72, 20);
        gotoxy(30, 5);
        printf("========================================\n");
        gotoxy(30, 6);
        printf("                Alquileres                \n");
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
                printf("> "); // Resalta la opción actual
            }else
            {
                printf("  ");
            }

             if(i == 0)
            {
                printf("Alquilar un vehiculo \n");
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
    }
    while (tecla != 13);  // Salir con Enter

    switch (opcion)
    {
        case 0:
            cargaUnAlquiler();
            break;
        default:
            // Opción no válida
            printf("Esta opcion no es válida");
            break;
    }

}



void menuAlquileresAdmin(){

 int opcion = 0;
    char tecla;
    system("cls");
    system("cls");

    int num_opciones = 3;
    system("cls");

    do
    {
        dibujarCuadro(27, 4, 72, 20);
        gotoxy(30, 5);
        printf("========================================\n");
        gotoxy(30, 6);
        printf("                Alquileres                \n");
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
                printf("> "); // Resalta la opción actual
            }else
            {
                printf("  ");
            }

             if(i == 0)
            {
                printf("Mostrar alquileres");
            }else if(i==1){
                printf("Mostrar alquileres por fecha");
            }else if(i==2){
                printf("Cargar un alquiler");
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
    }
    while (tecla != 13);  // Salir con Enter

    switch (opcion)
    {
        case 0:
            mostrarAlquieres();
            break;
        case 1:
            mostrarAlquilerPorFecha();
            break;
        case 2:
            cargaUnAlquiler();
            break;
        default:
            // Opción no válida
            printf("Esta opcion no es válida");
            break;
    }

}




Alquiler* leerArchivoAlquileres(int* cantidad)
{
    FILE* archivoAlquileres= fopen(RUTAALQUILERES, "rb");
    int i = 0;
    if(!archivoAlquileres)
    {
        printf("\nHubo un error al abrir el archivo");
    }
    else
    {
        fseek(archivoAlquileres, 0L, SEEK_END);
        long cantidadBytes = ftell(archivoAlquileres);
        int cantidadEnArchivo = cantidadBytes / sizeof(Persona);
        Sleep(1500);

        fseek(archivoAlquileres, 0L, SEEK_SET);
        Alquiler *arregloAlquileres;
        arregloAlquileres = (Alquiler*) malloc(cantidadEnArchivo * sizeof(Alquiler));

        if (arregloAlquileres == NULL) {
            printf("No se pudo asignar memoria.\n");
            fclose(archivoAlquileres);
            return NULL;
        }

        for (int i = 0; i < cantidadEnArchivo; i++) {
            fread(&arregloAlquileres[i], sizeof(Persona), 1, archivoAlquileres);
        }

        *cantidad = cantidadEnArchivo;
        fclose(archivoAlquileres);
        return arregloAlquileres;

        }
}
