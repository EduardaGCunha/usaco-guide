#include <bits/stdc++.h>
using namespace std;

int n, m;

string spotty[100], plain[100];

bool solve(int i){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(spotty[j][i] == plain[k][i]) return false;
        }
    }
    return true;
}

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> spotty[i];
    for(int i = 0; i < n; i++) cin >> plain[i];
    for(int i = 0; i < m; i++){
        if(solve(i))ans++;
    }
    cout << ans << endl;
    
}