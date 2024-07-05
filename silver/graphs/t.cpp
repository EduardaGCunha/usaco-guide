#include <bits/stdc++.h>
using namespace std;
 
#define fastio cin.tie(0); ios_base::sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
 
const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN];
 
signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
            graph[i].clear();
        }
 
        for(int i = 0; i < n-1; i++){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int cnt =0;
        string res = "YES";
        for(int i = 0; i < n; i++){
            if(graph[i].size() > 3){
                res = "NO";
                break;
            }else if(graph[i].size() == 3) cnt++;
        }

        if(cnt > 2) res = "NO";
        cout << res << endl;
    }
}