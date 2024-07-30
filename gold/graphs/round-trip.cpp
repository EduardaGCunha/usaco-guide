#include <bits/stdc++.h>
using namespace std;

int n, m, head = -2; 
const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN], parent[MAXN];

void dfs(int v){
    if(visited[v]){
        head = v;
        return;
    }

    for(auto a : graph[v]){
        if(!visited[v]){
            parent[a] = v;
            
        }
    }

}

int main(){
    cin >> n >> m;
}