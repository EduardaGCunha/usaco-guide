#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n+1), cnt(30, 0);
        string ans = "";
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            for(int j = 0; j < 26; j++){
                if(arr[i] == cnt[j]){
                    cnt[j]++;
                    ans+= ('a'+j);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
} 