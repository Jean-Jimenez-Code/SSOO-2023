#include <stdio.h>
int main(void){
    //char* a[100];
    char a[5][50];
    
    for (int i = 0; i < 5; i++)
    {   
        printf("Nombre %d:",i+1);
        scanf("%s",&a[i]);
    }
    printf("Imprimiendo nombres: \n");
    for (int j = 0; j < 5; j++)
    {   
        printf("Nombre %d: %s \n", j+1,a[j]);
    }
}