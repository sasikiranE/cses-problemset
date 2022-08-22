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
    string a, b;
    cin >> a >> b;
    // transform a into b.
    // delete a character or replace a character or insert a character.
    int m = a.size(), n = b.size();
    vector<vi> dp(m + 1, vi(n + 1, -1));

    function<int(int, int)> solve = [&] (int m, int n) {
        if (m == 0) return n;
        if (n == 0) return m;
        if (dp[m][n] != -1) return dp[m][n];
        if (a[m - 1] == b[n - 1]) return dp[m][n] = solve(m - 1, n - 1);
        return dp[m][n] = 1 + min({solve(m - 1, n - 1), solve(m - 1, n), solve(m, n - 1)});
    };

    cout << solve(m, n) << "\n";
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