#include <stdio.h>

int main(void){
    // Escribe un algoritmo en C que genere la suma de los primero 100 números impares
    int contador=0,b=0,a=0;
    while (a!=100)
    {   
        
        if (contador%2==1)
        {
            b+=contador;
            printf("Numero %d", contador);
            a++;
        }
        contador++;

        
    }
    printf("\nResultado de suma %d", b);
}