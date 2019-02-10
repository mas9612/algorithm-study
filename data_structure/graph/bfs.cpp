#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Vertex
{
public:
    int edge_count;
    vector<int> edges;
};

void bfs(vector<Vertex>& graph, int start, vector<bool>& enqueued);

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

    vector<bool> enqueued(n, false);
    bfs(adj_list, 0, enqueued);
}

void bfs(vector<Vertex>& graph, int start, vector<bool>& enqueued)
{
    queue<int> q;
    int current;

    enqueued[start] = true;
    q.push(start);

    while (!q.empty()) {
        current = q.front();
        q.pop();
        cout << "[INFO] vertex #" << current << '\n';

        for (int i = 0; i < graph[current].edge_count; ++i) {
            int child = graph[current].edges[i];
            if (enqueued[child] == false) {
                enqueued[child] = true;
                q.push(child);
            }
        }
    }
}

