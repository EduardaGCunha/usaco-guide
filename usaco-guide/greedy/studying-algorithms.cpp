#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(x - arr[i] >= 0){
            x-= arr[i];
            ans++;
        }
    }
    cout << ans << endl;
}