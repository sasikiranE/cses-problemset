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
    vi coins(n);
    read(coins);
    ll sum = accumulate(all(coins), 0LL);
    
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    
    function<int(int, int)> isPossible = [&] (int n, int sum) {
        if (sum == 0) return 1;
        if (n == 0) return 0;
        if (dp[n][sum] != -1) return dp[n][sum];
        if (coins[n - 1] > sum) return dp[n][sum] = isPossible(n - 1, sum);
        return dp[n][sum] = (int) (isPossible(n - 1, sum) == 1 or isPossible(n - 1, sum - coins[n - 1]) == 1);
    };

    int cnt = 0;
    for (int i = 1; i <= sum; i++) {
        cnt += (isPossible(n, i) == 1);
    }
    cout << cnt << "\n";
    for (int i = 1; i <= sum; i++) {
        if (isPossible(n, i) == 1) cout << i << " ";
    }
    cout << "\n";
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