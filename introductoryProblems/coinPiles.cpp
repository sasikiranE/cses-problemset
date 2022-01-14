#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

void testCase() {
    ll a, b;
    cin >> a >> b;
    cout << ((a + b) % 3 == 0 and 2 * a >= b and 2 * b >= a ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}