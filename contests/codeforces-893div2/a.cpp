#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        map<char, int> m; 
        string s; cin >> s;
        for(int i = 0; i < s.size(); i++){
           m[s[i]] += 1; 
        }


        string result = "YES";  
        for(auto v : m){
            cout << v.second << endl;
            if((v.second % 2) == 1 && v.second < k + 1){
                result = "NO";
            }
        }

        cout << result << endl;


    }
}