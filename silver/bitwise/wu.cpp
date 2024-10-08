#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q; cin >> n >> m >> q;
    int arr[n];
    string bin[m];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> vals(n, vector<int>(m));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char a; cin >> a;
            vals[i].push_back(a-'0');
        }
    }

    for(int i = 0; i < n; i++){
        sort(vals[i].begin(), vals[i].end());
    }

    while(q--){
        string s; 
        int k; cin >> s >> k;
        
    }
    
}