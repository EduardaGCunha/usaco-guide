#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Bit {
    int n; 
    vector<int> bit;
    Bit(int _n = 0) : n(_n), bit(n+1){}

    void update(int i, int x){
        for(i++; i <=n; i+= (i&(-i))) bit[i] += x;
    }

    int pref(int i){
        int ret = 0;
        for(i++; i; i -= (i&(-i))) ret += bit[i];
        return ret;
    }

};

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        Bit bit(n+1);
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<int> srt = arr;
        sort(srt.begin(), srt.end());
        for(int i = 0; i < n; i++){
            arr[i] = lower_bound(srt.begin(), srt.end(), arr[i]) - srt.begin() + 1;
        }

        int res =0;
        for(int i = n-1; i >= 0; i--){
            res += bit.pref(arr[i]-1);
            bit.update(arr[i], 1);
        }
        cout << res << endl;
    }
}