#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    map<string, int> cows_ind;
    for(int i = 0; i < 8; i++){
        cows_ind[cows[i]] = i;
    }
    vector<vector<int>> pairs(8);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string a, b, t;
        cin  >> a >> t >> t >> t >> t >> b;
        int c = cows_ind[a];
        int d = cows_ind[b];
        pairs[c].push_back(d);
        pairs[d].push_back(c);
    }

    bool visited[8, false];
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        else{
            visited[i] = true;
            cout << cows[i] << endl;
            for(auto a : pairs){
                visited[i] = true;
                cout << a << endl;
            }
        }
    }
}