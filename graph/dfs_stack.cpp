#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Vertex
{
public:
    int edge_count;
    vector<int> edges;
};

void dfs_stack(vector<Vertex>& graph, int current, vector<bool>& visited);

int main()
{
    int n;
    cin >> n;

    vector<Vertex> adj_list(n);
    for (int i = 0; i < n; ++i) {
        int index;
        cin >> index;

        cin >> adj_list[i].edge_count;

        adj_list[i].edges.resize(adj_list[i].edge_count);
        for (int j = 0; j < adj_list[i].edge_count; ++j) {
            int tmp;
            cin >> tmp;
            adj_list[i].edges[j] = tmp - 1;
        }
    }

    vector<bool> visited(n, false);
    dfs_stack(adj_list, 0, visited);
}

void dfs_stack(vector<Vertex>& graph, int current, vector<bool>& visited)
{
    stack<int> s;

    visited[current] = true;
    s.push(current);

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << "[INFO] vertex #" << current << '\n';

        for (int i = graph[current].edge_count - 1; i >= 0; --i) {
            int child = graph[current].edges[i];
            if (visited[child] == false) {
                visited[child] = true;
                s.push(child);
            }
        }
    }
}

