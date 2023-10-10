#include <stdio.h>
#include <string.h>

int main(void){
    char frase[100];
    
    printf("Escribe una frase de 100\n");
    scanf("%s", &frase);
    printf("frase :%s \n",frase);
    char letra;
    int contador=0;
    printf("Escribe una letra\n");
    scanf(" %c", &letra);
    for(int i=0;i<500;i++){
        if(frase[i]==letra){
            contador++;
        }
    }
    printf("Numero de veces que aprece la letra: %d", contador);
}