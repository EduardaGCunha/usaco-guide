#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int arr[n+1];
        set<int> p;
        arr[0] = INT_MIN;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            if(arr[i] < arr[i-1]){
                if((arr[i]&(arr[i]-1)) == 0)ans = max(__builtin_ctz(i)+1, ans);
                else p.insert(i);
                
            }
        }

        int t = 0;
        unordered_set<int> s;
        while(!p.empty()){
            for(auto i : p){
                arr[i] += (1<<t);
                if(arr[i] >= arr[i-1]){
                    s.insert(i);
                }
            }
            t++;
            for(auto i : s) p.erase(i);
        }
        cout << max(t, ans) << endl;
    }
}