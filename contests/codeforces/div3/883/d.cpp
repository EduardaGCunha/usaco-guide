#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10); cout.setf(ios::fixed);
    int t; cin >> t;
    while(t--){
        int n, b, h; cin >> n >> b >> h;
        vector<int> heights(n);
        for(int i = 0; i < n; i++){
            cin >> heights[i];
        }

        long double area = (long double) b*h / 2.0;
        long double total = area;
        for(int i = 0; i < n-1; i++){
            if(heights[i] + h <= heights[i+1]) total+= area;
            else{
                long double new_h = heights[i+1] - heights[i];
                long double k = (h - new_h)/h;
                long double a = k*b;
                long double new_area = ((a+b)*new_h)/2.0;
                total+= new_area;
            }
        }

        cout << total << endl;
    }
}