#include "alquileres.h"
#include "vehiculos.h"
Alquiler cargaUnAlquiler()
{
    Alquiler a;
    float cantDias=0;
    char letrasPatente[20];
    char numerosPatente[20];
    printf("\nREGISTRARA UN NUEVO ALQUILER DE AUTOS:\n");

    printf("INGRESE DNI DEL CLIENTE QUE VA INGRESAR:");
    fflush(stdin);
    scanf("%i",&a.dniCliente);

    printf("\nIngrese el día de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&a.fechaInicio.dia);

    printf("\nIngrese el mes de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&a.fechaInicio.mes);

    printf("\nIngrese el mes de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&a.fechaInicio.anio);

    //=============================================================
    printf("\nIngrese el día de fin del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&a.fechaFin.dia);

    printf("\nIngrese el mes de fin del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&a.fechaFin.mes);

    printf("\nIngrese el mes de fin del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&a.fechaFin.anio);

    printf("INGRESE LAS LETRAS DE LA PATENTE DEL AUTO A ALQUILAR:");
    fflush(stdin);
    gets(letrasPatente);

    printf("INGRESE LOS NUMEROS DE LA PATENTE DEL AUTO A ALQUILAR:");
    fflush(stdin);
    gets(numerosPatente);

    strcat(letrasPatente,numerosPatente);

    cantDias=(a.fechaFin.anio - a.fechaInicio.anio) * 365 + (a.fechaFin.mes - a.fechaInicio.mes) * 30 + (a.fechaFin.dia - a.fechaInicio.dia);

    FILE *archivo=fopen(RUTASAUTO,"r+b");

    Vehiculo v;

    float precioDiario=0;
    int flag=1;

    if(archivo!=NULL)
    {
        while(flag==1&&fread(&v,sizeof(Vehiculo),1,archivo)>0)
        {
            char patenteAux[20];
            strcpy(patenteAux,v.patente.letras);
            if(strcmpi(patenteAux,letrasPatente)==0)
            {
                flag=0;
                precioDiario=v.precioDeAlquilerDiario;
                fseek(archivo,-1*sizeof(Vehiculo),SEEK_CUR);
                v.disponibilidad=0;
                fwrite(&v,sizeof(Vehiculo),1,archivo);
            }
        }
    }
    else
    {
        printf("ERROR DE APERTURA");
    }
    fclose(archivo);

    if(flag==0)
    {
        a.precioTotal = cantDias * precioDiario ;
        printf("El precio total del alquiler es: %0.2f", a.precioTotal);
    }
    else
    {
        printf("NO HUBO SUMA");
    }

    return a;
}

void regitrarAlquier()
{
    FILE *archi=fopen(RUTAALQUILERES,"a+b");
    FILE *archivo=fopen(RUTASAUTO,"r+b");

    Alquiler a;
    int opc=0;
    if(archi!=NULL)
    {
        do
        {
            printf("\nINGRESE UN ALQUILER Y PRESIONE ESC PARA TERMINAR..\n");
            a=cargaUnAlquiler(RUTASAUTO);
            opc=getch();
            fwrite(&a,sizeof(Alquiler),1,archi);
        }
        while(opc!=27);
    }
    fclose(archi);
}


void mostrarAlquieres()
{
    FILE *archi=fopen(RUTAALQUILERES,"r+b");

    Alquiler a;

    if(archi!=NULL)
    {
        while(fread(&a,sizeof(Alquiler),1,archi)>0)
        {
            muestraUnAlquiler(a);
        }
    }
    else
    {
        printf("ERROR DE APERTURA");
    }
    fclose(archi);
}

void muestraUnAlquiler(Alquiler a)
{
    if(a.precioTotal>0)
    {
        printf("\n Fecha de inicio: %d / %d / %d \n", a.fechaInicio.dia,a.fechaInicio.mes,a.fechaInicio.anio);
        printf("\n Fecha de devolucion: %d / %d / %d \n", a.fechaFin.dia,a.fechaFin.mes,a.fechaFin.anio);
        printf("\n Precio: %0.2f \n", a.precioTotal);
        printf("\n DNI: %d \n", a.dniCliente);
        printf("\n PATENTE ALQUILADA %s",a.patente.letras);
    }
}

void mostrarAlquilerPorFecha()
{

    FILE *archi=fopen(RUTAALQUILERES,"a+b");

    Alquiler a;

    int dia=0;
    int mes=0;
    int anio=0;

    printf("\nIngrese el día de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&dia);

    printf("\nIngrese el mes de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&mes);

    printf("\nIngrese el mes de inicio del alquiler del auto\n");
    fflush(stdin);
    scanf("%i",&anio);

    char letrasPatente[10];
    char numerosPatente[10];

    printf("INGRESE LAS LETRAS DE LA PATENTE DEL AUTO A ALQUILAR:");
    fflush(stdin);
    gets(letrasPatente);

    printf("INGRESE LOS NUMEROS DE LA PATENTE DEL AUTO A ALQUILAR:");
    fflush(stdin);
    gets(numerosPatente);

    strcat(letrasPatente,numerosPatente);
    int flag=1;
    if(archi!=NULL)
    {
        while(flag==1&&fread(&a,sizeof(Alquiler),1,archi)>0)
        {
            char patenteAux[20];
            strcpy(patenteAux,letrasPatente);
            if(a.fechaInicio.dia==dia&&a.fechaInicio.mes==mes&&a.fechaInicio.anio==anio&&strcmpi(patenteAux,a.patente.letras)==0)
            {
                muestraUnAlquiler(a);
            }
        }

    }else
    {
        printf("\nERROR DE APERTURA\n");
    }
    fclose(archi);
}
