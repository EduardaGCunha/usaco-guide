#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200007;
vector<int> graph[MAXN]; 
int comp[MAXN], visited[MAXN];
char breed[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    comp[v] = c;
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a, c);
    }
}

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> breed[i];
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(breed[a] != breed[b]) continue;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, c);
            c++;
        }
    }
    
    for(int i = 0; i < m; i++){
        int a, b; char c; cin >> a >> b >> c;
        a--, b--;
        if((comp[a] != comp[b]) || (breed[a] == c)) cout << 1;
        else cout << 0;
    }
    cout << endl;
    
}