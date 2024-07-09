#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;

vector<int> graph[MAXN];
int visited[MAXN];
double ans = 0;

void dfs(int v, int d, double prob){
    visited[v] = 1;
    int p = 0;
    for(auto u : graph[v]) if(!visited[u]) p++;
    if(!p) ans += prob*d;
    else{
        prob /= p;
        for(auto u : graph[v]){
            if(!visited[u]){
                dfs(u, d+1, prob);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, 0, 1);
    cout << setprecision(10) << ans << endl;
}