class Solution {
public:
    void dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited,
             int &vertices, int &edges) {

        visited[curr] = true;
        vertices++;
        edges += graph[curr].size();

        for (int next : graph[curr]) {
            if (!visited[next]) {
                dfs(next, graph, visited, vertices, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        // Build graph
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        for (int vertex = 0; vertex < n; vertex++) {

            if (visited[vertex]) continue;

            int vertices = 0;
            int edgeCount = 0;

            dfs(vertex, graph, visited, vertices, edgeCount);

            if (edgeCount == vertices * (vertices - 1))
                completeCount++;
        }

        return completeCount;
    }
};