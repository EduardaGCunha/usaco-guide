#include <bits/stdc++.h>
using namespace std;

const int MAXN = 157;
vector<int> graph[MAXN];
int color[MAXN];

int main(){
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 1;
    color[0] = cnt;
    for(int i = 0; i < n; i++){
        for(auto u : graph[i]){
            if(color[u] && color[u] == color[i]){
                color[u] = color[i]+1;
            }else{
                cnt--;
                color[u] = cnt;
            }
        }
    }
}
