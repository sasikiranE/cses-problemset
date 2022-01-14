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
	if (n == 1)
		cout << "NO" << "\n";
	else if (n % 4 == 0) {
		cout << "YES" << "\n";
		cout << n / 2 << "\n";
		int a = 1, b = n;
		int k = n / 4;
		while (k--) {
			cout << a++ << " " << b-- << " ";
		}
		cout << "\n";
		k = n / 4;
		cout << n / 2 << "\n";
		while (k--) {
			cout << a++ << " " << b-- << " ";
		}
		cout << "\n";
	}
	else if (n % 2 == 0 || (n / 2) % 2 == 0)
		cout << "NO" << "\n";
	else {
		cout << "YES" << "\n";
		int mid = n / 2 + 1;
		int count = 0;
		int a = 1, b = n;
		cout << n / 2 + 1 << "\n";
		while (true) {
			cout << a++ << " ";
			count++;
			if (count == n / 2) {
				cout << mid << "\n";
				break;
			}
			cout << b-- << " ";
			count++;
			if (count == n / 2) {
				cout << mid << "\n";
				break;
			}
		}
		cout << n / 2 << "\n";
		cout << b-- << " ";
		while (a != b) {
			cout << a++ << " " << b-- << " ";
		}
		cout << "\n";
	}
	return 0;
}