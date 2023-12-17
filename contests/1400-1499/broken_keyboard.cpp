#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int b = 0, B = 0;
        string res = "";
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == 'b') b++;
            else if(s[i] == 'B') B++;
            else{
                if(s[i] > 92 && b) b--;
                else if(s[i] < 92 && B) B--;
                else res+= s[i];
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    
}