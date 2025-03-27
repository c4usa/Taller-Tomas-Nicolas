#include <stdio.h>

int main()
{
    int id, stock, cantidad, opcion;
    float precio = 0, totalGanancias = 0, descuento, precioFinal, precioDescontado;
    char nombre[30];
    do
    {
        printf("\nMenú de Opciones:\n");
        printf("\t1.Ingreso ID del producto, el nombre del producto y la cantidad en stock\n");
        printf("\t2.Vender producto\n");
        printf("\t3.Reabastecer producto\n");
        printf("\t4.Mostrar información del producto\n");
        printf("\t5.Mostrar total de ganancias\n");
        printf("\t6.Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese el ID del producto: ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Ingrese el nombre del producto: ");
            fgets(nombre, 30, stdin);
            fflush(stdin);
            int val;

            do
            {
                printf("Ingrese la cantidad inicial en stock: ");
                fflush(stdin);
                val = scanf("%d", &stock);
                if (val != 1)
                {
                    printf("El valor es incorrecto, vuelva a ingresar\n");
                }
            } while (val!=1);

            printf("Ingrese el precio unitario del producto: ");
            while (scanf("%f", &precio) != 1 || precio < 0)
            {
                printf("El precio tiene que ser positivo. Intente nuevamente: ");
                while (fflush(stdin))
                    ;
            }
            break;
        case 2:
        int value;
        do
        {
            printf("Ingrese la cantidad a vender: ");
            fflush(stdin);
            value = scanf("%d", &cantidad);
        } while (val!=1);
        if(cantidad==20)
        {
            descuento = 10;
            precioFinal = precio * (descuento/100);
            precioDescontado=precio-precioFinal;
            printf("\tPrecio descontado: $%.2f\n", precioDescontado);

        }
            float totalVenta = cantidad * precioFinal;
            stock -= cantidad;
            totalGanancias += totalVenta;
            printf("\n\tVenta realizada exitosamente.\n");
            printf("\tTotal de la venta: $%.2f\n", totalVenta);
            printf("\tStock restante: %d\n", stock);
            break;
        case 3:
            printf("Ingrese la cantidad a agregar en el stock: ");
            scanf("%d", &cantidad);
            if (cantidad < 1)
            {
                printf("La cantidad tiene que ser mayor que cero. Intente nuevamente: ");
            }
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
            printf("\tOpción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
