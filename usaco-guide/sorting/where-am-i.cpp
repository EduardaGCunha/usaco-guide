#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n, k = 0; cin >> n;
    string s; cin >> s;
    set<char> val;
    for(int i = 0; i < n - 1; i++){
        if(val.count(s[i]) == 0){
            val.insert(s[i]);
        }else{
            k = i;
            break;
        }
    }

    cout << k << endl;

}