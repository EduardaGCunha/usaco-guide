#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

	int n;
	cin >> n;
	int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    int res =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(x[i] != x[k]) continue;
                if(y[i] != y[j]) continue;
                int area = abs(y[k] - y[i])*abs(x[j]-x[i]);
                res = max(area, res);
            }
        }
    }
	cout << res << endl;
}