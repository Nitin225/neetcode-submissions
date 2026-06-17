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
    bool helper(TreeNode* root, int x){
        if(root == NULL)
            return false;

        if(root->val == x)
            return true;

        if (helper(root->left, x) ||
            helper(root->right, x))
            return true;

        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        if(root->val == p->val || root->val == q->val)
            return root;

        if(helper(root->left, p->val) && helper(root->right, q->val))
            return root;

        if(helper(root->right, p->val) && helper(root->left, q->val))
            return root;

        if(helper(root->left, p->val) || helper(root->left, q->val))
            return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);

    }
};
