#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vi v(n);
    for (auto &e : v) cin >> e;
    ll ans = 0;
    ll maxi = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < maxi) {
            ans += (maxi - v[i]);
        }
        else maxi = v[i];
    }
    cout << ans << "\n";
    return 0;
}