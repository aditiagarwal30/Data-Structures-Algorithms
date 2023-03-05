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
    bool compare(TreeNode* root, TreeNode *subRoot){
        if(root==NULL and subRoot==NULL) return true;
        if(root==NULL or subRoot==NULL) return false;

        if(root->val!= subRoot->val) return false;

        return compare(root->left, subRoot->left) && compare(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root-> val== subRoot->val){
            bool ans= compare(root, subRoot);
            if(ans) return ans;
        }

        bool l=isSubtree(root->left, subRoot);
        bool r=isSubtree(root->right, subRoot);
        return l||r;
    }
};