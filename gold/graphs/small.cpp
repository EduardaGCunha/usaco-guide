#include <bits/stdc++.h>
using namespace std;

int sumN(int n){
    int sum = 0;
    while(n != 0){
        sum += n % 10;
        n /=10;
    }

    return sum;
}

int main(){
    int k; cin >> k;

    unordered_set<int> vis;
    queue<int> q;
    q.push(k);
    int x = 1;

    int res = INT_MAX;
    while(!q.empty() && x < 10000){
        int v = q.front(); q.pop();
        int sum = sumN(v);
        //cout << sum << " " << v << endl;
        res = min(res, sum);
        if(vis.find(v) != vis.end()) continue;
        cout << sum << endl;
        vis.insert(v);
        q.push({k*x});
        x++;
    }

    cout << res << endl;
}