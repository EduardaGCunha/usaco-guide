#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int val[n];
    for(int i = 0; i < n; i++) cin >> val[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(val[j] > val[j + 1]){
                cnt++;
                swap(val[j], val[j+1]);
            }
        }
    }

    cout << "Array is sorted in " << cnt << " swaps" << endl;
    cout << "First element: " << val[0] << endl;
    cout << "Second element: " << val[n-1] << endl;
}