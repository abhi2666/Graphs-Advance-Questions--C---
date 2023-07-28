/*
for each node we will check for the left value and right value. If any value 
matches with the p and q then we will return those else we will return 0.
If for any node, both the left and right value is not null then that node is the LCA.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q) return root;

        // go left and right
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // if for a node one side is giving NULL and other is giving a value..
        // then take the value
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) return left;
        else {
            // if both are not null means you have reached LCA
            return root;
        }
    }
};