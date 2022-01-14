#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, x;
	cin >> n >> x;
	vi v(n);
	for (auto &e : v) {
		cin >> e;
	}
	sort(all(v));
	// Using two pointers.
	int i = 0, j = n - 1;
	int cnt = 0;
	while (i <= j) {
		if (v[i] + v[j] <= x) {
			cnt++;
			i++;
			j--;
		}
		else {
			cnt++;
			j--;
		}
	}
	cout << cnt << "\n";
	return 0;
}