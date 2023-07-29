/*
          1
       /     \
     2        3
   /  \     /  \
  4    5   6    7
   \
     8   

    output --> {1, 2, 4, 8}
*/

void preOrder(int level, vector<int>&ans, Node*root)
{
    if(root == NULL) return;

    if(ans.size() == level)
    {
        ans.push_back(root->data);
    }
    preOrder(level+1, ans, root->left);
    preOrder(level+1, ans, root->right);
}

vector<int> leftView(Node *root)
{
   vector<int>ans;
   preOrder(0, ans, root);
   return ans;
}