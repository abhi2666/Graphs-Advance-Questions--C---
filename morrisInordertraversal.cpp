/*
Just inorder traversal with optimised space
we will create threads to reach the previous node
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorderTraversal;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                inorderTraversal.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                // if there is a left then go single left and then go to total right
                TreeNode *temp = curr->left;
                while (temp->right && temp->right != curr)
                {
                    temp = temp->right;
                }
                if (temp->right == NULL)
                {
                    // there is no node
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // if there is any connection already then remove it
                    temp->right = NULL;
                    inorderTraversal.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        return inorderTraversal;
    }
};