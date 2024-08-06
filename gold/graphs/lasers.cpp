#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<pair<int, int>> fences;
int n, xl, yl, xb, yb;

void dfs(int x, int y, int i){
    
}

int main(){
    cin >> n >> xl >> yl >> xb >> yb;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        fences.push_back({a, b});
    }

    sort(fences.begin(), fences.end());    
}