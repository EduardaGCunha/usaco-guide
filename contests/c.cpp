#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n, k; 
    cin >> n >> k;
    vector<int> color(n);
    for(int j = 0; j < n; j++){
        cin >> color[j];
    }

    int l = 0, r = 0, i = 0, j = n - 1;
    int k_left = k, k_right = k;

    if(color[0] == color[n - 1]){
        k_left /= 2;
        k_right = k - k_left;
    }

    for(int i = 0; i < n && l < k_left; i++){

    }
}

int main(){
    int t;
    cin >> t;
    vector<string> answers(t);
    for(int i = 0; i < t; i++){


    }
}