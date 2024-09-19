#include <bits/stdc++.h>
using namespace std;

int main(){
    bitset<100000000001> visited;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        visited[a] = 1;
    } 

    cout << visited.count() << endl;
}