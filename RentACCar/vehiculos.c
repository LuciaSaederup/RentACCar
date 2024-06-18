#include "vehiculos.h"
#include <conio.h>
#include <windows.h>
void menuVehiculos()
{
    int opcion;
    system("cls");
    int num_opciones = 3;
    int tecla;

    do
    {
        system("cls");
        dibujarCuadro(25, 4, 85, 15);


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
                cargaEstructuraAtuos();
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


Vehiculo cargaUnVehiculo()
{
    system("cls");
    char opcion=0;
    int flagTipo=0;
    int num_opciones = 3;
    int tecla;
    Vehiculo v;


    dibujarCuadro(23, 3, 75, 17);
    gotoxy(30, 5);
    printf("\nIngrese la marca del vehiculo:\n");
    fflush(stdin); //LIMPIAMOS EL BUFFER.
    gotoxy(70, 5);
    gets(v.marca);

    gotoxy(30, 7);
    printf("\nIngrese el modelo:");
    gotoxy(57, 7);
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    gets(v.modelo);

    gotoxy(30, 8);
    printf("\nIngrese el anio: ");
    fflush(stdin);
    gotoxy(40, 8);//LIMPIAMOS EL BUFFER.
    scanf("%i",&v.anio);

    gotoxy(30,9);
    printf("\nIngrese los Kms que tiene el vehiculo: ");
    gotoxy(90,9);
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    scanf("%i",&v.kms);

    gotoxy(30,10);
    printf("\nIngrese el precio del alquiler diario: ");
    gotoxy(90, 10);
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    scanf("%f",&v.precioDeAlquilerDiario);


 do{
        system("cls");
        // Mostrar opciones

        for (int i = 0; i < num_opciones; i++) {
            gotoxy(30, i + i*2);
            printf("Ingrese el tipo del auto: ");
            if (i == opcion) {
                printf("> "); // Resalta la opción actual
            } else {
                printf("  ");
            }
           if(i==0){
                printf("Auto");
           }else if(i==1){
                printf("Camioneta");
           }else if(i==2){
                printf("Utilitario");
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

        switch(opcion)
        {
            case '1':
                strcpy(v.tipoVehiculo,"Auto");
                flagTipo=1;
                break ;
            case '2':
                strcpy(v.tipoVehiculo,"Camioneta");
                flagTipo=1;
                break ;
            case '3':
                strcpy(v.tipoVehiculo,"Utilitario");
                flagTipo=1;
                break ;
        }

        gotoxy(30,11);
        printf("\nIngrese las letras de la patente:\n");
        gotoxy(90,11);
        fflush(stdin);
        fgets(v.patente.letras, 3, stdin);
        validarLetrasPatente(v);

         gotoxy(30,12);
         printf("\nIngrese los numeros de la patente:\n");
        fflush(stdin);
        gotoxy(90,12);
        gets(v.patente.numeros);

        gotoxy(30,13);
        printf("\nEl vehiculo se cargara como DISPONIBLE (1).\nEn caso de querer cambiarlo, se caga");
        v.disponibilidad=1;


    return v;
}

void cargaEstructuraAtuos()
{
    FILE *archivo;
    archivo=fopen(RUTAVEHICULOS,"ab");
    int opc=0;
    int opcion;
    int tecla;
    int opcionesSeguir = 2;
    Vehiculo v;

    if(archivo!=NULL)
    {
            v=cargaUnVehiculo();
            fwrite(&v,sizeof(Vehiculo),1,archivo);

        do{
            for (int i = 0; i < opcionesSeguir; i++)
            {
                gotoxy(30, 6);
                printf("Desea cargar otro vehículo? ");
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
                opcion = (opcion - 1 + opcionesSeguir) % opcionesSeguir;
                break;
            case 80: // Flecha abajo
                opcion = (opcion + 1) % opcionesSeguir;
                break;
            }
        }while (tecla != 13);  // Salir con Enter

        switch (opcion)
        {
            case 0:
                v=cargaUnVehiculo();

            case 1:
                menuVehiculos();
        }

    }
    else
    {
        gotoxy(30,5);
        printf("\nError al abrir el archivo");
    }
    fclose(archivo);
}


void muestraVehiculosDisponibles()
{
    FILE *archivo=fopen(RUTAVEHICULOS,"r+b");

    Vehiculo v;
    printf("\nLISTADO DE VEHICULOS DISPONIBLES\n");
    int flag=1;
    char opc=0;

    do
    {
        printf("\nQUIERE VER AUTOS DISPONIBLES? PRESIONE CUALQUIER TECLA PARA VER O [ESC] para salir\n");
        fflush(stdin);
        opc=getch();
        if(opc!=27)
        {
            if(archivo!=NULL)
            {
                rewind(archivo);
                while(fread(&v,sizeof(Vehiculo),1,archivo)>0)
                {
                    if(v.disponibilidad==flag)
                    {
                        printf("\nMARCA:%s\n",v.marca);
                        printf("\nMODELO:%s\n",v.modelo);
                        printf("\nTIPO DE VEHICULO:%s\n",v.tipoVehiculo);
                        printf("\nANIO:%i\n",v.anio);
                        printf("\nPATENTE:%s\n",v.patente.letras);
                        printf("\nKILOMETROS:%i\n",v.kms);
                    }
                }
            }
            else
            {
                printf("\nERROR EN APERTURA DE EL ARCHIVO\n");
            }
        }
    }
    while(opc!=27);
    fclose(archivo);
}

void muestraVehiculos()
{
    FILE *archivo=fopen(RUTAVEHICULOS,"r+b");

    Vehiculo v;

    printf("\nLISTADO DE VEHICULOS\n");

    if(archivo!=NULL)
    {
        rewind(archivo);
        while(fread(&v,sizeof(Vehiculo),1,archivo)>0)
        {

            printf("\nMARCA:%s\n",v.marca);
            printf("\nMODELO:%s\n",v.modelo);
            printf("\nTIPO DE VEHICULO:%s\n",v.tipoVehiculo);
            printf("\nANIO:%i\n",v.anio);
            printf("\nLETRAS PATENTE:%s\n",v.patente.letras);
            printf("\nKILOMETROS:%i\n",v.kms);
        }
    }
    else
    {
        printf("\nERROR EN APERTURA DEL ARCHIVO\n");
    }
    fclose(archivo);
}

void modificarVehiculo()
{
    FILE *archivo;
    archivo =fopen(RUTAVEHICULOS,"a+b");
    Vehiculo v;
    char modifa[20];
    char numModifica[20];
    int flag=1;
    char modelo=0;
    char anio=0;
    char kms=0;
    char tipo=0;
    printf("\nIngrese la patente del vehiculo a modicar\n");
    fflush(stdin);
    gets(modifa);

    printf("\nIngrese los numeros de la patente\n");
    fflush(stdin);
    gets(numModifica);

    strcat(modifa,numModifica);


    if(archivo!=NULL)
    {
        while(flag==1&&fread(&v,sizeof(Vehiculo),1,archivo)>0)
        {
            char auxPatente[20];
            strcpy(auxPatente,v.patente.letras);

            if(strcmpi(modifa,auxPatente)==0)
            {
                flag=0;
                printf("\nINGRESA MARCA:?\n");
                fflush(stdin);//LIMPIAMOS EL BUFFER.
                gets(v.marca);


                printf("\nQUIERE CAMBIAR EL TIPO DE VEHICULO?");
                scanf("%c",&tipo);
                if(tipo=='s')
                {
                    char option=0;
                    int flagTipo=0;
                    do
                    {
                        printf("\nSELECCIONA EL VEHICULO\n");
                        printf("\nOPCION 1: AUTO\n");
                        printf("\nOPCION 2: CAMIONETA\n");
                        printf("\nOPCION 3: UTILITARIO\n");
                        fflush(stdin);
                        option=getch();
                        switch(option)
                        {
                        case '1':
                            strcpy(v.tipoVehiculo,"AUTO");
                            flagTipo=1;
                            break ;
                        case '2':
                            strcpy(v.tipoVehiculo,"CAMIONETA");
                            flagTipo=1;
                            break ;
                        case '3':
                            strcpy(v.tipoVehiculo,"UTILITARIO");
                            flagTipo=1;
                            break ;
                        }
                    }
                    while(flagTipo==0);
                }

                printf("\nQUIERE CAMBIAR EL MODELO? (S)");
                fflush(stdin);//LIMPIAMOS EL BUFFER.
                scanf("%c",&modelo);
                if(modelo=='s')
                {
                    printf("\nINGRESA NUEVO MODELO\n");
                    fflush(stdin);//LIMPIAMOS EL BUFFER.
                    gets(v.modelo);
                }

                printf("\nQUIERE CAMBIAR EL ANIO (S)\n");
                fflush(stdin);//LIMPIAMOS EL BUFFER.
                scanf("%c",&anio);
                if(anio=='s')
                {
                    printf("\nINGRESA NUEVO ANIO: (S)\n");
                    fflush(stdin);//LIMPIAMOS EL BUFFER.
                    scanf("%i",&v.anio);
                }

                printf("\nQUIERE CAMBIAR LOS KMS:(S)\n");
                fflush(stdin);//LIMPIAMOS EL BUFFER.
                scanf("%c",&kms);

                if(kms=='s')
                {
                    printf("\nINGRESE NUEVO KMS:(S)\n");
                    fflush(stdin);//LIMPIAMOS EL BUFFER.
                    scanf("%i",&v.kms);
                }

                fseek(archivo,-1*sizeof(Vehiculo),SEEK_CUR);
                fwrite(&v,sizeof(Vehiculo),1,archivo);
                mostrarAuto(v);
            }
        }
    }
    else
    {
        printf("\nERROR DE APERTURA DEL ARCHIVO\n");
    }
    fclose(archivo);
}

void mostrarAuto(Vehiculo v)
{
    printf("\nMARCA:%s\n",v.marca);
    printf("\nMODELO:%s\n",v.modelo);
    printf("\nTIPO DE VEHICULO:%s\n",v.tipoVehiculo);
    printf("\nANIO:%i\n",v.anio);
    printf("\nPATENTE:%s\n",v.patente.letras);
    printf("\nKILOMETROS:%i\n",v.kms);
}


void busquedaPorPatente()
{

    FILE *archivo=fopen(RUTAVEHICULOS,"r+b");
    Vehiculo v;
    char letrasPatente[20];
    char numerosPatente[20];

    printf("\nIngresa las letras de la patente que quiera encontrar:\n");
    fflush(stdin);
    gets(letrasPatente);

    printf("\nIngresa los numeros de la pantente que quiera encontrar:\n");
    fflush(stdin);
    gets(numerosPatente);

    strcat(letrasPatente,numerosPatente);

    int flag=1;

    if(archivo!=NULL)
    {
        rewind(archivo);
        while(flag==1&&fread(&v,sizeof(Vehiculo),1,archivo)>0)
        {
            char auxPantente[20];
            strcpy(auxPantente,v.patente.letras);

            if(strcmpi(letrasPatente,auxPantente)==0)
            {
                flag=0;
                printf("\nMARCA:%s\n",v.marca);
                printf("\nMODELO:%s\n",v.modelo);
                printf("\nTIPO DE VEHICULO:%s\n",v.tipoVehiculo);
                printf("\nANIO:%i\n",v.anio);
                printf("\nPATENTE:%s\n",v.patente.letras);
                printf("\nKILOMETROS:%i\n",v.kms);
            }
        }
    }else
    {
        printf("ERROR DE APERTURA DEL ARCHIVO");
    }
    fclose(archivo);
}




int validarLetrasPatente(Vehiculo v){
    int flag=0;
    int len = strlen(v.patente.letras);
        if (len == 3)// Verificar que la longitud no sea mayor a 3
        {
            for (int i = 0; i < len; i++)
            {
                if (!isalpha(v.patente.letras[i])) // Verificar que cada carácter sea una letra
                {
                    flag=1;
                    printf("\nINGRESE LAS |LETRAS| CORRECTAS DE LA PATENTE..\n");
                }
            }
        }
        else
        {
            printf("\nINGRESE LAS |LETRAS| CORRECTAS DE LA PATENTE..\n");
            flag=1;
        }
    return flag;
}

int validarNumerosPatente(Vehiculo v){

    int flagPantente=1;
    int len = strlen(v.patente.numeros);
    if (len == 3)   // Verificar que la longitud no sea mayor a 3
        {
            for (int i = 0; i < len; i++)
            {
                if (!isdigit(v.patente.numeros[i]))
                {
                    flagPantente=0;
                    printf("\nINGRESE LOS |NUMEROS| CORRECTOS DE LA PATENTE..\n");
                } ; // Verificar que cada carácter sea una letra
            }
        }
        else
        {
            printf("\nINGRESE LOS |NUMEROS| CORRECTOS DE LA PATENTE..\n");
            flagPantente=0;
        }


}
