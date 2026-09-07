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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q1;

          if (root == nullptr)
            return ans;

        q1.push(root);
        while(!q1.empty()){
           int size = q1.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q1.front();
                q1.pop();

                level.push_back(node->val);

                if (node->left != nullptr)
                    q1.push(node->left);

                if (node->right != nullptr)
                    q1.push(node->right);
        }
           
        ans.push_back(level);
        }
        return ans;
    }
};