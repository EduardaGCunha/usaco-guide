#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int graph[MAXN];
string ans[MAXN], pos[MAXN];

int cur;

void dfs(int v, string s){
    if(cur == 0){
        ans[v] = s;
        return;
    }
    cur--;
    dfs(graph[v], s);
}

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        graph[a] = i;
    }

    for(int i = 0; i < n; i++) cin >> pos[i];

    for(int i = 0; i < n; i++){
        cur = 3;
        dfs(i, pos[i]);
    }   

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

}