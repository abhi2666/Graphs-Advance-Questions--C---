/*
Very similar to bottom view approach but here you just have to push the
element into map if they are not present there already.
*/

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;           // node->data, vertical_level
        queue<pair<Node *, int>> q; // Node, vertical_level
        vector<int> result;
        q.push({root, 0});
        while (!q.empty())
        {
            auto item = q.front();
            q.pop();
            Node *node = item.first;
            int level = item.second; // to store the node with its level in map

            if(mp.find(level) == mp.end()) mp[level] = node->data;
            if (node->left)
            {
                q.push({node->left, level - 1});
            }
            if (node->right)
            {
                q.push({node->right, level + 1});
            }
        }
        // now the elements will be stored in sorted order in map
        for (auto it : mp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};