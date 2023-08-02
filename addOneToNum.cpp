vector<int> Solution::plusOne(vector<int> &A) {
    // array represents the number where the A[0] symobolizes the most
    // significant bit
    vector<int>ans;
    int carry = 1;
    int sum = 0;
    for(int i = A.size()-1; i >= 0; i++)
    {
        sum = A[i] + carry;
        carry = sum / 10;
        sum %= 10;

        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
