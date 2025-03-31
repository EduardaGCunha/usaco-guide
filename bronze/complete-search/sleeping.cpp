#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int maxsum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            maxsum += arr[i];
        }
        int ans = INT_MAX;
        //all possible sums I can make
        for(int i = 0; i <= maxsum; i++){
            if(i != 0 && (maxsum%i) != 0) continue;
            int j = 0, cnt = 0, cursum = 0;
            int ok = 1;
            while(j < n){
                cursum += arr[j];
                if(cursum > i){
                    ok = 0;
                    break;
                }else if(cursum == i){
                    cursum = 0;
                }
                j++;
            }

            if(ok){
                //cout << maxsum << " " << i << endl;
                if(i) cout << n - maxsum/i << endl;
                else cout << 0 << endl;
                break;
            }
        }
    }
}