#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int visited[MAXN][MAXN];

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, k, n;
    cin >> x >> y >> k >> n;

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});

    int ans = INT_MAX;
    while(!q.empty()){
        auto [a, b, c] = q.front();
        q.pop();
        //cout << a << " " << b << endl;
        ans = min(abs(n - (a+b)), ans);
        if(c >= k || visited[a][b]) continue;
        visited[a][b] = 1;
        if(a < x) q.push({x, b, c+1});
        if(b < y) q.push({a, y, c+1});
        if(a > 0) q.push({0, b, c+1});
        if(b > 0) q.push({a, 0, c+1});
        if(a > 0 && b < y) q.push({max(0, a - (y - b)), min(y, a + b), c + 1});
        if(b > 0 && a < x) q.push({min(x, a + b), max(0, b - (x-a)), c+1});
    }

    cout << ans << endl;
}
