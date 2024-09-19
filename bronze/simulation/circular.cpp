#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i, c = 0; c < n; j++, c++){
            if(j == n) j = 0;
            sum += arr[j]*c;
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}