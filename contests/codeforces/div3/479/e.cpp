//so preciso ver se tem algum elemento q se conecta com algum q ja foi visitado e q nn seja o pai dele
#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 11;
vector<int> graph[N];
int deg[N];
int comp[N];
bool visited[N];



int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        deg[a]++; deg[b]++; //checking if they only have 2 connections
    }

    int answer = 0;
    stack<int> s;
    for(int i = 1; i <= m; i++){
        if(!visited[i]){
            bool val = true;
            s.push(i);
            while(!s.empty()){
                int cur = s.top(); s.pop();
                if(deg[cur] != 2){
                    val = false;
                }
                visited[cur] = true;
                for(auto u : graph[cur]){
                    if(!visited[u]) s.push(u);
                }
            }
            if(val){
                answer++;
            }
        } 
    }

    cout << answer << endl;
}