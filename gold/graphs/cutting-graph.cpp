#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int p[MAXN], r[MAXN];


int get(int a) {
    return p[a] = (p[a] == a)? a : get(p[a]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);

    if(a == b) return;
    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]){
        p[b] = a;
    }else p[a] = b;
}


int main(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        p[i] = i;
        r[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<tuple<string, int, int>> queries;
    for(int i = 0; i < q; i++){
        string s;
        int a, b; 
        cin >> s >> a >> b;
        queries.push_back({s, a, b});
    }

    vector<string> ans;
    for(int i = q-1; i >= 0; i--){
        string s = get<0>(queries[i]);
        int a = get<1>(queries[i]);
        int b = get<2>(queries[i]);

        if(s == "ask"){
            get(a) == get(b) ? ans.push_back("YES") : ans.push_back("NO");
        }else{
            unite(a, b);
        }
    }

    for(int i = ans.size() -1; i>= 0; i--) cout << ans[i] << endl;
}