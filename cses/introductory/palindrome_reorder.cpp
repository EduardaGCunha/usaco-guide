#include <bits/stdc++.h> 
using namespace std;


int main(){
    string s; cin >> s;
    map<char, int> abc;
    for(int i = 0; i < s.size(); i++){
        abc[s[i]] += 1;
    }
    int odd_cnt = 0;
    string r = "";

    char middle;
    int middle_cnt = 0;
    for(auto a : abc){
        if(a.second % 2 != 0){
            odd_cnt++;
            if(odd_cnt > 1){
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            middle = char(a.first);
            middle_cnt = a.second;
            continue;
        }
        for(int i = 0; i < a.second/2; i++){
            r += char(a.first);
        }
    }

    int v = r.size();
    if(s.size()%2 != 0){
        for(int i = 0; i < middle_cnt; i++){
            r+=char(middle);
        }
    }
    for(int i = v-1; i >= 0; i--){
            r+=char(r[i]); 
    }

    cout << r << endl;
    return 0;

}