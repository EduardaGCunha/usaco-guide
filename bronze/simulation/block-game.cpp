#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int n, m, K; cin >> n >> m >> K;
    char grid[11][11];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        string s;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < K; k++){
                s += grid[i][j];
            }
        }
        for(int i = 0; i < K; i++) cout << s << endl;
    }


}