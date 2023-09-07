#include <stdio.h>

int main(void){
    // Escribe un algoritmo en C que genere la suma de los primero 100 números impares
    int contador=0,b;
    while (contador==100)
    {
        if (contador%2==1)
        {
            b+=contador;
        }
        contador++;
        printf("Numero %d", contador);
    }
    printf("Resultado %d", b);
}