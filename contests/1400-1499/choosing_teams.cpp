//question link: https://codeforces.com/problemset/problem/432/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];
    int cnt =0, y = 0;
    sort(numbers.begin(), numbers.end());
    for(int i = 0; i < n; i++){
        if(numbers[i] + m <= 5) y++;
        if(y == 3){
            cnt++;
            y = 0;
        }
    }
    cout << cnt << endl;
}