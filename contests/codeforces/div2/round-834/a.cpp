#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int j = 0;
        string result = "YES";
        vector<char> yes = {'Y', 'e', 's'};
        while(yes[j] != s[0] && j < 3) j++;
        if(j == 3){
            cout << "NO" << endl;
            continue;
        }

        for(int i = 0; i < s.length(); i++){
            if(yes[j] != s[i]){
                result = "NO";
                break;
            }
            j = (j+1)%3;
        }

        cout << result << endl;
    }
}