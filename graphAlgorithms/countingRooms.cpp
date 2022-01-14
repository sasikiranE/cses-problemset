#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

int n, m;
vector<vector<char>> grid;

bool inside(int x, int y) {
	return x >= 0 and y >= 0 and x < n and y < m;
}

vi dx = {0, 0, -1, 1};
vi dy = {-1, 1, 0, 0};

void dfs(int i, int j) {
	grid[i][j] = '$';
	for (int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (inside(x, y) and grid[x][y] == '.') {
			dfs(x, y);
		}
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> grid[i][j];
    	}
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (grid[i][j] == '.') {
    			cnt++;
    			dfs(i, j);
    		}
    	}
    }
    cout << cnt << "\n";
    return 0;
}