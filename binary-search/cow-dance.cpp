#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n, t;
int arr[MAXN];

bool check(int k){
    priority_queue<int> q;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(q.size() == k){
            time = -q.top();
            q.pop();
        }
        if(time + arr[i] > t){
            return false;
        }
        else{
            q.push(-time -arr[i]);
        }
    }
    return true;
}

signed main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int l = 1, r = n;
    while(l != r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}