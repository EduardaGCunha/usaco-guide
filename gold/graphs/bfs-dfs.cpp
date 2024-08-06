#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];

int main(){
    int n; cin >> n;

    int bfs[n], dfs[n];
    for(int i = 0; i < n; i++){
        cin >> bfs[i];
    }
    for(int i = 0; i < n; i++){
        cin >> dfs[i];
    }

    if(bfs[1] != dfs[1]){
        cout << -1 << endl;
        return 0;
    }
    
    cout << 2*(n-1) - 1 << endl;
    for(int i = 0; i < n; i++){
        cout << 1 << " " << bfs[i] << endl;
    }

    for(int i = 1; i < n; i++){
        cout << dfs[i-1] << " " << dfs[i] << endl;
    }
}