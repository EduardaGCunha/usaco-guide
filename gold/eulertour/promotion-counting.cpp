#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e5+7;
pair<int, int> arr[MAXN];
int visited[MAXN], tin[MAXN], tout[MAXN];
vector<int> graph[MAXN];
int t = 0;

struct BIT{
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n;
        bit.resize(n+1, 0);
    }

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)) bit[x] += v;
    }

    int query(int x){
        int sum = 0;
        for(; x > 0; x -= x&(-x)) sum += bit[x];
        return sum;
    }
};

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
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    //cout << "passou da leitura dos valores\n";
    for(int i = 1; i <= n-1; i++){
        int a; cin >> a;
        a--;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }
    //cout << "passou da leitura do grafo\n";    
    //fazer a euler tour e pegar as queries
    dfs(0);
    sort(arr, arr+n);
    BIT bit;
    bit.init(n+1);
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        int v = arr[i].second;
        ans[v] = bit.query(tout[v]) - bit.query(tin[v]-1);
        bit.upd(tin[v], 1);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << endl;

}