
#include "reportes_estadisticas.h"

#include "pantallaIngreso.h"
#include "gotoxy.h"

void calcularIngresosEnMes(Persona* persona) {
    system("cls");
    dibujarCuadro(25, 3, 100, 30);

    int mes, anio;

    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchivoAlquileres(&cantidadAlquileres);
    float ingresosTotales = 0;
    imprimirTitulo("Ingresos en mes");
    gotoxy(30, 8);
    printf("Ingrese mes y anio (MM AAAA): ");
    gotoxy(70, 8);
    scanf("%d %d", &mes, &anio);

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (alquileres[i].fechaInicio.mes == mes && alquileres[i].fechaInicio.anio == anio) {
            ingresosTotales += alquileres[i].precioTotal;
        }
    }

        gotoxy(30, 9);
        printf("Ingresos en %02d/%d: %.2f\n", mes, anio, ingresosTotales);
        Sleep(1500);
        system("cls");

}

void calcularAlquilerMayorIngreso() {
    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchivoAlquileres(&cantidadAlquileres);
    int opcion;

    Alquiler alquilerMayorIngreso = alquileres[0];
    for (int i = 1; i < cantidadAlquileres; i++) {
        if (alquileres[i].precioTotal > alquilerMayorIngreso.precioTotal) {
            alquilerMayorIngreso = alquileres[i];
        }
    }

    while(opcion!=27){
    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30,5);
    printf("Alquiler con mayor ingreso:");
    gotoxy(30,6);
    printf("Fecha Inicio: %d/%d/%d", alquilerMayorIngreso.fechaInicio.dia, alquilerMayorIngreso.fechaInicio.mes, alquilerMayorIngreso.fechaInicio.anio);
    gotoxy(30,7);
    printf("Patente: %s", alquilerMayorIngreso.patente.letras);
    gotoxy(30,8);
    printf("Precio Total: %.2f\n",alquilerMayorIngreso.precioTotal);
    gotoxy(30,10);
    printf("Si desea salir presione ESC");
    gotoxy(30,7);
    opcion = getch();
    }
}

void verVehiculosDisponiblesRecientes() {

    int cantVehiculos;
    Vehiculo* vehiculos;
    vehiculos = leerArchVehiculos(&cantVehiculos);
    Vehiculo* vehiculosRecientes = (Vehiculo*) malloc(cantVehiculos*sizeof(Vehiculo));
    int contador = 0;
    int cantidadRecientes= 0;

    for (int i = 0; i < cantVehiculos; i++) {
        if (vehiculos[i].disponibilidad == 1 && (ANIOACTUAL - vehiculos[i].anio) < 5) {
            vehiculosRecientes[contador++] = vehiculos[i];
            cantidadRecientes++;
        }
    }

    ordenarVehiculosPorAnio(vehiculosRecientes, cantidadRecientes);
    imprimirVehiculosRecientes(vehiculosRecientes, cantidadRecientes);
}

void ordenarVehiculosPorAnio(Vehiculo* vehiculos, int cantidadVehiculos) {
    for (int i = 0; i < cantidadVehiculos - 1; i++) {
        for (int j = i + 1; j < cantidadVehiculos; j++) {
            if (vehiculos[i].anio > vehiculos[j].anio) {
                Vehiculo temp = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = temp;
            }
        }
    }
}

void imprimirVehiculosRecientes(Vehiculo* vehiculos, int cantidadVehiculos) {

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

    muestraVehiculo(arregloVehiculos[opcion]);


}

void verAlquileresPorCliente() {

    int cantidadAlquileres;
    Alquiler* alquileres;
    alquileres = leerArchivoAlquileres(&cantidadAlquileres);
    char dni[8];

    system("cls");
    dibujarCuadro(25, 3, 100, 30);
    gotoxy(30, 5);
    printf("Ingrese DNI del cliente: ");
    gotoxy(40, 5);
    fflush(stdin);
    gets(dni);
    dni[strcspn(dni, "\n")] = 0;
    gotoxy(30, 6);
    printf("Fecha Inicio:  Patente:  Fecha Fin:  Precio Total: \n");

    for (int i = 0; i < cantidadAlquileres; i++) {
        if (strcmp(alquileres[i].persona.dni, dni)) {
            char* patente = strcat(alquileres[i].vehiculo.patente.letras,alquileres[i].vehiculo.patente.numeros);
            gotoxy(30, 7+i);
            printf("  %i/%i/%i. ",alquileres[i].fechaInicio.dia, alquileres[i].fechaInicio.mes, alquileres[i].fechaInicio.anio);
            printf("   %s. ",patente);
            printf("   %i/%i/%i. ",alquileres[i].fechaFin.dia, alquileres[i].fechaFin.mes, alquileres[i].fechaFin.anio);
            printf("   %.2f\n",alquileres[i].precioTotal);
        }
    }
}






