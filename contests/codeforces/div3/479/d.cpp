#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll graph[100];
map<ll, bool> s;
map<ll, bool> deg;

vector<ll> ans;

void dfs(ll cur){
    if(s[cur*2]) dfs(cur*2);
    if((cur%3 == 0) && s[cur/3]) dfs(cur/3);
    ans.push_back(cur);
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> graph[i];
        s[graph[i]] = 1; 
        if(graph[i] % 3 == 0) deg[graph[i]/3] = 1;
        deg[graph[i]*2] = 1;
    }
    
    for(int i = 0; i < n; i++){
        if(deg[graph[i]] == 0){
            dfs(graph[i]);
            break;
        }
    }

    for (int i = n-1; i >= 0; i--) cout << ans[i] << " \n"[i==0];
    return 0;
}
