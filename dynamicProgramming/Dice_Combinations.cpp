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
    vll dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 6; k++) {
            if (i < k) continue;
            dp[i] = (dp[i] + dp[i - k]) % Mod;
        }
    }
    cout << dp[n] << "\n";
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