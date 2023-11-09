#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long sum = 0;
        long long s = 0x3f3f3f3f;
        long long m = 0x3f3f3f3f;
        vector<long long> values;
        for(long long i = 0; i < n; i++){
            long long c; cin >> c;
            vector<long long> val(c);
            for(long long j = 0; j < c; j++){
                cin >> val[j];
            }
            sort(val.begin(), val.end());
            sum += val[1];
            m = min(m, val[0]);
            s = min(s, val[1]);
        }
        cout << sum + m - s << endl;
    }
}