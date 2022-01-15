#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;
const int inf = 1e9;

vi dx = {0, 0, -1, 1};
vi dy = { -1, 1, 0, 0};
vector<char> dir = {'L', 'R', 'U', 'D'};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));

	// using multisource BFS. (sources -> monsters)

	pi A;
	vector<vi> monsterTime(n, vi(m, inf));
	vector<vi> personTime(n, vi(m, inf));
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	queue<pi> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') {
				A = make_pair(i, j);
			}
			else if (grid[i][j] == 'M') {
				vis[i][j] = true;
				monsterTime[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	personTime[A.first][A.second] = 0;

	auto inside = [&] (int x, int y) {
		return x >= 0 and y >= 0 and x < n and y < m;
	};

	while (!q.empty()) {
		pi node = q.front();
		q.pop();
		int x = node.first;
		int y  = node.second;
		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			if (inside(i, j) and !vis[i][j] and grid[i][j] == '.') {
				monsterTime[i][j] = monsterTime[x][y] + 1;
				vis[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}

	// BFS with person as source.

	q.push(A);
	pi exit;
	bool ok = false;

	while (!q.empty()) {
		pi node = q.front();
		q.pop();
		int x = node.first;
		int y = node.second;
		if (x == 0 or y == 0 or x == n - 1 or y == m - 1) {
			exit = make_pair(x, y);
			ok = true;
			break;
		}
		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			if (inside(i, j) and grid[i][j] == '.') {
				grid[i][j] = dir[k];
				personTime[i][j] = personTime[x][y] + 1;
				if (personTime[i][j] >= monsterTime[i][j]) continue;
				q.push(make_pair(i, j));
			}
		}
	}

	if (ok) {
		vector<char> path;
		int i = exit.first, j = exit.second;
		while (grid[i][j] != 'A') {
			path.push_back(grid[i][j]);
			if (grid[i][j] == 'L') {
				j++;
			}
			else if (grid[i][j] == 'R') {
				j--;
			}
			else if (grid[i][j] == 'U') {
				i++;
			}
			else i--;
		}
		reverse(all(path));
		cout << "YES" << "\n";
		cout << path.size() << "\n";
		for (auto &c : path) {
			cout << c;
		}
		cout << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	return 0;
}