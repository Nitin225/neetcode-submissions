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
    bool helper(TreeNode* root, vector<TreeNode*> &ans, TreeNode* x){
        if(root == NULL)
            return false;

        ans.push_back(root);

        if(root == x)
            return true;

        if (helper(root->left, ans, x) ||
            helper(root->right, ans, x))
            return true;

        ans.pop_back();
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;

        helper(root, v1, p);
        helper(root, v2, q);

        TreeNode* lca = NULL;
        for (int i = 0; i < min(v1.size(), v2.size()); i++) {
            if (v1[i] == v2[i]) lca = v1[i];
            // else break;
        }
        return lca;



    }
};
