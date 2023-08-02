/*
maximum width of binary tree (which is directly dependent on level of the binary tree)

for an element present in ith index, its left side will be present in 2*i + 1 th index and 
right side will be present in 2*i + 2 th index.
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q; // (node, index)
        int firstIdx, lastIdx;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            int minIdx = q.front().second;

            for(int i = 0; i < size; i++)
            {
                auto item = q.front();
                q.pop();
                TreeNode* node = item.first;
                int currIdx = item.second - minIdx; // to keep overflow

                if(i == 0) firstIdx = currIdx;
                if(i == size-1) lastIdx = currIdx;

                if(node->left)
                {
                    q.push({node->left, 2*i + 1});

                }
                if(node->right)
                {
                    q.push({node->right, 2*i + 2});
                }
            }
        }
        ans = max(ans, lastIdx-firstIdx+1);
        return ans;
    }
};