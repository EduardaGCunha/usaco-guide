#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        int a; cin >> a; a--;
        if(s[a] == '1') s[a] = '0';
        else s[a] = '1';
        
    }
}