#include <bits/stdc++.h>
using namespace std;

struct val{
    int a, b, idx;
};

int main(){
    int n; cin >> n;
    vector<val> east, north;
    for(int i = 0; i < n; i++){
        char dir; cin >> dir;
        val x; cin >> x.a >> x.b; 
        x.idx = i;
        if(dir == 'E') east.push_back(x);
        else north.push_back(x);
    }

    sort(north.begin(), north.end(), [&](const val &v1, const val &v2) {return v1.a < v2.a;});
    sort(east.begin(), east.end(), [&](const val &v1, const val &v2) {return v1.b < v2.b;});
    vector<int> ans(n, -1);
    for(auto n : north){
        auto [x, y, idx] = n;
        for(auto e : east){
            auto [a, b, i] = e;
            if(x > a && y < b){
                if(b - y < x - a && ans[i] == -1){
                    ans[i] = x - a;
                }
                if(b - y > x - a && ans[i] == -1){
                    ans[idx] = b - y;
                    break;
                }
            }
        }
    }

    for (int d : ans) { cout << (d == -1 ? "Infinity" : to_string(d)) << '\n'; }

}