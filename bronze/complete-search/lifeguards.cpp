#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    //1 4
    //3 7
    //4 5
    //5 9
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        int prv = i-1;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if(prv != -1 && arr[prv].second > arr[j].first){
                if(arr[prv].first > arr[j].first){
                    cnt += arr[j].first - arr[prv].first;
                }
                cnt += arr[j].second - arr[prv].second;
            }else cnt += arr[j].second - arr[j].first;
            prv = j;
        }
        //cout << cnt << endl;
        ans = max(ans, cnt);
    }
    cout << ans+1 << endl;
}