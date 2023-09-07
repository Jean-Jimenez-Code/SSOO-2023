#include <stdio.h>

int main(void){
    // Escribe un algoritmo en C que genere la suma de los primero 100 números impares
        printf("Ingresa 4 numeros decimales, punto flotante\n");
    float a = 0, b = 0, c=0, d=0, promedio;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);

    promedio=(a+b+c+d)/4;
    printf("El Promedio es %f", promedio);

}