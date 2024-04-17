#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    int n; cin >> n;
    vector<int> values = {0, 1, 2};
    vector<int> counter(3);
    for(int i = 0; i < n; i++){
        int a, b, g;
        cin >> a >> b >> g;
        a--, b--, g--;
        swap(values[a], values[b]);
        counter[values[g]]++;
    }

    freopen("shell.out", "w", stdin);
    int m = max({counter[0], counter[1], counter[2]});
    printf("%d", m);
}