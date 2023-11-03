#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    int total = 0;
 
    int sum = (n*(n+1))/2;
 
    if(sum % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    total = sum / 2;
    long long i = n;
    long long cnt = 0;
    vector<long long> values;
    vector<bool> arr(n+1, false);
    while(total > 0 && i > 0){
        if(total - i >= 0){
            arr[i] = true;
            total -= i;
            cnt++; 
        }
        i--;
    }

    cout << cnt << endl;

    vector<long long> toprint;
    for(long long i = 1; i <= n; i++){
        if(arr[i]) cout << i << " ";
        else toprint.push_back(i);
    }
    cout << endl << n - cnt << endl;
    for(auto v : toprint) cout << v << " ";
    cout << endl;

}