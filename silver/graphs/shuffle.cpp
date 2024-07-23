#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int graph[MAXN];
int visited[MAXN];
int n;
queue<int> q;
int steps;

void dfs(int v){
    q.push(v);
    if(visited[v]){
        return;
    }
    visited[v] = 1;
    steps++;
    dfs(graph[v]);
}

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        graph[i] = a;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            int c = 1;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                if(cur == q.back()) c = 0;
                steps -= c;
            }
        }
    }

    cout << steps << endl;
}