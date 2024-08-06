#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
vector<pair<int, string>> graph[MAXN];
string ans[MAXN];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; string c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    queue<pair<int, string>> q;
    q.push({0, ""});
    q.push({n-1, ""});
    string prev = "";

}