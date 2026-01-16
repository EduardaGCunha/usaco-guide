#include <bits/stdc++.h>
using namespace std;

 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 20;
const int MAXM = (1<<20)+7;
const int MOD = 1e9+7;
vector<int> graph[MAXN];
int dp[MAXN][MAXM];
int n; 

int pd(int v, int mask){
	auto& p = dp[v][mask];
	//cout << v+1 << " " << mask << endl;
	if(v == n-1){
		//cout << v+1 << " " << mask << endl;
		return p = (mask ==((1<<n)-1));
	}

	if(p != -1) return p;

	int ans = 0;
	//cout << graph[v].size() << endl;
	for(auto u : graph[v]){
		//cout << u+1 << " " << mask << " " << (1<<u) << endl;
		if(!((mask>>u)&1)){
			int newmask = mask | (1 << u);
			ans = (ans + pd(u, newmask))%MOD;
		}
	}
	return p = ans;
}

void solve(){
	int m; cin >> n >> m;
	memset(dp, -1, sizeof(dp));
    	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
	}
	cout << pd(0, 1) << endl;
	//cout << dp[3][15] << endl;	
}

signed main(){
	fastio;
    int t = 1;
	while(t--){
		solve();
	}
}
