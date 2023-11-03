#include <stdio.h>

int main(){
    int a, b; 
    scanf("%d %d", &a, &b);

    a != 0 ? (b == 0? printf("B\n") : printf("A\n")): printf("C\n");
}