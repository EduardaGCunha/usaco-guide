#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];

pair<int, int> bfs(int v){
    queue<pair<int, int> > q;
    q.push({v, 0});
    vector<bool> visited(200005, false);
    pair<int, int> u;

    while(!q.empty()){
        u = q.front(); q.pop();
        visited[u.first] = true;
        for(auto n : graph[u.first]){
            if(!visited[n]){
                q.push({n, u.second+1});
            }
        }
    }

    return u;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    pair<int, int> i = bfs(0);
    pair<int, int> j = bfs(i.first);
    cout << j.second << endl;
}