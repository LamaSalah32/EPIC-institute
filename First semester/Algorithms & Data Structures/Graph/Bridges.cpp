#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define cin(v) for (auto& i : v) cin >> i
#define cout(v) for (auto& i : v) cout << i << ' '; cout << "\n"

using namespace std;

int n, m;
vector<vector<int> > adj;
vector <bool> vis;
set <pair<int, int>> Bridges;
vector<int> h, dp;


void dfs(int v, int p, int depth) {
    vis[v] = 1;
    dp[v] = h[v] = depth;

    for (auto u : adj[v]) {
        if (u != p) {
            if (vis[u]) {
                dp[v] = min(dp[v], h[u]);
            }
            else {
                dfs(u, v, depth + 1);
                dp[v] = min(dp[v], dp[u]);

                if (h[v] < dp[u]) {
                    Bridges.insert({v, u});
                }
            }
        }
    }
}


void init(){
    adj = vector<vector<int>> (n + 5);
    vis = vector <bool> (n + 5);
    h = vector <int> (n + 5);
    dp = vector <int> (n + 5);
    Bridges.clear();
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

    cout << Bridges.size() << "\n";
    for (auto i : Bridges) {
        cout << i.first << ' ' << i.second << "\n";
    }
    
    return 0;
}