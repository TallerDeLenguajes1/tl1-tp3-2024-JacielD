#include <stdio.h> 
#define MINIMO 10000
#define MAXIMO 50000

int main(){

    int matriz[5][12],total = 0,minimo = 0, maximo = 0,mesMa,mesMi;
    float promedio;

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            matriz[i][j] = (rand() % (MAXIMO - MINIMO + 1)) + MINIMO;

            total = total + matriz[i][j];
            printf(" %d ",matriz[i][j]);

            //calcular mes con mas ganancias

            if (matriz[i][j] > maximo)
            {
                maximo = matriz[i][j];
                mesMa = j;
            }else if (matriz[i][j] < maximo)
            {
                minimo = matriz[i][j];
                mesMi = j;
            }
            
            
            

        }
            printf("\n");
            promedio = total/12;
            printf("\n********** Datos Del Year %d **********\n\n",i+1);
            printf("el maximo numero de ventas fue: %d y el menor fue: %d\n\n",maximo,minimo);
            printf("el mes que mas se tuvo ventas fue: %d y el menor %d \n\n",mesMa,mesMi);
            printf("Promedio Del Year: %.2f\n\n",promedio);   
                 
    }

    // Mostrar Mtriz


    
    return 0;
}