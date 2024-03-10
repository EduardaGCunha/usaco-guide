#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<set<int>> graph(n);
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            a--;
            graph[i].insert(a);
            graph[a].insert(i);
        }
        vector<int> neighbor_cnt(n, 0);
        vector<bool> visited(n, false);
        stack<int> s;
        int c = 0, t = 0;
        for(int i = 0; i < n; i++){
            neighbor_cnt[i] = graph[i].size();
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                s.push(i);
                vector<int> comp;
                while(!s.empty()){
                    int v = s.top(); s.pop();
                    visited[v] = true;
                    comp.push_back(v);
                    for(auto a : graph[v]){
                        if(!visited[a]){
                            s.push(a);
                        }
                    }
                }
                
                bool tree = false;
                for(auto a : comp){
                    if(neighbor_cnt[a] == 1){
                        tree = true;
                        break;
                    }
                }
                if(tree) t++;
                else c++;
            }
        }
        cout << c + min(t, 1) <<  " " << c + t << endl;
    }
} 