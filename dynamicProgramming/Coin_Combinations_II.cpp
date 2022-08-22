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
    ll n, x;
    cin >> n >> x;
    vll coins(n);
    read(coins);
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = 1; i <= x; i++) {
            if (i < coin) continue;
            dp[i] = (dp[i] + dp[i - coin]) % Mod;
        }
    }
    cout << dp[x] << "\n";
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