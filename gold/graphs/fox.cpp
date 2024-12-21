#include <bits/stdc++.h>
using namespace std;



int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> graph(27, vector<int>());
    vector<int> indeg(27, 0);
    int pos = 1;
    for(int k = 1; k < n; k++){
        string t; cin >> t;
        int m = min(s.length(), t.length());
        int i = 0;
        while(i < m){
            if(s[i] != t[i]){
                graph[s[i]-'a'].push_back(t[i]-'a');
                indeg[t[i]-'a']++;
                break;
            }
            i++;
        }

        if(i == m && s.length() > t.length()){
            pos = 0;
        }
        s = t;
    }

    if(!pos){
        cout << "Impossible\n";
        return 0;
    }

    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(!indeg[i]) q.push(i);
    }

    vector<int> toposort;
    int cnt = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        toposort.push_back(v);
        for(auto u : graph[v]){
            if(--indeg[u] == 0) q.push(u);
        }
        cnt++;
    }
    if(cnt < 26){
        cout << "Impossible\n";
        return 0;
    }

    for(auto u : toposort){
        char a = u+'a';
        cout << a;
    }
    cout << endl;


}