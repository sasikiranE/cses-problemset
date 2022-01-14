#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

ll ans = 0;
int n = 8;
vector<vector<char>> grid(n, vector<char>(n));
vector<bool> col(n), diag1(n), diag2(n);

void solve(int x) {
	if (x == n) {
		ans++;
		return;
	}
	for (int y = 0; y < n; y++) {
		if (col[y] or diag1[x + y] or diag2[y - x + n - 1] or grid[x][y] == '*') continue;
		col[y] = diag1[x + y] = diag2[y - x + n - 1] = true;
		solve(x + 1);
		col[y] = diag1[x + y] = diag2[y - x + n - 1] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}