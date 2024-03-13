#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    pair<int, int> movie[n+1];
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        movie[i].first = b, movie[i].second = a;
    }
    sort(movie, movie + n);
    
    int film = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(movie[i].second >= film){
            ans++;
            film = movie[i].first;
        }
    }

    cout << ans << endl;
}
