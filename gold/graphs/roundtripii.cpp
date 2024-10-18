#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int visited[MAXN];
vector<int> c;

bool dfs(int v){
    if(visited[v] == 1){
        visited[v] = 2;
        c.push_back(v);
        return true;
    }
    visited[v] = 1;

    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
    visited[v] = 2;
}

int main(){

}