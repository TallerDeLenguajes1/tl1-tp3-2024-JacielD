#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct{

int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100

}typedef Producto;

struct{

int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

float calcularPrecio(int cant, float precio);
void mostrarDatos(Cliente *cli,int cant);
int main(){

    Cliente *clientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"},*buff;
    int cant;
    printf("ingrese la cantidad de clientes: ");
    scanf("%d",&cant);

    for (size_t i = 0; i < cant; i++)
    {
        printf("ingrese el ID del cliente %d: ",i +1);
        scanf("%d",&clientes[i].ClienteID);

        buff= (char *) malloc(100*sizeof(char));
        printf("ingrese el nombre del cliente %d: ", i+1);
        gets(buff);
        clientes[i].NombreCliente= (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(clientes[i].NombreCliente,buff);

        clientes[i].CantidadProductosAPedir = (rand() % 5) + 1;

        for (size_t j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("ingrese el id del producto: ");
            scanf("%d",&clientes[i].Productos[j].ProductoID);

            clientes[i].Productos[j].Cantidad = (rand() % 10) + 1;

            int indice = rand() % 5;
            buff = TiposProductos[indice];
            clientes[i].Productos[j].TipoProducto = (char *) malloc((strlen(buff)+1)*sizeof(char));
            strcpy(clientes[i].Productos[j].TipoProducto,buff);

            clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10;

            
        }
    }

    mostrarDatos(&clientes,cant);
    return 0;
}
float calcularPrecio(int cant, float precio){

        return (cant * precio);

}

void mostrarDatos(Cliente *cli,int cant){

    for (size_t i = 0; i < cant; i++)
    {   
        printf(" ****** Datos Del Cliente %d ****** ", i+1);

        printf("ID del cliente: %d\n",cli->ClienteID);
        printf("Nombre Del Cliente: %s",cli->NombreCliente);
        printf("Cantidad De Productos A Pedir: %d",cli->CantidadProductosAPedir);

        for (size_t j = 0; j < cli->CantidadProductosAPedir; j++)
        {
            printf("ID del producto: %d",cli->Productos[j].ProductoID);
            printf("Cantidad Del Producto: %d",cli->Productos[j].Cantidad);
            printf("Tipo De Producto: %s",cli->Productos[j].TipoProducto);
            printf("precio unitario del producto: %.2f",cli->Productos[j].PrecioUnitario);
            float total = calcularPrecio(cli->Productos[j].Cantidad,cli->Productos[j].PrecioUnitario);
            printf("total a pagar: %.2f",total);
        }
        
    }
    
}