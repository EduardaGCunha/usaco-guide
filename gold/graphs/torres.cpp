#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> linhas;
    vector<int> colunas;
    int res = 0;
    for(int i = 0; i < n; i++){
        int l = 0, c = 0;
        for(int j = 0; j < n; j++){
            l += arr[i][j];
            c += arr[j][i];
        }
        
        cout << l << " " << c << endl;
        for(int j = 0; j < n; j++){
            cout << abs(l-arr[j][j]) + abs(c-arr[i][j]) << endl;
            res = max({res, abs(l+c - 2*(arr[i][j]))});
        }
    }

    cout << res << endl;
}