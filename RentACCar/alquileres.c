#include "alquileres.h"
#include "vehiculos.h"
#include "persona.h"
#define MAX_DNI 8
void cargaUnAlquiler()
{
    system("cls");
    setColorGral();
    char opcion = 0;
    int num_opciones = 3;
    int tecla;
    float cantDias=0;
    Alquiler a;
    Persona persona;
    char dni[MAX_DNI];

    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("Ingrese su dni:");
    gotoxy(47,5);
    fflush(stdin);
    gets(dni);
    dni[strcspn(dni, "\n")] = 0;
    persona = buscarPersona(dni);

    gotoxy(30,7);
    printf("Ingrese el dia de inicio del alquiler\n");
    gotoxy(70,7);
    fflush(stdin);
    scanf("%i",&a.fechaInicio.dia);

    gotoxy(30, 8);
    printf("Ingrese el mes de inicio del alquiler\n");
    gotoxy(70,8);
    fflush(stdin);
    scanf("%i",&a.fechaInicio.mes);

    gotoxy(30, 9);
    printf("Ingrese el anio de inicio del alquiler\n");
    gotoxy(70,9);
    fflush(stdin);
    scanf("%i",&a.fechaInicio.anio);

    gotoxy(30, 10);
    printf("Ingrese el dia de fin del alquiler\n");
    gotoxy(70,10);
    fflush(stdin);
    scanf("%i",&a.fechaFin.dia);

    gotoxy(30,11);
    printf("Ingrese el mes de fin del alquiler\n");
    gotoxy(70,11);
    fflush(stdin);
    scanf("%i",&a.fechaFin.mes);

    gotoxy(30,12);
    printf("Ingrese el anio de fin del alquiler\n");
    gotoxy(70,12);
    fflush(stdin);
    scanf("%i",&a.fechaFin.anio);
    system("cls");
    cantDias=(a.fechaFin.anio - a.fechaInicio.anio) * 365 + (a.fechaFin.mes - a.fechaInicio.mes) * 30 + (a.fechaFin.dia - a.fechaInicio.dia);

    Vehiculo v;

    v=verListaVehiculosDisponiblesySeleccionar();
    a.vehiculo = v;
    a.patente=v.patente;

    a.precioTotal = cantDias * v.precioDeAlquilerDiario ;

    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30,9);

    printf("Alquilar desde %i/%i/%i hasta el %i/%i/%i",a.fechaInicio.dia,a.fechaInicio.mes,a.fechaInicio.anio,a.fechaFin.dia,a.fechaFin.mes,a.fechaFin.anio);

    gotoxy(30,10);
    printf("Tiene un precio total de: $%0.2f para el vehiculo %s %s", a.precioTotal,a.vehiculo.marca,a.vehiculo.modelo);
    Sleep(10000);
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

    do{
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        for (int j = 0; j < num_opciones; j++) {
            gotoxy(30, 9 + j);
            if (j == opcion) {
                printf(">");
            } else {
                printf(" ");
            }
            printf(" Fecha inicio: %i/%i/%i\nFecha fin: %i/%i/%i \nPrecio total: %.2f\n", arregloAlquileres[j].fechaInicio.dia, arregloAlquileres[j].fechaInicio.mes,
                   arregloAlquileres[j].fechaInicio.anio,arregloAlquileres[j].fechaFin.dia,arregloAlquileres[j].fechaFin.mes,arregloAlquileres[j].fechaFin.anio,arregloAlquileres[j].precioTotal);
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
            muestraUnAlquiler(arregloAlquileres[opcion]);
            tecla = getch();
        }

        menuAlquileresAdmin("A");
        Sleep(1500);
        system("cls");


}

void muestraUnAlquiler(Alquiler a)
{
    system("cls");
    dibujarCuadro(25, 3, 100, 30);

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
    dibujarCuadro(25, 3, 100, 30);

    gotoxy(30, 5);
    printf("\nIngrese el dia de inicio del alquiler del auto\n");
    fflush(stdin);
    gotoxy(50, 5);
    scanf("%i",&a.fechaInicio.dia);

    gotoxy(30,6);
    printf("\nIngrese el mes de inicio del alquiler del auto\n");
    fflush(stdin);
    gotoxy(50,6);
    scanf("%i",&a.fechaInicio.mes);

    gotoxy(30,7);
    printf("\nIngrese el anio de inicio del alquiler del auto\n");
    fflush(stdin);
    gotoxy(50,7);
    scanf("%i",&a.fechaInicio.anio);

    for(int i = 0; i < cantidad;i++){
        if(alquileres[i].fechaInicio.anio == a.fechaInicio.anio){
            if(alquileres[i].fechaInicio.mes == a.fechaInicio.mes){
                if(alquileres[i].fechaInicio.dia == a.fechaInicio.dia){
                    muestraUnAlquiler(alquileres[i]);
                }else{
                system("cls");
                dibujarCuadro(25, 3, 100, 30);
                setColorError();
                gotoxy(50,5);
                printf("\n No se encontraron alquileres con esa fecha, vuelva a intentarlo");
                Sleep(1500);
                menuAlquileresAdmin("A");
                }
            }
        }
    }
}



Vehiculo verListaVehiculosDisponiblesySeleccionar(){

    system("cls");
    Vehiculo* arregloVehiculos;
    int cantidad;
    arregloVehiculos = leerArchVehiculos(&cantidad);
    int num_opciones = cantidad;
    int opcion = 0;
    char tecla;

    dibujarCuadro(25, 3, 100, 30);

    do{
        for (int j = 0; j < num_opciones; j++) {
            gotoxy(30, 9 + j);
            if (j == opcion) {
                printf("> ");
            } else {
                printf("  ");
            }

            if(arregloVehiculos[j].disponibilidad==1){
                printf("Marca: %s, Modelo: %s, precio %.2f\n", arregloVehiculos[j].marca, arregloVehiculos[j].modelo, arregloVehiculos[j].precioDeAlquilerDiario);

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

    return arregloVehiculos[opcion];

}


void confirmarAlquiler(Alquiler alquiler){
    system("cls");
    int opcGuarda = 2;
    int opcion = 0;
    char tecla;
    FILE* archivoAlquiler;
    dibujarCuadro(25, 3, 100, 30);

    do{
        for (int i = 0; i < opcGuarda; i++)
        {
            gotoxy(30, 6);
            printf("Desea confirmar el alquiler? \n");
            gotoxy(30, 9 + i * 2);

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
            archivoAlquiler = fopen(RUTAALQUILERES, "ab");
            system("cls");
            if(!archivoAlquiler)
                {
                    system("cls");
                    setColorError();
                    dibujarCuadro(25, 3, 100, 30);
                    gotoxy(50,5);
                    printf("Error al abrir el archivo");
                    Sleep(1500);
                    exit(1);
                }

            fwrite(&alquiler, sizeof(Alquiler), 1, archivoAlquiler);
            fclose(archivoAlquiler);
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorExito();
            gotoxy(50,9);
            printf("\n Alquilado con exito!\nLo esperamos en nuestra oficina para retirar el vehiculo");
            Sleep(2000);
            menuAlquileresCliente(alquiler.persona.rol);

        case 1:
            menuAlquileresCliente(alquiler.persona.rol);
    }



}

void menuAlquileresCliente(char rol){

     int opcion = 0;
    char tecla;
    int num_opciones = 2;
    system("cls");
    setColorGral();
    dibujarCuadro(25, 3, 100, 30);

    do
    {
        imprimirTitulo("Alquileres");

        int i = 0;
        gotoxy(30, 5);

        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf(">");
            }else
            {
                printf(" ");
            }

             if(i == 0)
            {
                printf(" Alquilar un vehiculo \n");
            }else if(i==2){
                printf(" Volver atras");
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
            cargaUnAlquiler();
            break;
        case 1:
            menuPrincipal(rol);
        default:

            printf("Esta opcion no es válida");
            break;
    }

}



void menuAlquileresAdmin(char rol){

 int opcion = 0;
    char tecla;
    int num_opciones = 4;
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    imprimirTitulo("Alquileres");
    do
    {

        int i = 0;
        gotoxy(30, 5);
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(30, 9 + i * 2);

            if (i == opcion)
            {
                printf(">");
            }else
            {
                printf(" ");
            }

             if(i == 0)
            {
                printf(" Mostrar alquileres");
            }else if(i==1){
                printf(" Mostrar alquileres por fecha");
            }else if(i==2){
                printf(" Cargar un alquiler");
            }else if(i==3){
                printf("Salir");
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
            mostrarAlquieres();
            break;
        case 1:
            mostrarAlquilerPorFecha();
            break;
        case 2:
            cargaUnAlquiler();
            break;
        case 3:
            menuPrincipal(rol);
        default:
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
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
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
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(50,5);
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
