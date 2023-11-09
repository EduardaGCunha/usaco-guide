#include <stdio.h>
#include <stdlib.h>

int main(){
    double a, b, c, e, d, f; scanf("%lf %lf %lf", &e, &d, &f);

    if(a*a == b*b + c*c) printf("TRIANGULO RETANGULO\n");
    if(a*a < b*b + c*c) printf("TRIANGULO ACUTANGULO\n");
    if(a*a > b*b + c*c) printf("TRIANGULO OBTUSANGULO\n");
    if(a == b || b == c || a == c){
        if(b==c && a == c)  printf("TRIANGULO EQUILATERO\n");
        else printf("TRIANGULO ISOSCELES\n");
    }
}