#include <bits/stdc++.h>
using namespace std;

//iterative dfs that isn't working
int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    int n; cin >> n;
    map<string, int> index;
    for(int i = 0; i < 8; i++){
        index[cows[i]] = i;
    }

    vector<set<int>> pairs(8);
    for(int i = 0; i < n; i++){
        string a, b, t;
        cin >> a >> t >> t >> t >> t >> b;
        int x = index[a], y = index[b];
        pairs[x].insert(y);
        pairs[y].insert(x);
    }

    vector<bool> visited(n, false);
    for(int i = 0; i < 8; i++){
        if(!visited[i] && pairs[i].size() < 2){
            cout << cows[i] << endl;
            visited[i];
            for(auto p : pairs[i]){
                if(!visited[p]){
                    visited[p] = true;
                    cout << cows[p] << endl;
                }
            }
        }
    }
    
}