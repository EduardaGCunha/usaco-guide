#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> answers;
    for(int i = 0; i < t; i++){
        int n, m, k, h, ans;
        cin >> n >> m  >> k >> h;
        ans = 0;
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            ans += (h != x ) && abs(h - x) % k == 0 && abs(h - x) <= (m-1) * k;
        }
        answers.push_back(ans);
    }

    for(auto a : answers){
        cout << a << endl;
    }
}