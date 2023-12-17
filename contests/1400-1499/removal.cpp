#include <bits/stdc++.h>
using namespace std;

string deleter(string s){
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != s[i-1]){
            s = s - s[i];
            cout << s << endl;
        }
    }
    return s;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string t = string(deleter);
    }
}