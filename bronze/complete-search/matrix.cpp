#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int arr[n][n];
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                x = i, y = j;
            }
        }
    }

    cout << abs(x - 2) + abs(y-2) << endl;
}