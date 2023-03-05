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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        int sum=0;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            TreeNode *node= it.first;
            int pos= it.second;

            if(node->left==NULL and node->right==NULL and pos==1) sum+= node->val;
            if(node->left) q.push({node->left, 1});
            if(node->right) q.push({node->right,2});
        }
        return sum;
    }
};