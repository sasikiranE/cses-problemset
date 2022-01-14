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
    vi v(n - 1);
    for (auto &e : v) cin >> e;
    ll a = (n * 1LL * (n + 1)) / 2;
    ll b = accumulate(all(v), 0LL);
    cout << a - b << "\n";
    return 0;
}