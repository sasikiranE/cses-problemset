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
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (sum & 1) {
        cout << 0 << "\n";
        return;
    }
    ll target = sum / 2;
    // no of ways to get sum target.
    vector<vll> dp(n, vll(target + 1, -1));

    function<ll(ll, ll)> countWays = [&] (ll n, ll target) {
        if (target == 0) return 1LL;
        if (n == 0) return 0LL;
        if (dp[n][target] != -1) return dp[n][target];
        if (target < n) return dp[n][target] = countWays(n - 1, target) % Mod;
        return dp[n][target] = (countWays(n - 1, target) + countWays(n - 1, target - n)) % Mod;
    };

    cout << countWays(n - 1, target) << "\n";
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