#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int MAXN = 2*(1e5)+1;
int n, q, arr[MAXN];

Tree<pair<int, int>> t;

int main(){
    fastio;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        t.insert({arr[i], i});
    }

    while(q--){
        char op; cin >> op;
        if(op == '!'){
            int x, y; cin >> x >> y;
            t.erase({arr[x], x});
            arr[x] = y;
            t.insert({arr[x], x});
        }else{
            int x, y; cin >> x >> y;
            cout << t.order_of_key({y, MOD}) - t.order_of_key({x-1, MOD}) << endl;
        }
    }
}