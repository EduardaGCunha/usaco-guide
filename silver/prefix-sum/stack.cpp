#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}


int main(){

    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int v = st.top(); st.pop();
        for(auto u : graph[v]){
            if(!visited[u]){
                visited[u] = 1;
                st.push(u);
            }
        }
    }
}