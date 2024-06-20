#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n, m;
pair<int, int> p[MAXN];

bool check(int d){
    int cnt = 1, cur = p[0].first;
    for(int i = 0; i < m; i++){
        if(cur + d <= p[i].first){
            cur = p[i].first;
            cnt++;
        }
        while(cur + d >= p[i].first && cur + d <= p[i].second){
            cnt++;
            cur += d;
        }
    }
    return cnt >= n;
}

signed main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        p[i].first = a;
        p[i].second = b;
    }
    sort(p, p+m);

    int l = 0, r = p[m-1].second;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    cout << l-1 << endl;
}