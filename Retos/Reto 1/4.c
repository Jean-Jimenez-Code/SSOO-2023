#include <stdio.h>
int main(void){
    int a[2][2], b[2][2], c[2][2];
    
    printf("Ingrese numeros de la matriz a:");
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {   
            
            printf("Ingrese valor \n");
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nIngrese numeros de la matriz b:");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {   
            int d=0;
            printf("Ingrese valor \n");
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nValores de la matriz c, suma:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("Valor %d ", c[i][j]);
        }
        printf("\n");
    }
}