#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5);
int pfx[MAXN+1], arr[MAXN];

signed main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];


    for(int i = 0; i < 30; i++){
        int sum = 0;
        
        /* contador de quantas vezes que a soma de xor seja maior q 0
        */
        vector<int> pref = {1, 0};
        for(auto a : arr){
            sum ^= (a >> i) & 1;

            ans += pref[s^1] * 1LL << i;
        }
    }
}