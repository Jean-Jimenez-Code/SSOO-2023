#include <stdio.h>
#include <math.h>

int main(void){
    int n=0, contadorP=0, contadorI=0;
    while(n>=0){
        printf("inserte su numero \n");
        scanf("%d", &n);
        if(n%2==0){
            contadorP++;
            printf("numeros pares: %d\n", contadorP);
        }else if(n>=0){
            contadorI++;
            printf("numeros impares: %d\n", contadorI);
        }
    }
}