#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5;
 
signed main(){
    fastio;
    int n; cin >> n;
    vector<array<int, 3>> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end());
    //we'll be storing our end times and current room;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    int arr[MAXN];
    int ans = 0, curr_room = 0;
    for(int i = 0; i < n; i++){
        if(pq.empty()){
            curr_room++;
            arr[v[i][2]] = curr_room;
            pq.push({v[i][1], curr_room});
        }else{        
            if(pq.top().first < v[i][0]){
                arr[v[i][2]] = pq.top().second;
                pq.pop();
                pq.push({v[i][1], arr[v[i][2]]});
            }else{
                curr_room++;
                arr[v[i][2]] = curr_room;
                pq.push({v[i][1], curr_room});
            }
        }
        int a = pq.size();
        ans = max(ans, a);
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}
