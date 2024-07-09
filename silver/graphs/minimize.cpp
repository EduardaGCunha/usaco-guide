#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int dis, cur;

void dfs(int v, int p, int d){
    for(auto u : graph[v]){
        if(u != p) dfs(u, v, d+1);
    }
    if(dis < d){
        dis = d;
        cur = v;
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
    //what if 0 has a parent?
    dfs(0, -1, 0);
    dfs(cur, -1, 0);
    int val1 = dis; 
    for(int i = 0; i < n; i++) graph[i].clear();
    int m; cin >> m;
    for(int i = 0; i < m-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1, 0);
    dfs(cur, -1, 0);
    int val2 = dis;
    //cout << val1-1 << " " << val2-1 << endl;
    cout << val1 + val2 - 2 << endl;
    
}