#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int n; cin >> n;
    pair<int, int> tasks[n+1];
    for(int i = 0; i < n; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks, tasks + n);
    int duration = 0, rewards = 0;
    for(int i = 0; i < n; i++){
        duration += tasks[i].first;
        rewards += tasks[i].second - duration;
    }
    cout << rewards << endl;
}