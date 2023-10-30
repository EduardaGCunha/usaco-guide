#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char d; cin >> d;
        string result = "";
        int cnt = 1;
        for(int i = 0; i < n; i++){
            char a; cin >> a;
            if(d > a && cnt == 1){
                result += d;
                cnt--;
            }
            result += a;
        }
        if(cnt == 1){
            result += d;
        }

        cout << result << endl;
    }
}