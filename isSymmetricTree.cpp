/*
Check if tree 
*/
class Solution {
public:
    bool checkSymmetry(TreeNode* rootLeft, TreeNode* rootRight){
        if(rootLeft->left == NULL && rootRight->right == NULL) return true;
        else if(rootLeft->left == NULL || rootRight->right == NULL) return false;
        if(rootLeft->val == rootRight->val) return false;
        return checkSymmetry(rootLeft->left, rootRight->right) && checkSymmetry(rootLeft->right, rootRight->left);

    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL || root->left == NULL || root->right == NULL){
            reutrn false;
        }
        return checkSymmetry(root->left, root->right);
    }
};