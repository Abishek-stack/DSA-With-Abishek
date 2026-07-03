class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            indegree[v]++;
            maxCost = max(maxCost, w);
        }

        // Topological Sort
        queue<int> q;
        vector<int> topo;
        vector<int> indeg = indegree;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &it : adj[u]) {
                int v = it.first;
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) {
            const long long INF = 1e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF)
                    continue;

                // Intermediate offline node cannot be used
                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &it : adj[u]) {
                    int v = it.first;
                    int w = it.second;

                    if (w < limit)
                        continue;

                    if (v != 0 && v != n - 1 && !online[v])
                        continue;

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int low = 0;
        int high = maxCost;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};