#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;

    for(int i = 2; i < 10000; i++){
        long long val = 1 + i;
        long long p = i * i;
        for(int j = 2; j < 20; j++){
            val+=p; 
            if (val > 1e6) break;
            s.insert(val);
            p *= i;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        if(s.count(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}