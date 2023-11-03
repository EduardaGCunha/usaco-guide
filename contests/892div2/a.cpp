#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> values(n, 0);
        for(auto &a : values) cin >> a;
        sort(values.begin(), values.end());
        if(values.back() == values[0]){
            cout << "-1" << endl;
        }else{
            int i = 0;
            while(values[i] == values[0]) i++;
            cout << i << " " << n - i << endl;
            for(int j = 0; j < i; j++) cout << values[j] << " ";
            cout << endl;
            for(int j = i; j < n; j++) cout << values[j] << " ";
            cout << endl;
        }
    }
    return 0;
}