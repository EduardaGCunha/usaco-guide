#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    int c_max = 0;
    for(int i = 0; i < n; i++){
        c_max = max(cnt, c_max);
        if(s[i] == s[i+1]) cnt++;
        else cnt = 0;
    }
    cout << c_max + 1 << endl;
}