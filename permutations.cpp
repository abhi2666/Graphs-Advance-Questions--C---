/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
class Solution {
public:

    void getPermutations(vector<int>&nums, vector<vector<int>>&ans, vector<int>&res, int freq[])
    {
        if(res.size() == nums.size())
        {
            //you have got one permutation
            ans.push_back(res);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            //check if the element is picked or not
            if(freq[i] == 0)
            {
                //not picked yet..pick it
                res.push_back(nums[i]);
                freq[i] = 1;
                getPermutations(nums, ans, res, freq);
                //remove the element from array
                res.pop_back();
                freq[i] = 0;
            }
            
        }
        return;

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int freq[nums.size()];
        for(int i = 0; i < nums.size(); i++) freq[i] = 0;
        getPermutations(nums, ans, res, freq);
        return ans;
    }
};