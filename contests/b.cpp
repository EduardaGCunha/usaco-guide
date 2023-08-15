#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<string> results(t);
    for(int j = 0; j < t; j++){
        int n;
        cin >> n;
        string result = "YES";
        vector<int> arr(n);
        vector<int> arr2(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        arr2 = arr;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            if((arr2[i] % 2) != (arr[i]%2)){
                result = "NO";
                break;
            }
        }
        results.push_back(result);
    }

    for(auto a : results){
        cout << a << endl;
    }
}