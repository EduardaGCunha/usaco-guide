#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    for(auto u : s){
        if(u >= 'a' && u <= 'z'){
            char t = (u-'a'+13)%26 + 'a';
            cout << t;
        }else if(u >= 'A' && u <= 'Z'){
            char t = (u-'A'+13)%26 + 'A';
            cout << t;
        }else{
            cout << u;
        }
    }
    cout << endl;
}