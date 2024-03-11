#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 100007;

vector<int> graph[MAXN];
int visited[MAXN];
ll cnt[2];

void dfs(int v, int c){
    visited[v] = 1;
    cnt[c]++;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, !c);
        }
    }
}

int main(){
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    cout << cnt[0]*cnt[1] - n+1 << endl;

}