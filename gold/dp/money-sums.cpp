#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int MAX_SUM = 1e5;

bool dp[MAX_N + 1][MAX_SUM + 1];

int main() {
    freopen("text2.txt", "r", stdin);
	int n;
	cin >> n;

	vector<int> coins_values(n);
	for (int i = 0; i < n; i++) { cin >> coins_values[i]; }

	dp[0][0] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= MAX_SUM; j++) {
			dp[i][j] = dp[i - 1][j];
			int prev_sum = j - coins_values[i - 1];
			if (prev_sum >= 0 && dp[i - 1][prev_sum]) {
				dp[i][j] = true;
			}
		}
	}

	vector<int> possible;
	for (int sum = 1; sum <= MAX_SUM; sum++) {
		if (dp[n][sum]) { possible.push_back(sum); }
	}

	cout << (int)(possible.size()) << endl;

	// for (int sum : possible) { cout << sum << " "; }
	// cout << endl;
}