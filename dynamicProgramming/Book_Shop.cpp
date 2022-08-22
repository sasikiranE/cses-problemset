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
    int n, amount;
    cin >> n >> amount;
    vi prices(n), pages(n);
    read(prices);
    read(pages);
    vector<vi> dp(n + 1, vi(amount + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= amount; j++) dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (prices[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], pages[i - 1] + dp[i - 1][j - prices[i - 1]]);
        }
    }
    cout << dp[n][amount] << "\n";
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