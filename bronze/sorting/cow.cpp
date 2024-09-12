#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int idx = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]*(i+1) >= sum){
            sum = arr[i]*(i+1);
            idx = arr[i];
        }   
    }

    cout << sum << " " << idx << endl;
}