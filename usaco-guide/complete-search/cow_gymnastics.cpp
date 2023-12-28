#include <bits/stdc++.h>
using namespace std;

int rankings[10][20], better[20][20];

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> rankings[i][j];
            rankings[i][j]--;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = j + 1; k < m; k++){
                better[rankings[i][j]][rankings[i][k]]++;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(better[i][j] == n) cnt++;
        }
    }

    cout << cnt << endl;
   

}