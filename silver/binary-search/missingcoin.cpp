#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int arr[MAXN];
int n; 

int check(int x){
    int i = n-1;
    while(x > 0){
        if(arr[i] >= x) x -= arr[i];
        i--;
    }
    return (x == 0);
}

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int l = 0, r = 1e18;
    while(l < r){
        int mid = (l+r)/2;
        //cout << mid << endl;
        if(check(mid)) l = mid+1;
        else r = mid;
    }

    cout << l+1 << endl;
}