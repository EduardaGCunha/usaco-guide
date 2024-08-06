#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
vector<int> endpoints;
int visited[MAXN];
int n, k;


bool check(int mid){
    //funcao check vai chamar meu bfs 
    // e enviar mid diferentes endpoints pra ver se isso garante
    // that in all cases there will be no way that she can escape

    
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<pair<char, int>> q;
    q.push({'b', 0});
    
    for(int i = 0; i <= n; i++){
        if(i == k) continue;
        if(graph[i].size() == 1){
            endpoints.push_back(i);
        }
    }


    int l = 0, r = endpoints.size();

    while(l < r){
        int mid = (l+r)/2;
        
    }

}