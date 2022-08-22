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

const long long INF = 1e18;

void testCase() {
    ll n, x;
    cin >> n >> x;
    vll coins(n);
    read(coins);
    vll dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int coin : coins) {
            if (i < coin) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
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