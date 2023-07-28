#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int mx = nums[i];
            int mn = nums[i];
            for(int j = i; j < nums.size(); j++)
            {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                cout<<"max "<<mx<<" min "<<mn<<endl;
                ans += (mx - mn);
                cout<<ans<<endl;
            }
        }
        cout<<endl;
        return ans;
    }
};

int main()
{
    vector<int> nums = {4, -2, -3, 4, 1};
    Solution s;
    cout<<s.subArrayRanges(nums)<<endl;
    return 0;
}
