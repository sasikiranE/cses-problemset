#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

int n, m;
vector<vi> graph;
vector<bool> vis;
vi p;
int cycle_start, cycle_end;

void dfs(int node, int par) {
	vis[node] = true;
	for (auto &nei : graph[node]) {
		if (nei == par) continue;
		if (vis[nei]) {
			cycle_start = node;
			cycle_end = nei;
			return;
		}
		p[nei] = node;
		dfs(nei, node);
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    graph.assign(n + 1, vi());
    p.assign(n + 1, -1);
    vis.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    cycle_start = -1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, p[i]);
        if (cycle_start != -1) break;
    }
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
    	vi cycle;
    	cycle.push_back(cycle_start);
    	for (int i = cycle_end; i != cycle_start; i = p[i]) {
    		cycle.push_back(i);
    	}
    	cycle.push_back(cycle_start);
    	reverse(all(cycle));
    	cout << cycle.size() << "\n";
    	for (auto &e : cycle) {
    		cout << e <<  " ";
    	}
    	cout << "\n";
    }
    return 0;
}