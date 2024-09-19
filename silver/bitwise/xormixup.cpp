#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        int total;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                sum ^= arr[j];
            }

            cout << sum << endl;
        }
    }
}