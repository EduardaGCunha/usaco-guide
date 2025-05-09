#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 41;
int arr[MAXN];

unordered_map<int, int> mp1, mp2;

void gen(int l, int r, int c){
    int n = r - l;
    for(int i = 0; i < (1<<n); i++){
        int sum =0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                sum += arr[l + j];
            }
        }
        if(c) mp1[sum]++;
        else mp2[sum]++;
    }
}

signed main(){
    fastio;
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> arr[i];

    mp1.reserve(1<<(n/2));
    mp2.reserve(1<<(n-n/2));
    gen(0, n/2, 1);
    gen(n/2, n, 0);

    int ans = 0;
    for(auto u : mp1){
        //cout << u.first << " " << u.second << endl;
        int k = x - u.first; 
        auto it = mp2.find(k);
        if(it != mp2.end()) ans += (u.second * it->second);
    }

    cout << ans << endl;
}