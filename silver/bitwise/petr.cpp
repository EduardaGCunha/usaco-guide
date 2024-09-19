#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int mask = 0; mask < (1<<n)-1; mask++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i))sum += arr[i];
            else sum -= arr[i];
        }

        if(!sum || !(sum%360)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}