#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int tempo[MAXN];

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        for(int j = arr[i].first; j < arr[i].second; j++){
            tempo[j]++;
        }
    }

    sort(arr, arr+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < MAXN; j++){
            if(j >= arr[i].first && j < arr[i].second){
                tempo[j]--;
                sum += (tempo[j] > 0);
                tempo[j]++;
            }else sum += (tempo[j] > 0);
        }
        ans = max(sum, ans);
    }

    cout << ans << endl;

}