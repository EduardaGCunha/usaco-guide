#include <stdio.h>

double m[12][12];

double sum(int n){
    double s = 0;
    for(int i = 0; i < 12; i++){
        s += m[n][i];
    }
    return s;
}

double media(int n){
    double s = 0;
    for(int i = 0; i < 12; i++){
        s += m[n][i];
    }
    return (s/12);
}

int main(){
    int n; scanf("%d", &n);
    char a; scanf("%c", &a);
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            double x; scanf("%lf", &x);
            m[i][j] = x;
        }
    }

    double res;
    if(a == 'S') res = sum(n);
    else res = media(n);
    printf("%.1lf\n", res);

}