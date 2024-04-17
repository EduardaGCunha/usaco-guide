#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10006;

vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a);
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
            c++;
            dfs(i);
        }
    }

    cout << c << endl;
}