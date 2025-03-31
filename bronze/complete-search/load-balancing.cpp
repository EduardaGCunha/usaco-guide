#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, b; cin >> n >> b;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    int ans = INT_MAX;
    for(int i= 0; i < n; i++){
        for(int k = 0; k < n; k++){
            int qx = x[i]+1;
            int qy = y[k]+1;
            int q1 = 0, q2 = 0,  q3 = 0, q4 = 0;
            for(int j = 0; j < n; j++){
                if(x[j] > qx && y[j] > qy) q1++;
                if(x[j] > qx && y[j] < qy) q2++;
                if(x[j] < qx && y[j] > qy) q3++;
                if(x[j] < qx && y[j] < qy) q4++;
            }
            ans = min(ans, max({q1, q2, q3, q4}));
        }
    }
    cout << ans << endl;
}