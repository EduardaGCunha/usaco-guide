#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<tuple<int, string, int>> v;
    while(n--){
        int a, b;
        string s; cin >> a >> s >> b;
        v.push_back({a, s, b});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        string cow = get<1>(v[i]);
        cout << cow << endl;
    }

    //val, cow
    //0 mildred, 1 bessie 2 elsie
    int arr[4] = {7, 7, 7, 0};
    int w = 3, cnt = 0;
    for(int i = 0; i < n; i++){
        string cow = get<1>(v[i]);
        cout << cow << endl;
        int sum = get<2> (v[i]);
        if(cow == "Mildred"){
            if(w == 3 && sum + arr[0] > arr[0]){
               w = 0; 
               cnt++;
            }else if(w != 0 && arr[w] < sum + arr[0]){
                w = 0;
                cnt++;
            }
            arr[0] += sum;
        }else if(cow == "Bessie"){
            if(w == 3 && sum + arr[1] > arr[1]){
               w = 1; 
               cnt++;
            }else if(w != 1 && arr[w] < sum + arr[1]){
                w = 1;
                cnt++;
            }
            arr[1] += sum;
        }else{
            if(w == 3 && sum + arr[2] > arr[2]){
               w = 2; 
               cnt++;
            }else if(w != 1 && arr[w] < sum + arr[2]){
                w = 2;
                cnt++;
            }
            arr[2] += sum;
        }
    }

    for(auto u : arr) cout << u << endl;
    cout << cnt << endl;

}