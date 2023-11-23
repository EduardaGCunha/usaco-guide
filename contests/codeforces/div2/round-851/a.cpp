#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> values(n);
        int i, cnt = 0;
        for(i = 0; i < n; i++){
            cin >> values[i];
            if(values[i] == 2) cnt++;
        }

        if(cnt % 2 != 0) {
            cout << -1 << endl;
            continue;
        }

        cnt = cnt/2;
        for(i = 0; i < n; i++){
            if(values[i] == 2) cnt--;
            if(cnt == 0) break;
        }

        cout << i + 1<< endl;
    }
}