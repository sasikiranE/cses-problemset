#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

void testCase() {
	ll x, y;
	cin >> x >> y;
	if (x >= y) {
		if (x % 2 == 0) {
			cout << (x * x) - y + 1;
		}
		else {
			cout << ((x - 1) * (x - 1)) + y;
		}
	}
	else {
		if (y % 2 == 0) {
			cout << ((y - 1) * (y - 1)) + x;
		}
		else {
			cout << (y * y) - x + 1;
		}
	}
	cout << "\n";
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