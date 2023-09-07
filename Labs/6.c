#include <stdio.h>

int main(void){
    // Escribe un algoritmo en C que genere la suma de los primero 100 números impares
        printf("Ingresa 3 notas, punto flotante\n");
    float a = 0, b = 0, c=0, d=0, promedio;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    

    promedio=(a*0.4+b*0.3+c*0.3);
    printf("El Promedio ponderado es %f \n", promedio);
    if (promedio<3.95)
    {
        printf("ha reprobado la asignatura\n");
    }else if (promedio>=3.95 && promedio<=4.94)
    {
        printf("el estudiante va a examen\n");
    }else if (promedio>=495)
    {
        printf("el alumno se exime de la asignatura\n");
    }
    
    
    

}