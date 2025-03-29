// Tomás González, Nicolás Acosta
#include <stdio.h>

int main()
{
    char nombre[30];
    int stock, cantidad, opcion, val, id, datosIngresados = 0;
    float precio, totalGanancias = 0, descuento, precioFinal, precioDescontado;

    do
    {
        printf("\nMenú de Opciones:\n");
        printf("\t1. Ingreso ID del producto,nombre y cantidad en stock\n");
        printf("\t2. Vender producto\n");
        printf("\t3. Reabastecer producto\n");
        printf("\t4. Mostrar información del producto\n");
        printf("\t5. Mostrar total de ganancias\n");
        printf("\t6. Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1)
        {
            while (getchar() != '\n')
                ;
            opcion = 0;
        }

        if (!datosIngresados && opcion != 1 && opcion != 6)
        {
            printf("Primero debe ingresar los datos del producto. Intente nuevamente\n");
            continue;
        }

        switch (opcion)
        {
        case 1:
            printf("Ingrese el ID del producto: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            printf("Ingrese el nombre del producto: ");
            fgets(nombre, 30, stdin);
            fflush(stdin);
            do
            {
                printf("Ingrese la cantidad inicial en stock: ");
                val = scanf("%d", &stock);
                if (val != 1 || stock < 0)
                {
                    printf("Valor inválido. Intente nuevamente\n");
                    while (getchar() != '\n')
                        ;
                }
                fflush(stdin);
            } while (val != 1 || stock < 0);

            do
            {
                printf("Ingrese el precio unitario del producto: ");
                val = scanf("%f", &precio);
                if (val != 1 || precio < 0)
                {
                    printf("Valor inválido. Intente nuevamente\n");
                    while (getchar() != '\n')
                        ;
                }
                fflush(stdin);
            } while (val != 1 || precio < 0);

            datosIngresados = 1;
            break;

        case 2:
            do
            {
                printf("Ingrese la cantidad a vender: ");
                val = scanf("%d", &cantidad);
                if (val != 1 || cantidad < 0)
                {
                    printf("Valor inválido. Intente nuevamente\n");
                    while (getchar() != '\n')
                        ;
                }
                else if (cantidad > stock)
                {
                    printf("El valor ingresado es mayor al stock. Intente nuevamente\n");
                }
                fflush(stdin);
            } while (val != 1 || cantidad < 0 || cantidad > stock);

            if (cantidad >= 20)
            {
                descuento = 10;
                precioFinal = precio - (precio * (descuento / 100));
                precioDescontado = precioFinal;
                printf("\tPrecio descontado: $%.2f\n", precioDescontado);
            }
            else
            {
                precioFinal = precio;
            }

            float totalVenta = cantidad * precioFinal;
            stock -= cantidad;
            totalGanancias += totalVenta;
            printf("\n\tVenta realizada exitosamente.\n");
            printf("\tTotal de la venta: $%.2f\n", totalVenta);
            printf("\tStock restante: %d\n", stock);
            break;

        case 3:
            do
            {
                printf("Ingrese la cantidad a agregar en el stock: ");
                if (scanf("%d", &cantidad) != 1 || cantidad < 1)
                {
                    printf("Valor invalido. Intente nuevamente\n");
                    while (getchar() != '\n')
                        ;
                }
            } while (cantidad < 1);

            stock += cantidad;
            printf("\tNuevo stock: %d\n", stock);
            break;

        case 4:
            printf("\n\tInformación del producto:\n");
            printf("\tID: %d\n", id);
            printf("\tNombre: %s", nombre);
            printf("\tStock disponible: %d\n", stock);
            printf("\tPrecio unitario: $%.2f\n", precio);
            break;

        case 5:
            printf("\tTotal de ganancias: $%.2f\n", totalGanancias);
            break;

        case 6:
            printf("\tSaliendo del programa...\n");
            break;

        default:
            printf("Opción inválida. Intente de nuevo\n");
        }
    } while (opcion != 6);

    return 0;
}

