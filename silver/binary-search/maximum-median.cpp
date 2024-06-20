#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2*(1e5);

int arr[MAXN];
int n, k;

bool check(int mid){
    int cnt = 0;
    for(int i = (n/2); i < n; i++){
        if(arr[i] < mid){
            cnt += mid - arr[i];
            if(cnt > k) return 0;
        }
    }
    return cnt <= k;
}

signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r = 2e18;
    while(l < r){
        int mid = (l+r)/2;  
        if(check(mid) == 0){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << r << endl;
} 