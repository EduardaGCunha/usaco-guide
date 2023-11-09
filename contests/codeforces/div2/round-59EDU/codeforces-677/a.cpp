#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int t = (int(s[0]) - 48 - 1)*10;
        for(int i = 1; i <= s.length(); i++){
            t += i; 
        }
        cout << t << endl;
    }
}