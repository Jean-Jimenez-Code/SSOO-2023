#include <stdio.h>

int main(void){
    // Escribe un algoritmo en C que genere la suma de los primero 100 números impares
        printf("Ingresa 3 lados del triangulo\n");
    int a = 0, b = 0, c=0, perimetro, semiperimetro;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a==b && b==c)
    {
        printf("El triangulo es Equilatero");
    }else if (a==b||c==b||a==c)
    {
        if (b!=c || a!=c)
        {
            printf("El triangulo es Isosceles");
        }
    }else if (a!=b&&b!=c)
    {
        printf("El triangulo es Escaleno");
    }
    
    perimetro=a+b+c;
    semiperimetro=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c))
    printf("El triangulo es ");
}