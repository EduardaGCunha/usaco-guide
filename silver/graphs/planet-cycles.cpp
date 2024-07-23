#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
int graph[MAXN];
int visited[MAXN], pathlength[MAXN]; 
int n;
queue<int> q;
int steps;

void dfs(int v){
    q.push(v);
    if(visited[v]){
        steps += pathlength[v];
        return;
    }

    visited[v] = 1;
    steps++;
    dfs(graph[v]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        graph[i] = (a);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            steps = 0;
            dfs(i);

            int c = 1;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                if(cur == q.back()) c = 0;
                pathlength[cur] = steps;
                steps -= c;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << pathlength[i] << " ";
    }
    cout << endl;
}