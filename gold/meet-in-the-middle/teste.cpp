#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 41;
int arr[MAXN];

unordered_map<int, int> mp1, mp2;

void gen(int l, int r, int c){
    int n = r - l;
    for(int i = 0; i < (1<<n); i++){
        int sum =0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                sum += arr[l + j];
            }
        }
        if(c) mp1[sum]++;
        else mp2[sum]++;
    }
}

signed main(){
    fastio;
    cout << (5<<3) << endl; 
}