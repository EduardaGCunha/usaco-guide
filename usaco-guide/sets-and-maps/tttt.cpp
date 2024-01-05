#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    int n = 3;
    vector<string> tictac(n);
    int unit_win = 0, team_win = 0;
    for(int i = 0; i < n; i++){
        set<char> s;
        cin >> tictac[i];
        for(int j = 0; j < n; j++){
            s.insert(tictac[i][j]);
        }
        if(s.size() == 1) unit_win++;
        else if(s.size() == 2) team_win++;
    }

    //checando vertical
    for(int i = 0; i < n; i++){
        set<char> s;
        for(int j = 0; j < n; j++){
            s.insert(tictac[j][i]);
        }
        if(s.size() == 1) unit_win++;
        else if(s.size() == 2) team_win++;
    }

    set<char> s, t;
    for(int i = 0; i < n; i++){
        s.insert(tictac[i][i]);
        int j = n - i - 1;
        t.insert(tictac[j][i]);
    }
    if(s.size() == 1) unit_win++;
    else if(s.size() == 2) team_win++;
    if(t.size() == 1) unit_win++;
    else if(t.size() == 2) team_win++;
    
    // cout << unit_win << endl;
    // cout << team_win << endl;
}