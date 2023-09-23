#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> hello = {2, 4, 6, 8, 10};

    for(int i =0; i < hello.size(); i++){
        hello[i] /= 2;
    }

    for(int i =0; i < hello.size(); i++){
        cout << hello[i] << endl;
    }
}