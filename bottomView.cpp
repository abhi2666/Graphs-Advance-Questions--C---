/*
To get the bottom view of the tree we can perform something like a vertical
order traversal which is a slight variation of BFS(level order traversal).

we will use BFS to store the elements
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int>mp; // node->data, vertical_level
        queue<pair<Node*, int>>q; // Node, vertical_level
        vector<int>result;
        q.push({root, 0});
        while(!q.empty())
        {
          auto item = q.front();
          q.pop();
          Node* node = item.first;
          int level = item.second; // to store the node with its level in map
          mp[level] = node->data;

          if(node->left)
          {
            q.push({node->left, level-1});
          }
          if(node->right)
          {
            q.push({node->right, level+1});
          }
        }
      // now the elements will be stored in sorted order in map
      for(auto it : mp)
      {
        result.push_back(it.second);
      }

      return result;
    }
};