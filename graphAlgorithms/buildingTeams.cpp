#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vi> graph(n + 1);
    vi color(n + 1, -1);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
    	if (color[i] != -1) continue;
    	color[i] = 0;
    	queue<int> q;
    	q.push(i);
    	while (!q.empty()) {
    		int node = q.front();
    		q.pop();
    		for (auto &nei : graph[node]) {
    			if (color[nei] == -1) {
    				color[nei] = color[node] ^ 1;
    				q.push(nei);
    			}
    			else if (color[nei] == color[node]) {
    				cout << "IMPOSSIBLE" << "\n";
    				return 0;
    			}
    		}
    	}
    }
    for (int i = 1; i <= n; i++) {
    	cout << color[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}