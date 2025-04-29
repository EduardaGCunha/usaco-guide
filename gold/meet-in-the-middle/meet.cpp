#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    //criar as primeiras n somas
    map<int, int> mp1;
    int mx = (1<<(n/2));
    for(int i = 0; i < mx; i++){
        for(int j = 0; j < n/2; j++){
            if(i&(1<<j)){
                mp1[arr[i] + arr[j]]++;
            }
        }
    }


}