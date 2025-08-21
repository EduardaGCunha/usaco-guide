#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'
string s = "gecy nw";
void rec(int x){
    for(auto i : s){
        if(i == ' '){
            cout << " ";
            continue;
        }
        char b = 'a' + ((i-'a') + x)%26;
        cout << b;
    }
    cout << endl;
}

signed main(){
	fastio;	
    for(int i = 0; i < 26; i++){
        rec(i);
    }
}