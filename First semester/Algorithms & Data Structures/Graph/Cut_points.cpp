#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define cin(v) for (auto& i : v) cin >> i
#define cout(v) for (auto& i : v) cout << i << ' '; cout << "\n"

using namespace std;


int n, m;
vector<vector<int> > adj;
vector <bool> vis;
set <int> cut_points;
vector<int> h, dp;


void dfs(int v, int p, int depth) {
    vis[v] = 1;
    dp[v] = h[v] = depth;

    int children = 0;
    for (auto u : adj[v]) {
        if (u != p) {
            if (vis[u]) {
                dp[v] = min(dp[v], h[u]);
            }
            else {
                dfs(u, v, depth + 1);
                dp[v] = min(dp[v], dp[u]);

                if (h[v] <= dp[u] && p != -1) {
                    cut_points.insert(v);
                }

                children++;
            }
        }
    }

    if (p == -1 && children > 1) {
        cut_points.insert(v);
    }
}


void init(){
    adj = vector<vector<int>> (n + 5);
    vis = vector <bool> (n + 5);
    h = vector <int> (n + 5);
    dp = vector <int> (n + 5);
    cut_points.clear();
}


int main() {
    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1, 0);
        }
    }

    cout << cut_points.size() << "\n";
    cout(cut_points);

    return 0;
}