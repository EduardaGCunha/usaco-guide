#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define int ll
const int INF = 0x3f3f3f3f3f3f3f3f;
void solve(){
	int h,w,k; cin >> h >> w >> k;
	vector<string> b(h);
	for(auto &x:b) cin >> x;
	int ans = INF;
	for(int i=0;i<h;i++){
		int cur = 0;
		int sz = 0;
		for(int j=0;j<w;j++){
			if(b[i][j] == 'x'){
				cur = sz = 0;
				continue;
			}
			cur += (b[i][j] == '.');
			sz++;
			if(sz > k){
				sz--;
				cur -= (b[i][j-k] == '.');
			}
			if(sz == k) ans = min(ans,cur);
		}
	}
	for(int j=0;j<w;j++){
		int cur = 0;
		int sz = 0;
		for(int i=0;i<h;i++){
			if(b[i][j] == 'x'){
				cur = sz = 0;
				continue;
			}
			cur += (b[i][j] == '.');
			sz++;
			if(sz > k){
				sz--;
				cur -= (b[i-k][j] == '.');
			}
			if(sz == k) ans = min(ans,cur);
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << "\n";
}

signed main(){
	fastio;
	solve();
}

