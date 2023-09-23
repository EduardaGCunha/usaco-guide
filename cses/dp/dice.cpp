#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> paths(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a; cin >> a;
            if(a == '*') paths[i][j] = -1;
        }
    }

    paths[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(paths[i][j] != -1){
                if(i-1 >= 0 && paths[i-1][j] != -1){
                    paths[i][j] = (paths[i][j] + paths[i-1][j])%mod;
                }
                if(j-1 >=0 && paths[i][j-1] != -1){
                        paths[i][j] = (paths[i][j] + paths[i][j-1])%mod;
                }
            }
        }
    }

    cout << paths[n-1][n-1];
}