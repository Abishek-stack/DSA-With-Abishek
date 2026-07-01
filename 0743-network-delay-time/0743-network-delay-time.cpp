class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<pair<int, int>> adj[n + 1];

        // Create adjacency list
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if (d > dist[node])
                continue;

            // Traverse all neighbours
            for (int i = 0; i < adj[node].size(); i++) {

                int adjNode = adj[node][i].first;
                int weight = adj[node][i].second;

                if (dist[node] + weight < dist[adjNode]) {

                    dist[adjNode] = dist[node] + weight;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};