/*
Check if two trees are identical
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // we can traverse both the trees ans check if there values 
        // are equal
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false; // for scenario where there is 
        // a node missing in one of the tree

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right ,q->right);
    }
};