int getPathSum(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;

    int leftSum = max(0, getPathSum(root->left, sum));
    int rightSum = max(0, getPathSum(root->right, sum));
    sum = max(sum, (root->val + leftSum + rightSum)); 
    return max(leftSum, rightSum) + root->val;
}

int Solution::maxPathSum(TreeNode *A)
{
    int sum = INT_MIN;
    maxPath(A, sum);
    return sum;
}