class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if(left == NULL) return 0;
        if(right == NULL) return 0;

        return 1 + max(left, right);

    }
};