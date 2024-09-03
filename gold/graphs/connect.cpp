#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];
int visited[MAXN], prof[MAXN];

void dfs(int v, int p){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            prof[u] = prof[v]+1;
            dfs(u, v);
        }else{

            if(u == p) continue;

            /*caso a prof do u seja maior que a do v,
            significa que u é descendente de v, porem,
            se a prof[u] < prof[v], entao u é acesdentente
            de v, então é uma backedge;
            */
            if(prof[u] > prof[v]) continue;
            
        }
    }
}

int main(){

}