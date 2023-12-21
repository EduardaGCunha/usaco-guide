#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowsignal.in", "r", stdin);
    int n, m, k; cin >> n >> m >> k;
    vector<string> values(n);
    vector<string>answers;
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    int cnt = 1;
    for(int i = 0; i < n; i++){
        int c = k;
        string s = values[i];
        string t = "";
        for(int j = 1; j <= m; j++){
            if(s[j] == s[j-1]){
                cnt++;
                t+= s[j-1];
            }
            else{
                cnt = (cnt*k)-cnt + 1;
                while(cnt--){
                    t+= s[j-1];
                }
                cnt = 1;
            }
        }
        while(c--){
            answers.push_back(t);
        }
    }

    freopen("cowsignal.out", "w", stdout);
    for(auto a : answers){
        cout << a << endl;
    }
    

}