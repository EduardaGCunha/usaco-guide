#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 0x3f3f3f3f;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<long long> values(n);
        for(int i = 0; i < n; i++){
            cin >> values[i];
        }

        sort(values.begin(), values.end());

        ll res = values[n-1] + values[n-2] - (values[0] + values[1]);
        cout << res << endl;

    }
}