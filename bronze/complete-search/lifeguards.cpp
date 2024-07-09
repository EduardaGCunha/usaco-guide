#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr+n);
    int res = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += arr[j].second - arr[j].first;
            if(j-1 == i || j-1 < 0 || arr[j-1].second < arr[j].first) continue;
            sum -= arr[j-1].second - arr[j].first;
        }
        res = max(res, sum);
    }
    cout << res << endl;
}