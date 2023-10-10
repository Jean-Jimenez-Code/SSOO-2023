#include <stdio.h>
#include <string.h>

int main(void){
    char string[100],a=0,b;
    printf("Ingresa tu palidromo\n");
    scanf("%s", &string);
    for(int i=0;i<100;i++){  
        //printf("anda\n %c y %c",string[i],string[-i]);      
        
        if(string[i]==string[-i]){
            //printf("bien %d",i);
        }else if(strlen(string)/2==string[i]){
            break;
        }else{
            a++;
        }
    }
    if(a=0){
        printf("Es palidromo");
    }else if(a>0) {
        printf("No es palidromo");
    }
}