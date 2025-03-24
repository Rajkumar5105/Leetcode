class Solution {
public:
    
    bool dfs(const vector<vector<int>>& adj, vector<int>& vis, int i , int& nh, int &count){
        vis[i] = 1;
        for(auto j : adj[i]){
            if(nh!=adj[j].size()){
                return false;
            }
            if(vis[j] == 0){
                count++;
                bool tp = dfs(adj, vis, j, nh ,count);
                if(tp==false){
                    return tp;
                }
            }
        }

        if(nh!=count){
            return false;
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                int sz = adj[i].size();
                int count = 0;
                if(dfs(adj, vis, i, sz , count)==true){
                    ans++;
                }
            }
        }

        return ans;
    }
};