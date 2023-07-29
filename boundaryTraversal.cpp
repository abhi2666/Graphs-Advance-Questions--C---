/*
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9

	 output --> 1 2 4 8 9 6 7 3 

	 Approach --> we can divide the problem into various steps

	 i) Find the left side first and store it into a vector. keep going until you
	 see a leaf node
	 ii) now find all the leaf nodes using inorder traversal
	 iii) all the elements in the right in reverse order
	 iv) store all the elements into a vector and return it bary easy.
*/

class Solution {
public:

	void getLeftSide(vector<int>&result, Node*temp)
	{
		if(temp == NULL) return;

		if(isLeaf(temp)){
			result.push_back(temp->data);
		}
		if(temp->left){
			getLeftSide(result, temp->left);
		}
		else {
			getLeftSide(result, temp->right);
		}
	}

	void getLeafNodes(vector<int>&result, Node*temp)
	{
		// we will use inorder traversal to get the leaf nodes
		// and will pick the value if the node is a leaf node only.
		if(temp == NULL) return;
		if(isleaf(temp))
		{
			result.push_back(temp->val);
		}
		getLeafNodes(result, temp->left);
		getLeafNodes(result, temp->right);
	}

	void getReverseRightSide(vector<int>&result, Node*temp){
		vector<int>intermediate;
		while(temp != NULL)
		{	
			if(!isLeaf(temp)){
				intermediate.push_back(temp->value);
			}
			if(temp->right){
				temp = temp->right;
			}
			else{
				temp = temp->left;
			}

			// now reverse insert the data into main vector
			for(int i = intermediate.size()-1; i >= 0; i--)
			{
				result.push_back(intermediate[i]);
			}
		}
	}

    vector <int> boundary(Node *root)
    {
        vector<int>result;
		getLeftSide(result, root);
		getLeafNodes(result, root);
		getReverseRightSide(result, root->next); // because root will be stored with the left side
		return result;
    }
};