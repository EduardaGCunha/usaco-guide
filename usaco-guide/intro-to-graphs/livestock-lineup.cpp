#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(8, false);
vector<set<int>> pairs(8);
vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

void dfs(int i){
    if(visited[i]) return;
    visited[i] = true;
    cout << cows[i] << endl;
    for(auto p : pairs[i]){
        if(!visited[p]) dfs(p);
    }
}

int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int n; cin >> n;
    map<string, int> cows_ind;
    for(int i = 0; i < 8; i++){
        cows_ind[cows[i]] = i;
    }

    for(int i = 0; i < n; i++){
        string a, b, t; 
        cin >> a >> t >> t >> t >> t >> b;
        int x = cows_ind[a];
        int y = cows_ind[b];
        pairs[x].insert(y);
        pairs[y].insert(x);
    }
    
    vector<bool> visited(8, false);
    for(int i = 0; i < 8; i++){
        if(!visited[i] && pairs[i].size() < 2) dfs(i);
    }
}