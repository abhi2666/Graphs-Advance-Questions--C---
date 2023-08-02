class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if(nums.size() <= 1) return true;
        if(nums[0] == 0) return false;

        for(int i = 0; i < nums.size();)
        {
            int val = nums[i], k = i;
            int maxi = 0;
            while(val--)
            {
                maxi = max(maxi, nums[k++]);
            }
            if(maxi == 0) return false;
            i += maxi;
        }
        return true;

    }
};