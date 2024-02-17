#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n, t, ans = 0; cin >> n >> t;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        t-arr[i];
        if(t-arr[i] < 0) break;
        ans++;
    }

    cout << ans << endl;

}