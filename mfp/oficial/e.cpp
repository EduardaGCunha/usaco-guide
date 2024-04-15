#include <bits/stdc++.h>
using namespace std;

// struct Pos {
// 	int x, y;
// };
// bool operator<(const Pos &a, const Pos &b) { return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y)); }

int main(){
    int n, q, d; 
    cin >> n >> q >> d;
    map<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        m[i] = {a, b};
    }
    for(auto a : m){
        cout << a.first<< " " << a.second.first << " " << a.second.second << endl;
    }

}