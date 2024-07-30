#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;
const int MAXN = 2*(1e5)+7;
vector<pair<int, int>> graph[MAXN];
int dist[MAXN][10];


int main(){
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int a, b; ll c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[0] = 0;
    
}