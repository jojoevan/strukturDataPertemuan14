#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SocialGraph {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<string> users;

public:
    SocialGraph(int v, vector<string> names) {
        V = v;
        adj.resize(V);
        visited.resize(V, false);
        users = names;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void showFriends(int v) {
        cout << "Teman " << users[v] << " : ";
        for (int u : adj[v]) cout << users[u] << " ";
        cout << endl;
    }

    void DFS(int v) {
        visited[v] = true;
        cout << users[v] << " ";
        for (int u : adj[v])
            if (!visited[u]) DFS(u);
    }

    void BFS(int start) {
        vector<bool> vis(V, false);
        vector<int> level(V, -1);
        queue<int> q;
        vis[start] = true;
        level[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << users[v] << " (tingkat " << level[v] << ")" << endl;
            for (int u : adj[v])
                if (!vis[u]) {
                    vis[u] = true;
                    level[u] = level[v] + 1;
                    q.push(u);
                }
        }
    }
};

int main() {
    vector<string> users = {"Andi", "Budi", "Citra", "Dina", "Eko"};
    SocialGraph g(5, users);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "===== DATA PERTEMANAN =====" << endl;
    for (int i = 0; i < 5; i++) g.showFriends(i);

    cout << "\nDFS (semua yang terhubung dari Andi): ";
    g.DFS(0);

    cout << "\n\nBFS (tingkat pertemanan dari Andi):" << endl;
    g.BFS(0);
    return 0;
}
