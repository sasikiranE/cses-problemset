#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

void towerOfHanoi(int n, int src, int aux, int des) {
    if (n <= 0) return;
    // move (n - 1) discs for src to aux using des.
    towerOfHanoi(n - 1, src, des, aux);
    // move the last disc from src to des.
    cout << src << " " << des << "\n";
    // move (n - 1) discs from aux to des using src.
    towerOfHanoi(n - 1, aux, src, des);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}