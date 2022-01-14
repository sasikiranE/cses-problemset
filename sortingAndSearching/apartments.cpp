#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	for (auto &e : a) {
		cin >> e;
	}
	for (auto &e : b) {
		cin >> e;
	}
	// Using two pointers.
	sort(all(a));
	sort(all(b));
	int cnt = 0;
	int i = 0, j = 0;
	while (i < n and j < m) {
		if (a[i] - k > b[j]) {
			j++;
		}
		else if (a[i] + k < b[j]) {
			i++;
		}
		else {
			cnt++;
			i++;
			j++;
		}
	}
	cout << cnt << "\n";
	return 0;
}