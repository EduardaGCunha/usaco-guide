#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> coord(n);
    int radius[n+1];
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        coord[i].first = a;
        coord[i].second = b;
        radius[i] = c;
    }

    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++){
        int x1 = coord[i].first, y1 = coord[i].second;
        for(int j = i+1; j < n; j++){
            int x2 = coord[j].first, y2 = coord[j].second;
            int res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            if(res <= radius[i]){
                ans[i]++;
            }
        }
    }

    int res = 0;
    for(int i =0; i < n; i++){
        res = max(res, ans[i]);
    }
    cout << res << endl;
}