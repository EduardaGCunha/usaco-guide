#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n; cin >> n;
    vector<int> indeg(n, 0), outdeg(n, 0);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        outdeg[a]++, indeg[b]++;
    }
    
    bool res = false;
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(res && indeg[i] > 0 && outdeg[i] == 0){
            ans = -1;
            break;
        }
        if(indeg[i] > 0 && outdeg[i]==0){
            ans = i;
            res = true;
        }
    }

    cout << ans + 1<< endl;
}