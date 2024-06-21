#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = (1e3)+7;
pair<int, int> coord[MAXN];
int n;

bool check(int mid){
    queue<int> s;
    int visited[MAXN];
    s.push(0);
    for(int i = 0; i < n; i++) visited[i] = 0;
    while(!s.empty()){
        int v = s.front(); s.pop();
        for(int i = 0; i < n; i++){
            int x = (coord[i].first - coord[v].first);
            int y = (coord[i].second - coord[v].second);
            int d = x*x + y*y;
            if(d <= mid && !visited[i]){
                //c++;
                visited[i] = 1;
                s.push(i);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]) return false;
    }
    return true;

}

signed main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        coord[i].first = x;
        coord[i].second = y;
    }

    int l = 0, r = 1e18;
    int valid = -1;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid))
        {
            valid = mid;
            r = mid;
        }
        else l = mid+1;
    } 
    cout << valid << endl;
}