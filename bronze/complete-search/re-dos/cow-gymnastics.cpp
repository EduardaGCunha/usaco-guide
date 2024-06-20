#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gymnastics.in", "r", stdin);
    int n, m; cin >> n >> m;
    int values[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> values[i][j];
            values[i][j]--;
        }
    }
    int cnt = 0;

    int rankings[20][20];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = j + 1; k < m; k++){
                rankings[values[i][j]][values[i][k]]++;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(rankings[i][j] == n) cnt++;
        }
    }

    cout << cnt << endl;
}