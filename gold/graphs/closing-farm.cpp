#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5)+7;
int p[MAXN], r[MAXN], open[MAXN];
vector<int> graph[MAXN];

int get(int a){
    return (p[a] == a)? a : get(p[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);

    if(a == b) return;

    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]) p[b] = a;
    else p[a] = b;
}

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        r[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int rev[n];
    for(int i = 0; i < n; i++){
        cin >> rev[i];
    }   
    vector<string> ans;
    int comp = 0;
    for(int i = n-1; i >= 0; i--){
        int v = rev[i];
        comp++;

        open[v] = 1;
        for(auto u : graph[v]){
            if(open[u] && get(u) != get(v)){
                unite(u, v);
                comp--;
            }
        }
        if(comp == 1) ans.push_back("YES");
        else ans.push_back("NO");
    }

    for(int i = ans.size()-1; i>=0; i--) cout << ans[i] << endl;
}