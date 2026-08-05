class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& suspicious) {
        suspicious[node] = true;

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!suspicious[next]) {
                dfs(next, graph, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            graph[u].push_back(v);
        }

        vector<bool> suspicious(n, false);

        dfs(k, graph, suspicious);

        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int j = 0; j < n; j++) {
                    ans.push_back(j);
                }
                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};