#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool first = false;
        int f, l = 0;
        vector<int> values(n);
        for(int i = 0; i < n; i++){
            cin >> values[i];
            if(values[i] == 1){
                if(first == false){
                    f = i;
                    first = true;
                }
                l = i;
            }
        }

        int cnt = 0;
        while(f++ != l){
            if(values[f] == 0) cnt++;
        }
        cout << cnt << endl;
    }
}