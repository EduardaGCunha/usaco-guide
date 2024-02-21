#include <stdio.h>
#include <limits.h>

int main(){
    int n; scanf("%d", &n);
    int arr[n+1], arr1[n];
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        arr[i] = a;
    }

    arr1[0] = arr[n-1]; 
    for(int i = 1; i < n; i++){
        arr1[i] = arr[i-1];
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");


}