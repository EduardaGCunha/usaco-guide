#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c, R1, R2, R;
    scanf("%lf %lf %lf", &a, &b, &c);

    R = pow(b, 2) - (4*a*c);
    if(R < 0 || R == 0){
        printf("Impossível calcular");
    }
    else{
        R1 = (-b + sqrt(R))/(2*a);
        R1 = (-b - sqrt(R))/(2*a);
        printf("R1- %.5lf\n", R1);
        printf("R1- %.5lf\n", R2);
    }
    return 0;
}