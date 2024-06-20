#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n; 
int arr[MAXN];

int check(int x){
    int i = n-1;
    while(x > 0 && i > 0){
        if(x >= arr[i]) x -= arr[i];
        i--;
    }
    return x >= 0;
}


signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r = 1e18;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}