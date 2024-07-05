#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int visited[MAXN], sub[MAXN];

void dfs(int v, int p){
    sub[v] = 1;
    for(auto a : graph[v]){
        if(a != p){
            dfs(a, v);
        }
        sub[v] += sub[a];
    }
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n-1; i++){
        int a; cin >> a;
        a--;
        graph[a].push_back(i);
    }

    dfs(0, -1);
    for(int i = 0; i < n; i++){
        cout << sub[i]-1 << " ";
    }
    cout << endl;
}