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

const int INF = 1e9;

void testCase() {
    int n;
    cin >> n;
    vi v(n);
    read(v);
    // dp[i] -> min_element at which lis of length i is found.
    vi dp(n + 1, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        // get rightmost value in dp with value < v[i]
        int len = upper_bound(all(dp), v[i]) - dp.begin();
        if (dp[len - 1] < v[i] and v[i] < dp[len]) {
            dp[len] = v[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != INF) ans = i;
    }
    cout << ans << "\n";
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