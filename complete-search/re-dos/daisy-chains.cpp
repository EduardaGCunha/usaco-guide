#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int val[n];
    for(int i = 0; i < n; i++) cin >> val[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += val[j];
            for(int k = i; k <= j; k++){
                if(sum == val[k]*(j - i + 1)){
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
}