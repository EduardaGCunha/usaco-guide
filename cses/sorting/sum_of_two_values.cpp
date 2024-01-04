#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> val;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        val.push_back({a, i+1});
    }

    sort(val.begin(), val.end());
    int left = 0, right = n - 1;
    while(left < right){
        if(val[left].first + val[right].first == m){
            cout << val[left].second << " " << val[right].second << endl;
            return 0;
        }else if(val[left].first + val[right].first > m){
            right--;
        }else{
            left++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}