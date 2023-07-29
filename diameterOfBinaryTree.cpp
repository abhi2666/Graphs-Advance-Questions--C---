class Solution
{
public:
    int diameter = 0;

    int getDiameter(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        // find left height and right height
        int leftHeight = diameterOfBinaryTree(root->left);
        int rightHeight = diameterOfBinaryTree(root->right);
        int val = leftHeight + rightHeight;
        diameter = max(diameter, val);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if(root == NULL) return diameter;
        int h = getDiameter(root);
        return diameter;
    }
};