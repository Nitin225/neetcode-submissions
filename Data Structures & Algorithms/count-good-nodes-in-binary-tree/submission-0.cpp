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
private:
    int helper(TreeNode* root, int maxi){
        if(root == NULL)
            return 0;

        if(root->val < maxi)
            return helper(root->left, maxi) + helper(root->right, maxi);

        else{
            maxi = root->val;
            return 1 + helper(root->left, maxi) + helper(root->right, maxi);
        }

    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
