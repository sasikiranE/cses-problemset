#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

// using binary to gray code conversion

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		bitset<16> binary(i), gray(i);
		for (int k = n - 2 ; k >= 0; k--) {
			if (binary[k] == binary[k + 1]) gray.reset(k);
			else gray.set(k);
		}
		// printing gray code.
		for (int k = n - 1; k >= 0; k--) {
			cout << gray[k];
		}
		cout << "\n";
	}
	return 0;
}