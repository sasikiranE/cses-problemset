#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	vector<vector<ll>> preSum(n + 1, vector<ll>(n + 1, 0LL));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
			if (grid[i][j] == '*') preSum[i][j] += 1;
		}
	}
	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << preSum[c][d] - preSum[a - 1][d] - preSum[c][b - 1] + preSum[a - 1][b - 1] << "\n";
	}
	return 0;
}