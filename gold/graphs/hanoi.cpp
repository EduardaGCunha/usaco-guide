#include <bits/stdc++.h>
using namespace std;


int main(){
    int k; cin >> k;

    int n = 3;
    vector<vector<int>> hanoi(n, vector<int>(k));
    for(int i = 0; i < k; i++){
        hanoi[0].push_back(i);
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        
    }


}