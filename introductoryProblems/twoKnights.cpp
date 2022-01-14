#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

// sol => total possible - (no of ways they attack).

// sol => (n * n) C 2 - 4 * (n - 1) * (n - 2).

ll nC2(ll n) {
	return (n * (n - 1)) / 2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n;
	cin >> n;
	for (ll k = 1; k <= n; k++) {
		cout << nC2(k * k) - (4 * (k - 1) * (k - 2)) << "\n";
	}
	return 0;
}