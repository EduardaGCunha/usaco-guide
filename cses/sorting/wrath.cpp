#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n; 
    vector<long long> people(n);
    for(long long i = 0; i < n; i++){
        cin >> people[i];
    }

    int ans = 0;
    int j = 0;
    for(int i = n-1; i >= 0; i--){
        if(j == 0 && people[i] != -1) {
            ans++;
            j = people[i];
        } else if(j) {
            int b = people[i];
            j = max(j - 1, b);
        } else j--;
    }

    cout << ans << endl;
}
