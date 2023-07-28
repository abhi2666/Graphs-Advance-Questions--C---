/*
Right view of binary Tree using reverse preorder
--> we just have to pick the first element in every level from the right side.
*/

class Solution {
public:
    void generateRightView(int level, vector<int>&ans, TreeNode* root)
    {
        if(root == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        // right root left
        generateRightView(level+1, ans, root->right);
        generateRightView(level+1, ans, root->left);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        generateRightView(0, ans, root);
        return ans;
    }
};