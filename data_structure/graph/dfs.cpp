#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
public:
    int edge_count;
    vector<int> edges;
};

void dfs(vector<Vertex>& graph, int current, vector<bool>& visited);

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
    dfs(adj_list, 0, visited);
}

void dfs(vector<Vertex>& graph, int current, vector<bool>& visited)
{
    cout << "[INFO] vertex #" << current << '\n';
    visited[current] = true;

    for (int i = 0; i < graph[current].edge_count; ++i) {
        int next_vertex = graph[current].edges[i];
        if (visited[next_vertex] == false)
            dfs(graph, next_vertex, visited);
    }
}

