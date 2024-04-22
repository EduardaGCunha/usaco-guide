#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int n, k;
int arr[MAXN];

bool check(int r){
    int i = 0, cnt = 0;
    while(i < n){
        int cur = arr[i];
        while(i < n && arr[i] <= cur + 2*r)i++;
        cnt++;
    }
    //cout << cnt << " " << (cnt <= k) << endl;
    return cnt <= k;
}

signed main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r = 1e18;
    while(l < r){
        int mid = (r+l)/2;
        if(check(mid) == 1){
            r = mid;
        }else{
            l = mid + 1;
        }
        //cout << mid << endl;
    }

    cout << r << endl;
}   