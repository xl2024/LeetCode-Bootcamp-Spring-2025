/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> ans;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty()){
            int r = 0;
            while(!q1.empty()){
                TreeNode* t = q1.front();
                q1.pop();
                r = t->val;
                if(t->left != nullptr)
                    q2.push(t->left);
                if(t->right != nullptr)
                    q2.push(t->right);
            }
            ans.push_back(r);
            swap(q1, q2);
        }
        return ans;
    }
};