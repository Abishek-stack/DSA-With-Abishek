class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        // Store {value, original index}
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        // Sort by value
        sort(arr.begin(), arr.end());

        // value = sorted values
        // pos = position of original index in sorted array
        vector<int> value(n), pos(n);
        for(int i = 0; i < n; i++) {
            value[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // Find connected components
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;

        for(int i = 1; i < n; i++) {
            if(value[i] - value[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        // nxt[i] = farthest index reachable in one jump
        vector<int> nxt(n);
        int r = 0;

        for(int l = 0; l < n; l++) {
            while(r + 1 < n && value[r + 1] - value[l] <= maxDiff)
                r++;
            nxt[l] = r;
        }

        // Binary lifting table
        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if(u > v)
                swap(u, v);

            int cur = u;
            int jumps = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};