#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n; cin >> n;
	vector<int> prefix(n);
    prefix[0] = 1;
	for(int i = 0, sum = 0; i < n; i++){
		int a; cin >> a;
	    sum += a;
		prefix[(sum%n+n)%n]++;
	}
	int ans = 0;
	for(auto a : prefix){
		ans += ((a)*(a-1)/2);
	}
	cout << ans << "\n";
}