#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pi;
#define all(_a) _a.begin(), _a.end()
#define read(_a) for (auto &e : _a) cin >> e;
#define print(_a) for (auto &e : _a) { cout << e << " "; } cout << "\n";
const int Mod = 1e9 + 7;

void testCase() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vll> dp(n, vll(n, 0));
    if (grid[0][0] == '*') {
        cout << 0 << "\n";
        return;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 and j == 0) continue;
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if (i - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % Mod;
            if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % Mod;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}