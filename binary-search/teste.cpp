#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        pq.push(-a);
    }

    for(int i = 0; i < 3; i++){
        cout << pq.top() << endl;
        int a = pq.top(); 
    }
}