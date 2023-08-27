/*
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        int i, j, k, l;
        for(int i = 0; i < nums.size(); i++)
        {
            // skip any duplicate elements
            for(int j = i+1; j < nums.size()-1; j++)
            {
                //skip any duplicate elements
                k = j+1, l = nums.size()-1;
                while(k < l)
                {
                    int sum = nums[i]+nums[j]+nums[k] + nums[l];
                    if(sum == target){
                        vector<int>ans = {nums[i], nums[j], nums[k], nums[l]};
                       
                        result.push_back(ans);
                        k++;
                        l--;

                        // skip any duplicates
                        // now skip any repeating element
                    }
                    else if(sum < target) k++;
                    else l--;

                }

            }
        }
        return result;
    }
};