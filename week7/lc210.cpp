class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // can try dfs later
        vector<int> ans, indeg(numCourses, 0);
        vector<vector<int>> g(numCourses, vector<int>());
        for(auto pre:prerequisites){
            indeg[pre[0]]++;
            g[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int c = q.front();
            q.pop();
            ans.push_back(c);
            for(int i = 0; i < g[c].size(); i++){
                if((--indeg[g[c][i]]) == 0){
                    q.push(g[c][i]);
                }
            }
        }
        if(ans.size() == numCourses)
            return ans;
        else
            return {};
    }
};