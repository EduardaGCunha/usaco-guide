#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    int pfx[n+1];
    pfx[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pfx[i] = arr[i] + pfx[i-1];
    }

    int ans = pfx[1], low = pfx[0];
    for(int i = 0; i < n; i++){
        ans = max(ans, pfx[i] - low);
        low = min(low, pfx[i]);
    }

    cout << ans << endl;
}