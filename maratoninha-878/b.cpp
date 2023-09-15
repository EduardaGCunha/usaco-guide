#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, q, cnt, i, j, size;
        cin >> n >> k >> q;

        size = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(a <= q) size++;
        }

        cnt = 0; i = -1;
        j = k - 2;
        while(i++ < max(size - k - 1, 0)){
            while(j++ < size-1){
                cnt++;
                cout << "j: " << j << endl;
                cout << cnt << endl;
            }
            j=i+1;
            cout << "i: " << i << endl;
        }

        cout << cnt  << endl;
    }
}