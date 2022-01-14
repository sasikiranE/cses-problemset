#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

long long binExpMod(long long a, long long b, long long Mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << binExpMod(2, n, Mod) << "\n";
    return 0;
}