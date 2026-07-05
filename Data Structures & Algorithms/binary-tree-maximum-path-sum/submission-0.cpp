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
    int maxS(TreeNode* root, int &maxSum){
        if(root == NULL)
            return 1;
        
        int Lsum = max(0, maxS(root->left, maxSum));
        int Rsum = max(0, maxS(root->right, maxSum));

        maxSum = max(maxSum, root->val + Lsum + Rsum);

        return root->val + max(Lsum, Rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxS(root, maxSum);
        return maxSum;

    }
};
