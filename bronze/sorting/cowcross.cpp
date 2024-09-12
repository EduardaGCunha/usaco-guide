#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    int ans = arr[0].first + arr[0].second;
    for(int i = 1; i < n; i++){
        if(ans > arr[i].first) ans += arr[i].second;
        else ans = arr[i].second + arr[i].first;
    }

    cout << ans << endl;

}