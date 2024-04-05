#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<'){
                st.push(s[i]);
            }else{
                if(!st.empty() && s[i] == '>'){
                    cnt++;
                    st.pop();
                }
            }
        }
        cout << cnt << endl;

    }
}