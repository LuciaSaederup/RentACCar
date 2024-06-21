#include "vehiculos.h"
#include "gotoxy.h"

#include "pantallaIngreso.h"



void menuVehiculos(Persona* persona)
{
    system("cls");
    int opcion;
    int num_opciones_admin = 5;
    int tecla;
    dibujarCuadro(25, 3, 100, 30);
    setColorGral();
    imprimirTitulo("Vehiculos");

        do
        {
            gotoxy(30, 5);
            for (int i = 0; i < num_opciones_admin; i++)
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
                case 0:printf(" Cargar un nuevo vehiculo\n");break;
                case 1:printf(" Ver Vehiculos disponibles\n");break;
                case 2:printf(" Modificar un vehiculo\n");break;
                case 3:printf(" Borrar un vehículo");break;
                case 4:printf(" Volver al menu anterior");break;
                }
            }
            tecla = getch();

            switch (tecla)
            {
            case 72:
                opcion = (opcion - 1 + num_opciones_admin) % num_opciones_admin;
                break;
            case 80:
                opcion = (opcion + 1) % num_opciones_admin;
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
                    modificarVehiculo(persona);
                    break;
                }
                case 3:
                    borrarVehiculo(persona);
                case 4:
                    return ;
                default:
                    printf("Esta opcion no es válida");
                    break;
            }



}


void cargaUnVehiculo()
{
     system("cls");
     FILE *archivo=fopen(RUTAVEHICULOS,"ab");

    if (!archivo)
    {
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("Error al abrir el archivo");
        Sleep(1500);
        system("cls");
    }else{

        setColorGral();
        Vehiculo v;

        dibujarCuadro(25, 3, 100, 30);
        gotoxy(30, 5);
        printf("Ingrese la marca del vehiculo:");
        fflush(stdin);
        gotoxy(60, 5);
        gets(v.marca);

        gotoxy(30, 7);
        printf("Ingrese el modelo:");
        gotoxy(60, 7);
        fflush(stdin);
        gets(v.modelo);

        gotoxy(30, 8);
        printf("Ingrese el anio:");
        gotoxy(60, 8);
        fflush(stdin);
        scanf("%i", &v.anio);

        gotoxy(30, 9);
        printf("Ingrese los Kms que tiene el vehiculo:");
        gotoxy(60, 9);
        fflush(stdin);
        scanf("%i", &v.kms);

        gotoxy(30, 10);
        printf("Ingrese el precio del alquiler diario:");
        gotoxy(60, 10);
        fflush(stdin);
        scanf("%f", &v.precioDeAlquilerDiario);

        ingresarTipoVehiculo(v.tipoVehiculo);

        Sleep(1500);
        gotoxy(30, 18);
        printf("Ingrese las letras de la patente:");
        gotoxy(60, 18);
        fflush(stdin);
        fgets(v.patente.letras, MAX_LETRAS_PATENTE, stdin);
        v.patente.letras[strcspn(v.patente.letras, "\n")] = '\0';
        validarLetrasPatente(v.patente);

        gotoxy(30, 19);
        printf("Ingrese los numeros de la patente:");
        gotoxy(60, 19);
        fflush(stdin);
        fgets(v.patente.numeros,MAX_NUMEROS_PATENTE, stdin);
        v.patente.numeros[strcspn(v.patente.numeros, "\n")] = '\0';
        validarNumerosPatente(v.patente);

        gotoxy(30, 20);
        printf("El vehiculo se cargara como DISPONIBLE (1).\nEn caso de querer cambiarlo, se carga");
        Sleep(1500);
        v.disponibilidad = 1;
        if(archivo!=NULL)
        {
            fwrite(&v,sizeof(Vehiculo),1,archivo);
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorExito();
            gotoxy(30,5);
            printf("Vehiculo cargado con exito!");
            Sleep(1500);
            system("cls");
        }
        else
        {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(30,5);
            printf("\nError al abrir el archivo");
            system("cls");
        }
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
                printf(">");
            } else {
                printf(" ");
            }

            if(arregloVehiculos[j].disponibilidad==1){
                printf(" Marca: %s, Modelo: %s, precio %.2f\n", arregloVehiculos[j].marca, arregloVehiculos[j].modelo, arregloVehiculos[j].precioDeAlquilerDiario);

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

        if(tecla!=27){
            system("cls");
            muestraVehiculo(arregloVehiculos[opcion]);
            Sleep(1500);
            gotoxy(30, 15);
            printf("Presione ESC para volver al menu");
            tecla = getch();
        }

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
    printf("Patente: %s-%s",vehiculo.patente.letras, vehiculo.patente.numeros);
    gotoxy(30, 13);
    printf("========================================");

}

void modificarVehiculo(Persona* persona)
{
    system("cls");
    int opcion = 0;
    char tecla;
    int num_opciones = 6;
    Vehiculo vehiculo;
    Patente patente;
    dibujarCuadro(25, 3, 100, 30);

    gotoxy(30, 5);
    printf("Ingrese las letras de la patente por la que desea buscar: ");
    fflush(stdin);
    gets(patente.letras);
    validarLetrasPatente(patente);
    gotoxy(30, 6);
    printf("Ingrese los numeros de la patente por la que desea buscar: ");
    fflush(stdin);
    gets(patente.numeros);
    validarNumerosPatente(patente);


    vehiculo= buscarPatente(patente);

    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    if(strlen(vehiculo.marca)!=0){
        do
        {

            gotoxy(30, 5);
            printf("Que atributo desea modificar? \n");
            for (int i = 0; i < num_opciones; i++)
            {

                gotoxy(30, 8 + i * 2);
                if (i == opcion)
                {
                    printf(">");
                }
                else
                {
                    printf(" ");
                }
            switch (i){

                case 0:printf(" Marca \n");break;
                case 1:printf(" Modelo \n");break;
                case 2:printf(" Tipo Vehiculo \n");break;
                case 3:printf(" Anio \n");break;
                case 4:printf(" Kms \n");break;
                case 5:printf(" Patente");break;
                case 6:printf(" Volver atras");break;
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
                printf("Ingrese la nueva marca: \n");
                gotoxy(60, 5);
                fflush (stdin);
                gets(vehiculo.marca);
                break;
            case 1:
                system("cls");
                gotoxy(30, 6);
                printf("Ingrese el nuevo modelo\n");
                gotoxy(60, 6);
                fflush(stdin);
                gets(vehiculo.modelo);
                break;
            case 2:
                system("cls");
                gotoxy(30, 7);
                ingresarTipoVehiculo(vehiculo.tipoVehiculo);
                Sleep(1500);
                break;
            case 3:
                system("cls");
                gotoxy(30, 8);
                printf("Ingrese los anios\n");
                gotoxy(60, 8);
                fflush(stdin);
                scanf("%d",&vehiculo.anio);
                break;
            case 4:
                system("cls");
                gotoxy(30, 9);
                printf("Ingrese los kms\n");
                gotoxy(60, 9);
                fflush(stdin);
                scanf("%d",&vehiculo.kms);
                break;
            case 5:
                system("cls");
                gotoxy(30, 10);
                printf("Ingrese las letras de la nueva patente\n");
                gotoxy(60, 10);
                fflush(stdin);
                gets(vehiculo.patente.letras);
                validarLetrasPatente(patente);
                gotoxy(30, 11);
                printf("Ingrese los numeros de la nueva patente\n");
                gotoxy(60, 11);
                fflush(stdin);
                gets(vehiculo.patente.numeros);
                validarNumerosPatente(patente);
                break;
            case 6:
                return;
            default:
                gotoxy(30, 6);
                printf("Esta opcion no es válida");
                break;
        }
        confirmarCambiosVehiculo(vehiculo);
    }else{
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50, 5);
        printf("El vehículo que desea modificar no fue encontrado\n");
        Sleep(1500);
        system("cls");
        setColorGral();

    }

}


void busquedaPorPatente()
{

     system("cls");
    Patente patente;
    dibujarCuadro(25, 3, 100, 30);

    gotoxy(30, 5);
    printf("Ingrese los numeros de la patente por la que desea buscar: ");
    fflush(stdin);
    gotoxy(60,5);
    gets(patente.numeros);
    validarNumerosPatente(patente);
    gotoxy(30, 6);
    printf("Ingrese las letras de la patente por la que desea buscar: ");
    fflush(stdin);
    gotoxy(60,6);
    gets(patente.letras);
    validarLetrasPatente(patente);

    Vehiculo vehiculo= buscarPatente(patente);

       if(vehiculo.patente.numeros != 0)
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

Vehiculo buscarPatente(Patente patente){
    Vehiculo v ;
    Vehiculo* arregloVehiculos;
    int cantidad;
    arregloVehiculos = leerArchVehiculos(&cantidad);

    for(int i = 0; i<cantidad; i++)
    {
        if(compararPatentes(patente, arregloVehiculos[i].patente)==1)
        {

            v= arregloVehiculos[i];
        }
    }
    return v;
}

Vehiculo* leerArchVehiculos(int* cantidad){

    FILE* archivoVehiculos= fopen(RUTAVEHICULOS, "rb");

    Vehiculo *arregloVehiculos;
    if(!archivoVehiculos)
    {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(39,5);
        printf("Hubo un error al abrir el archivo");
        system("cls");
        setColorGral();
    }
    else
    {
        fseek(archivoVehiculos, 0L, SEEK_END);
        long cantidadBytes = ftell(archivoVehiculos);
        int cantidadEnArchivo = cantidadBytes / sizeof(Vehiculo);

        rewind(archivoVehiculos);

        arregloVehiculos = (Vehiculo*) malloc(cantidadEnArchivo * sizeof(Vehiculo));

        if (arregloVehiculos == NULL) {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(30,5);
            printf("No se pudo asignar memoria.\n");
            fclose(archivoVehiculos);
            system("cls");
            return arregloVehiculos;
        }

        for (int i = 0; i < cantidadEnArchivo; i++) {
            fread(&arregloVehiculos[i], sizeof(Vehiculo), 1, archivoVehiculos);
        }

        *cantidad = cantidadEnArchivo;

        }
        fclose(archivoVehiculos);
        return arregloVehiculos;

}


int validarLetrasPatente(Patente patente) {
    int len = strlen(patente.letras);

    if (len != 3) {
        gotoxy(30,22);
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("Deben ser 3 letras");
        Sleep(1500);
        system("cls");
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isalpha(patente.letras[i])) {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(50,5);
            printf("Deben ser solo letras\n");
            Sleep(1500);
            system("cls");
            return 0;
        }
    }

    return 1;
}

int validarNumerosPatente(Patente patente) {

    system("cls");
    int len = strlen(patente.numeros);

    if (len != 3) {
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(50,5);
        printf("Debe ingresar solo 3 numeros\n");
        Sleep(1500);
        system("cls");
        return 0;
    }else{

        for (int i = 0; i < len; i++) {
        if (!isdigit(patente.numeros[i])) {
            system("cls");
            dibujarCuadro(25, 3, 100, 30);
            setColorError();
            gotoxy(50,5);
            printf("Solo debe ingresar numeros\n");
            Sleep(1500);
            system("cls");
            return 0;
        }
    }
    }



    return 1;
}

void ingresarTipoVehiculo(char* tipo){

    int num_opciones = 3;
    int tecla;
    int opcion;
    do{
        gotoxy(30,11);
        printf("Ingrese el tipo del auto: ");
        for (int i = 0; i < num_opciones; i++) {
            gotoxy(31, 12 + i);

            switch (opcion) {
                case 0:
                    printf(">");
                    break;
                case 1:
                    printf(" ");
                    break;
            }
            switch(i){
                case 0:printf(" Auto");break;
                case 1:printf(" Camioneta");break;
                case 2:printf(" Utilitario");break;
            }
        }
        tecla = getch();

        switch (tecla) {
            case 72:
                opcion = (opcion - 1 + num_opciones) % num_opciones;
                break;
            case 80:
                opcion = (opcion + 1) % num_opciones;
                break;
        }
    } while (tecla != 13);

     switch (opcion) {
        case 0:
             strcpy(tipo, "Auto");
            break;
        case 1:
            strcpy(tipo, "Camioneta");
            break;
        case 2:
            strcpy(tipo, "Utilitario");
            break;
    }


}


void confirmarCambiosVehiculo(Vehiculo vehiculo){
    system("cls");
    int opcGuarda = 2;
    int opcion = 0;
    char tecla;
    int num_opciones = 2;
    dibujarCuadro(25, 3, 100, 30);


    do{
        for (int i = 0; i < opcGuarda; i++)
        {
            gotoxy(30, 6);
            printf("Desea guardar los cambios? \n");
            gotoxy(30, 9 + i * 2);

           switch (tecla) {
            case 72:
                opcion = (opcion - 1 + num_opciones) % num_opciones;
                break;
            case 80:
                opcion = (opcion + 1) % num_opciones;
                break;
        }
            switch (i){
            case 0:
                printf(" Si \n");
                break;
            case 1:
                printf(" No \n");
                break;
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
            if(modificar_registro_vehiculo(vehiculo) == 1){
                system("cls");
                dibujarCuadro(25, 3, 100, 30);
                gotoxy(50,5);
                setColorExito();
                printf(" Vehiculo modificado con exito!");
                Sleep(1500);
                system("cls");
            }

        case 1:
           return;
    }
}

int borrarPorPatente(Patente patente){

    FILE  *archivoTemporalVehiculos, *archivoVehiculos;
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
        gotoxy(30,5);
        printf("Error al abrir el archivo temporal");
        fclose(archivoTemporalVehiculos);
        fclose(archivoVehiculos);
        system("cls");
        return 0;
    }

    // Lee los registros del archivo original y escribe en el archivo temporal
    while (i<cantidad)
    {
        if(compararPatentes(arregloVehiculos[i].patente, patente)!=1)
        {
            fwrite(&arregloVehiculos[i], sizeof(Vehiculo), 1, archivoTemporalVehiculos);
        }
        else
        {
            encontrado = 1;
        }
        i++;
    }

    fclose(archivoTemporalVehiculos);
    fclose(archivoVehiculos);

    if (encontrado==1)
    {
        dibujarCuadro(25, 3, 100, 30);
        remove(RUTAVEHICULOS);
        if (rename(RUTAVEHICULOSTEMPORAL, RUTAVEHICULOS) == 0) {
            gotoxy(30, 5);
            setColorExito();
            printf("Registro con patente %s-%s fue borrado.\n", patente.letras,patente.numeros);
            Sleep(1500);
            system("cls");
        }
    }
    else
    {
        // Si no se encontró el registro, elimina el archivo temporal
        unlink(RUTAVEHICULOSTEMPORAL);
        system("cls");
        dibujarCuadro(25, 3, 100, 30);
        setColorError();
        gotoxy(30,5);
        printf("Registro con patente %s-%s no encontrado.\n", patente.letras,patente.numeros);
        Sleep(1500);
        system("cls");
    }

    return encontrado;
}


int modificar_registro_vehiculo ( Vehiculo vehiculo)
{
    int modificado = 0;
    FILE* fileVehi = fopen(RUTAVEHICULOS, "r+b");

    if (fileVehi)
        {
        rewind (fileVehi);

        Vehiculo leido;

        while (!modificado && fread (&leido, sizeof (Vehiculo), 1, fileVehi) > 0)
            {
            if (compararPatentes(leido.patente, vehiculo.patente)==1)
                {
                modificado = 1;

                fseek (fileVehi, (-1) * sizeof (Vehiculo), SEEK_CUR);
                fwrite (&vehiculo, sizeof (Vehiculo), 1, fileVehi);
                }
            }
            fclose(fileVehi);
        }

    return modificado;
}

int compararPatentes(Patente p1, Patente p2){

    if(strcmp(p1.letras, p2.letras)==0 && strcmp(p1.numeros, p2.numeros)==0){
        return 1;

    }
    return 0;

}


void borrarVehiculo(){
        Patente patente;
        Sleep(1500);
        gotoxy(30, 18);
        printf("Ingrese las letras de la patente:");
        gotoxy(70, 18);
        fflush(stdin);
        fgets(patente.letras, MAX_LETRAS_PATENTE, stdin);
        patente.letras[strcspn(patente.letras, "\n")] = '\0';

        gotoxy(30, 19);
        printf("Ingrese los numeros de la patente:");
        gotoxy(70, 19);
        fflush(stdin);
        fgets(patente.numeros,MAX_NUMEROS_PATENTE, stdin);
        patente.numeros[strcspn(patente.numeros, "\n")] = '\0';

    if((validarLetrasPatente(patente)==1)&& (validarNumerosPatente(patente) ==1)){
            borrarPorPatente(patente);
    }

}
