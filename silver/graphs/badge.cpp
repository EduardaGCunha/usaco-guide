#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int graph[MAXN];
int visited[MAXN];

void dfs(int v){
    if(visited[v]){
        cout << v+1 << " ";
        return;
    }
    visited[v] = 1;
    dfs(graph[v]);

}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        graph[i] = a;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) visited[j] = 0;
        dfs(i);
    }
    cout << endl;
}