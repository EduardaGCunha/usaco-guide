#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n;
int t; 
int s[N], e[N];
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s[i] >> e[i];
        }


        bool ok = true;
        for(int i = 1; i < n; i++){
            if(s[0] <= s[i] && e[0] <= e[i]){
                ok = false;
                break;
            }
        }

        if(!ok){
            cout << -1 << endl;
            continue;
        }

        cout << s[0] << endl;
    }
}