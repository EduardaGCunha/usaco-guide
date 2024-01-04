#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n; m = 2*n;
    vector<int> val(m);
    for(int i = 0; i < m; i++) cin >> val[i];
    sort(val.begin(), val.end());

    int ans = 1e9;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            vector<int> new_val;
            int minimum = 0;
            for(int p = 0; p < m; p++){
                if(p != i && p != j) new_val.push_back(val[p]);
            }

            for(int p = 0; p < m - 2; p += 2){
                minimum += abs(new_val[p+1] - new_val[p]);
            }
            ans = min(minimum, ans);
        }
    }

    cout << ans << endl;
    
}