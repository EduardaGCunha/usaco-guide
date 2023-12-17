#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt_l = 0, cnt_o = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') cnt_l++;
        else cnt_o++;
    }
    int curL = 0, curO = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'L') cnt_l--, curL++;
        else cnt_o--, curO++;
        if(curL != cnt_l && curO != cnt_o){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}