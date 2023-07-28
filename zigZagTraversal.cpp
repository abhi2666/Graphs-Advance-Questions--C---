// #include<bits/stdc++.h>
// using namespace std;

/*
Zig Zag Traversal can be easily achieved by using BFS traversal.
Keep in mind to have a bool variable which will tell if the value is to be stored from left to 
right or vice versa.
*/

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // we can apply BFS
        vector<vector<int>> setOfNodes;
        if(root == NULL) return setOfNodes;
        queue<TreeNode *> q4nodes;
        bool leftToRight = true; // will keep track of wether to store from left to right or
        // right to left
        q4nodes.push(root);
        while (!q4nodes.empty())
        {
            // for the no. of elements the queue have.. we will extract them as soon as soon as
            // that happens we will insert their left and right element into the queue..
            int currentSizeOfQueue = q4nodes.size();
            vector<int> intermediateNodes(currentSizeOfQueue);
            for (int i = 0; i < currentSizeOfQueue; i++)
            {
                TreeNode* storedNode = q4nodes.front();
                q4nodes.pop(); // removing the node which we have taken already

                // will check if insertion is from right to left or vice versa.
                int getIndex = (leftToRight) ? i : (currentSizeOfQueue - 1 - i);
                intermediateNodes[getIndex] = storedNode->val;
                // now check for its left or right
                if (storedNode->left)
                {
                    q4nodes.push(storedNode->left);
                }
                if (storedNode->right)
                {
                    q4nodes.push(storedNode->right);
                }
            }
            leftToRight  = !leftToRight;
            setOfNodes.push_back(intermediateNodes);
        }

        return setOfNodes;
    }
};