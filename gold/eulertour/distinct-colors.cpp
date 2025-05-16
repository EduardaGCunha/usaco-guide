#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5)+7;
int tin[MAXN], tout[MAXN], visited[MAXN];
vector<int> graph[MAXN];
int t = 0;

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.assign(n, 0);
    }

    void update(int x, int v){
        for(; x <= n; x += x&(-x)) bit[x] += v;
    }

    int query(int b){
        int sum = 0;
        for(; b > 0; b -= b&(-b)) sum += bit[b];
        return sum;
    }
};

//fazendo euler tour p/ linearizar a arvore
void dfs(int v){
    visited[v] = 1;
    tin[v] = ++t;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    tout[v] = t;
}


signed main(){
    fastio;
    int n; cin >> n;
    int arr[n+1];
    //talvez de problema por a bit ser 0 ou 1 indexada sla
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1);

    map<int, vector<pair<int, int>>> queries;
    for(int i = 1; i <= n; i++){
        //cout << i << ": " << tin[i] << " " << tout[i] << endl;
        queries[tin[i]].push_back({tout[i], i});
    }

    //forgot to take into consideration the color at the tin time
    vector<int> color_at_time(n+1);
    for(int v = 1; v <= n; v++){
        color_at_time[tin[v]] = arr[v];
    }
    
    BIT bit;
    bit.init(n+1);
    vector<int> ans(n+1);
    map<int, int> freq;
    for(int i = n; i > 0; i--){
        int val = color_at_time[i];
        if(freq.count(val) > 0){
            bit.update(freq[val], -1);
        }

        freq[val] = i;
        bit.update(i, 1);

        for(auto u : queries[i]){
            ans[u.second] = bit.query(u.first);
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}