class Solution {
public:
    
    void dfs(int node , vector<vector<int>>& graph , vector<bool>& visited){
        visited[node] = true;
        for(int i = 0 ; i < graph[node].size();i++){
            int neighbour = graph[node][i];
            if(!visited[neighbour]){
                dfs(neighbour,graph,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> graph(n);
      for(int i = 0; i<edges.size();i++){
       int u = edges[i][0];
       int v = edges[i][1];
       graph[u].push_back(v);
       graph[v].push_back(u);
      }
       vector<bool> visited(n,false);
       dfs(source ,graph , visited);

       return visited[destination];
      
    }
};