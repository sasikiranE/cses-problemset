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
    vll points(n);
    read(points);

    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    function<ll(int, int)> maxScore = [&] (int a, int b) {
        if (b - a == 0) return points[a];
        if (b - a == 1) return max(points[a], points[b]);
        if (dp[a][b] != -1) return dp[a][b];
        return dp[a][b] = max(points[a] + min(maxScore(a + 2, b), maxScore(a + 1, b - 1)),
        points[b] + min(maxScore(a + 1, b - 1), maxScore(a, b - 2)));
    };

    cout << maxScore(0, n - 1) << "\n";
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