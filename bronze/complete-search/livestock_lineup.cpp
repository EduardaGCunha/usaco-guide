#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());
    int n; cin >> n;
    vector<pair<string, string>> restrictions;
    for(int i = 0; i < n; i++){
        string a, b, t;
        cin >> a;
        cin >> t >> t >> t >> t;
        cin >> b;
        restrictions.push_back({a, b});
    }

    int cnt = 0;
    while(next_permutation(cows.begin(), cows.end())){
        bool passed = true;
        for(auto r : restrictions){
            auto a = find(cows.begin(), cows.end(), r.first);
            auto b = find(cows.begin(), cows.end(), r.second);
            if(abs(a-b) > 1){
                passed = false;
            }
        }
        if(passed) break;
    }

    for(auto a : cows){
        cout << a << endl;
    }
}