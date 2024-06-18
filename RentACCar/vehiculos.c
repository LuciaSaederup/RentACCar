#include "vehiculos.h"


Vehiculo cargaUnVehiculo()
{
    Vehiculo v;

    printf("\nINGRESE MARCA:\n");
    fflush(stdin); //LIMPIAMOS EL BUFFER.
    gets(v.marca);

    printf("\nINGRESE MODELO:\n");
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    gets(v.modelo);

    printf("\nINGRESE ANIO:\n");
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    scanf("%i",&v.anio);

    printf("\nINGRESE KMS\n");
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    scanf("%i",&v.kms);

    printf("\nINGRESE PRECIO DE ALQUILER DIARIO\n");
    fflush(stdin);//LIMPIAMOS EL BUFFER.
    scanf("%f",&v.precioDeAlquilerDiario);

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

    int flag=1;
    do
    {
        flag=1;
        printf("\nIngrese las letras de la patente:\n");
        fflush(stdin);
        gets(v.patente.letras);
        int len = strlen(v.patente.letras);
        if (len == 3)// Verificar que la longitud no sea mayor a 3
        {
            for (int i = 0; i < len; i++)
            {
                if (!isalpha(v.patente.letras[i])) // Verificar que cada carácter sea una letra
                {
                    flag=0;
                    printf("\nINGRESE LAS |LETRAS| CORRECTAS DE LA PATENTE..\n");
                }
            }
        }
        else
        {
            printf("\nINGRESE LAS |LETRAS| CORRECTAS DE LA PATENTE..\n");
            flag=0;
        }
    }
    while(flag==0);


    int flagPantente=1;
    do
    {
        flagPantente=1;
        printf("\nIngrese los numeros de la patente:\n");
        fflush(stdin);
        gets(v.patente.numeros);
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
    while(flagPantente==0);

    do
    {
        printf("\nVEHICULO DISPONIBLE (1 DISPONIBLE) (0 NO DISPONIBLE)\n");
        fflush(stdin);
        scanf("%i",&v.disponibilidad);
        if(v.disponibilidad!=0&&v.disponibilidad!=1)
        {
            printf("\nNUMERO DE DISPONIBILIDAD EQUIVOCADO (0 no disponible) (1 disponible)\n");
        }
    }
    while(v.disponibilidad!=0&&v.disponibilidad!=1);

    return v;
}

void cargaEstructuraAtuos()
{
    FILE *archivo=fopen(RUTAVEHICULOS,"a+b");
    int opc=0;
    Vehiculo v;
    if(archivo!=NULL)
    {
        do
        {
            v=cargaUnVehiculo();
            opc=getch();
            fwrite(&v,sizeof(Vehiculo),1,archivo);
        }
        while(opc!=27);
    }
    else
    {
        printf("ERROR EN APERTURA DE ARCHIVO");
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
