/* #include <stdio.h>
int main(void){
    char* a[]={"Santiago","Sofia","Mateo","Isabella","Sebastian"};
    
    for (int i = 0; i < 5; i++)
    {   
        printf("Nombre %d: %s \n", i+1,a[i]);
    }
    
} */
#include <stdio.h>
int main(void){
    char a[5][50]={"Santiago","Sofia","Mateo","Isabella","Sebastian"};
    
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: %s \n", i+1,a[i]);
    }
}