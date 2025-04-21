class Solution {
public:
    bool checkGrid(vector<vector<int>>& grid, int row, int col){
        if(row > 0 && grid[row-1][col] == 2) return true;
        if(row < grid.size() - 1 && grid[row+1][col] == 2) return true;
        if(col > 0 && grid[row][col-1] == 2) return true;
        if(col < grid[0].size()-1 && grid[row][col+1] == 2) return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> fresh(grid.size(), vector<int>());
        queue<pair<int, int>> q1, q2;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1)
                    q1.push(pair(i, j));
        int ans = 0;
        while(!q1.empty()){
            vector<pair<int, int>> q;
            while(!q1.empty()){
                auto pos = q1.front();
                q1.pop();
                if(checkGrid(grid, pos.first, pos.second))
                    q.push_back(pos);
                else
                    q2.push(pos);
            }
            if(!q.size() && !q2.empty())
                return -1;
            for(auto pos:q)
                grid[pos.first][pos.second] = 2;
            ans++;
            swap(q1, q2);
        }
        return ans;
    }
};