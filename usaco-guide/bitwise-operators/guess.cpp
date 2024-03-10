#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
	cout << "and " << a << ' ' << b << endl;
	int c, d;
    cin >> c;
    cout << "or " << a << ' ' << b << endl;
	cin >> d;
    return c + d;
}

int main() {
    int n, k; cin >> n >> k;
    int arr[n+1]; 
    int ab = ask(1, 2), ac = ask(1, 3), bc = ask(2, 3);
    int res = (ab + ac + bc)/2;
    arr[1] = res - ab, arr[2] = res - ac, arr[3] = res - bc;
    for(int i = 4; i <= n; i++){
        arr[i] = ask(1, i) - arr[1];
    }
    sort(arr+1, arr+n+1);
    cout << "finish " << arr[k] << endl;
}