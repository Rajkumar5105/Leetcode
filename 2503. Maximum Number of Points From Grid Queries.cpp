class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        int m = grid.size(), n = grid[0].size();
        
        vector<pair<int, int>> iq;
        for (int i = 0; i < q.size(); i++) {
            iq.push_back({q[i], i});
        }

        sort(iq.begin(), iq.end());
        
        vector<int> ans(q.size(), 0);
        set<pair<int,int>> vis;
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});
        vis.insert({0, 0});
        
        int count = 0;
        
        for (auto& [a, b] : iq) {
            while (!pq.empty() && pq.top().first < a) {
                auto [currentVal, cell] = pq.top();
                pq.pop();
                
                count++;
                vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
                
                for (auto& [dx, dy] : directions) {
                    int nx = cell.first + dx;
                    int ny = cell.second + dy;
                    
                    if (isValid(nx, ny, m, n) && 
                        vis.find({nx, ny}) == vis.end()) {
                        vis.insert({nx, ny});
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
            
            ans[b] = count;
        }
        
        return ans;
    }
};

