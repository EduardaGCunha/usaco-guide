#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, h; cin >> n >> m >> h;
        pair<int, long long> rud;
        int ans = 1;
        for(int i = 0; i < n; i++){
            vector<int> values(m);
            for(int j = 0; j < m; j++){
                cin >> values[j];
            }
            sort(values.begin(), values.end());
            int cnt = 0;
            long long sum = 0, penalty = 0;
            for(auto v : values){
                if(sum + v <= h){
                    sum+= v;
                    penalty += sum;
                    cnt++;
                }
            }
            if(i){
                if(make_pair(-cnt, penalty) < rud) ans++;
            }else rud = {-cnt, penalty};
        }
        cout << ans << '\n';
    }
}