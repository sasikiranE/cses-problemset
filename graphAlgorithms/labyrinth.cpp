#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

vi dx = {0, 0, -1, 1};
vi dy = {-1, 1, 0, 0};
vector<char> dir = {'L', 'R', 'U', 'D'};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    pi A, B;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> grid[i][j];
    		if (grid[i][j] == 'B') {
    			B = make_pair(i, j);
    			grid[i][j] = '.';
    		}
    		else if (grid[i][j] == 'A') A = make_pair(i, j);
    	}
    }

    auto inside = [&] (int x, int y) {
    	return x >= 0 and y >= 0 and x < n and y < m;
    };

    queue<pi> q;
    q.push(A);
    while (!q.empty()) {
    	int i = q.front().first;
    	int j = q.front().second;
    	q.pop();
    	for (int k = 0; k < 4; k++) {
    		int x = i + dx[k];
    		int y = j + dy[k];
    		if (inside(x, y) and grid[x][y] == '.') {
    			grid[x][y] = dir[k];
    			q.push(make_pair(x, y));
    		}
    	}
    }
    if (grid[B.first][B.second] == '.') {
    	cout << "NO" << "\n";
    }
    else {
    	vector<char> path;
    	int i = B.first, j = B.second;
    	while (i != A.first or j != A.second) {
    		path.push_back(grid[i][j]);
    		if (grid[i][j] == 'L') j++;
    		else if (grid[i][j] == 'R') j--;
    		else if (grid[i][j] == 'U') i++;
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
    return 0;
}