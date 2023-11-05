#include <bits/stdc++.h>

#define all(vec) vec.begin(), vec.end()
#define cin(v) for (auto& i : v) cin >> i
#define cout(v) for (auto& i : v) cout << i << ' '; cout << "\n"

using namespace std;


int n, m;
vector<vector<int>> graph, reverseGraph;
vector<int> vis;

void dfs(int node, vector <int>& topSort) {
    vis[node] = true;
    for (int i : graph[node]) {
        if (!vis[i]) {
            dfs(i, topSort);
        }
    }

    topSort.push_back(node);
}


void reverseDfs(int node, vector<int>& scc, int cnt) {
    vis[node] = true;
    scc[node] = cnt;
    for (int neighbor : reverseGraph[node]) {
        if (!vis[neighbor]) {
            reverseDfs(neighbor, scc, cnt);
        }
    }
}

void init(){
    graph = vector<vector<int>> (n + 5);
    reverseGraph = vector<vector<int>> (n + 5);
    vis = vector<int> (n + 5);
}

int main() {
    cin >> n >> m;
    init();

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    vector <int> topSort;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, topSort);
        }
    }

    int count_scc = 0;
    vector<int> scc(n + 5, -1);
    vis.assign(n + 5, 0);

    reverse(all(topSort));
    for(auto&node : topSort) {
        if (!vis[node]) {
            count_scc++;
            reverseDfs(node, scc, count_scc);
        }
    }

    cout << count_scc << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << scc[i] << " ";
    }


    return 0;
}