#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    int st = 0;
    int m = 1;
    //1 1 3 4 6
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] - arr[i] > k){
                m = max(m, j - i);
            }
        }
    }
    cout << m << endl;
}