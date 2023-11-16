#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        for(int i = 0; i < s.size() - 1; i++){
            int l = i + i;
            while(s[i] == s[l]){
                i++;
                
            }
        }
    }
}