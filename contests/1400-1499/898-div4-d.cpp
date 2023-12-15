#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        string s; cin >> s;

        int i = -1;
        int cnt = 0;
        while(i++ < a){
            if(s[i] == 'B'){
                cnt++;
                i = i + b - 1;
            }
        }
        cout << cnt << endl;
    }
}