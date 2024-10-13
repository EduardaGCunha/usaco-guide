#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
vector<int> visited;
vector<int> c;

/*
cases:
not visited
visiting
visited
whenever we find someone who we are visiting, then
there is a way
*/

bool dfs(int v){
    visited[v] = 1;
    //cout << v << endl;
    for(auto u : graph[v]){
        if(!visited[u]){
            if(dfs(u)){
                c.push_back(u);
                return true;
            }
        }else if(visited[u] == 1){
            c.push_back(u);
            visited[u] = 2;
            return true;
        }
    }
    
    visited[v] = 2;
    return false; 
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    visited.resize(n);
    for(int i = 0; i < n; i++){
        fill(visited.begin(), visited.end(), 0);
        if(dfs(i)){
            break;
        }
    }

    if(c.empty()){
        cout << "IMPOSSIBLE" << endl;
    }else{
        reverse(c.begin(), c.end());
        cout << c.size() << endl << c.back()+1 << " ";
        for(auto a : c){
            cout << a+1 << " ";
        }
        cout << endl;
    }
}