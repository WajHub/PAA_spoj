#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <stack>

using namespace std;

vector<int> dfs(const unordered_map<int, vector<int> >& graph, int start) {
    vector<int> result;
    unordered_map<int, bool> visited;
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;
            result.push_back(vertex);

            for (int neighbor : graph.at(vertex)) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    return result;
}

vector<int> bfs(const unordered_map<int, vector<int> >& graph, int start) {
    vector<int> result;
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;
            result.push_back(vertex);

            for (int neighbor : graph.at(vertex)) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        unordered_map<int, vector<int> > graph;

        for (int j = 0; j < n; ++j) {
            int vertex;
            cin >> vertex;
            graph[vertex];

            string line;
            getline(cin, line);
            istringstream iss(line);

            int neighbor;
            while (iss >> neighbor) {
                graph[vertex].push_back(neighbor);
            }
        }

        int v, query;
        while (true) {
            cin >> v >> query;
            if (v == 0 && query == 0) {
                break;
            }

            vector<int> result;
            if (query == 0) {
                result = dfs(graph, v);
            } else {
                result = bfs(graph, v);
            }

            cout << "graph " << i + 1 << endl;
            for (int k = 0; k < result.size(); ++k) {
                cout << result[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
