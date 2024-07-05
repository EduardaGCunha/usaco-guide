#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+7;
vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            c++;
        }
    }

    cout << c << endl;
}