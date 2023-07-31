/*
Find the path from root to all nodes and store them as string in a vector<string>
*/

// class Solution {
// public:

//     void getPathsToLeaf(TreeNode* root, string s, vector<string>&finalVect)
//     {
//         if(root == NULL)
//         {
//             finalVect.push_back(s);
//             return;
//         }

//         s += root->val; don't add integer directly to the string 
//         s += "->";
//         getPathsToLeaf(root->left, s, finalVect);
//         s += root->val;
//         s += "->";
//         getPathsToLeaf(root->right, s, finalVect);
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         string s;
//         vector<string>finalVect;
//         getPathsToLeaf(root, s, finalVect);
//     }
// };

class Solution {
public:
    void getPathsToLeaf(TreeNode* root, string s, vector<string>& finalVect) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            // If it is a leaf node, add the value to the current path and push it to he final vector.
            s += to_string(root->val);
            finalVect.push_back(s);
            return;
        }
        s += to_string(root->val) + "->";
        getPathsToLeaf(root->left, s, finalVect);
        getPathsToLeaf(root->right, s, finalVect);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> finalVect;
        getPathsToLeaf(root, s, finalVect);
        return finalVect;
    }
};
