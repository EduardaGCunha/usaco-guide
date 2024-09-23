#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    vector<array<int, 3>> v(m); 
    for (array<int, 3> &arr : v) {
		cin >> arr[0] >> arr[1] >> arr[2];
	}

    vector<int> pfx(m+2);
    vector<int> final(n+2, 0);

    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        pfx[a]++;
        pfx[b+1]--;
    }

    for(int i = 1; i <= m; i++){
        pfx[i] += pfx[i-1];
        final[v[i-1][0]] += v[i-1][2] * pfx[i];
        final[v[i-1][1]+1] -= v[i-1][2] * pfx[i];

    }

    for(int i = 1; i <= n; i++){
        final[i] += final[i-1];
        cout << arr[i] + final[i] << " ";
    }

    cout << endl;

}