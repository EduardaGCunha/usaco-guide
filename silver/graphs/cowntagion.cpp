#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
int d;

void dfs(int v){
    visited[v] = 1;
    int sick = 1, total = graph[v].size();
    if(v == 0) total++;
    while(total > sick){
        d++;
        sick *= 2; 
    }
    for(auto u : graph[v]){
        if(!visited[u]){
            d++;
            dfs(u);
        }
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n -1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    d = 0;
    dfs(0);
    cout << d << endl;
}