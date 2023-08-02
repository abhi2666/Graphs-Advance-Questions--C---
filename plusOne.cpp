/*
Input: digits = [1,2,3]
Output: [1,2,4]

Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int i = digits.size()-1;
        int carry = 1, sum = 0;
        while(i >= 0 || carry)
        {
            sum = 0;
            if(i >= 0)
            {
                sum += digits[i--];
            }
            sum += carry;
            carry = sum/10;
            sum %= 10;

            res.push_back(sum);
        }
        // check if there is any carry left
        if(carry)
        {
            res.push_back(carry);
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};