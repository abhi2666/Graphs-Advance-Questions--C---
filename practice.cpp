#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main()
{
    map<int, int>mp;
    auto it = mp;
    cout<<it<<endl;
    Solution s;
    cout<<s.subArrayRanges(nums)<<endl;
    return 0;
}
