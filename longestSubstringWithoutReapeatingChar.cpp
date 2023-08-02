// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int longestLengthSubstr = 0;
//         unordered_map<char, int>mp;
//         int left, right;
//         left = right = 0;
//         while(right < s.size())
//         {
//             // if element not found in the map then insert it and inc. right
//             // else inc left to where right is and also update it in the map
//             if(mp.find(s[right]) == mp.end())
//             {
//                 // insert it
//                 mp[s[right]] = right;
//             }
//             else{
//                 left = mp[s[right]]+1;
//             }
//             longestLengthSubstr = max(longestLengthSubstr, right-left+1);
//             right++;
//         }
//         return longestLengthSubstr;
//     }
// };

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longestLengthSubstr = 0;
        unordered_map<char, int> mp;
        int left, right, size = s.size();
        left = right = 0;
        while (right < size)
        {
            if (mp.find(s[right]) != mp.end())
            {
                // means the character already exists
                // update the left value
                left = max(mp[s[right]] + 1, left);
            }

            mp[s[right]] = right;

            longestLengthSubstr = max(longestLengthSubstr, right - left + 1);
            right++;
        }
        return longestLengthSubstr;
    }
};