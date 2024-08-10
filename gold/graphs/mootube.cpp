#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
int p[MAXN], r[MAXN], sum[MAXN];

int find(int a) {
    return p[a] = (p[a] == a)? a : find(p[a]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]){
        p[b] = a;
        sum[a] += sum[b];
    }else{
        p[a] = b;
        sum[b] += sum[a];
    }
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q; cin >> n >> q;

    for(int i = 0;  i< n; i++){
        sum[i] = 1;
        r[i] = 0;
        p[i] = i;
    }
    vector<tuple<int, int, int>> graph;
    for(int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        graph.push_back({c, a, b});
    }

    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; i++){
        int k, v; cin >> k >> v;
        queries.push_back({k, v, i});
    }

    sort(graph.rbegin(), graph.rend());
    sort(queries.rbegin(), queries.rend());
    int edge = 0;

    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int k = get<0>(queries[i]);
        int v = get<1>(queries[i]);
        int idx = get<2>(queries[i]);

        while(edge < graph.size() && get<0>(graph[edge]) >= k){
            unite(get<1>(graph[edge]), get<2>(graph[edge]));
            edge++; 
        }
        
        ans[idx] = sum[find(v)]-1;
    }

    for(auto a : ans) cout << a << endl;
}
