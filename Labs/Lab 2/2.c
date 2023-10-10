#include <stdio.h>
#include <math.h>

int main(void){
    float c1, c2, hip,p,area;
    printf("Coloca los 2 catetos del tri. recto")
    scanf("%f", &c1);
    scanf("%f", &c2);
    hip=sqrt(c1*c1+c2*c2);
    area=(c1*c2)/2;
    p=hip+c1+c2;
    printf("hip %f, area %f, p %f",hip,area,p);
}