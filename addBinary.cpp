class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size()-1, j = b.size()-1;
        char carry;
        char ch;
        while(i >= 0 && j >= 0)
        {
            carry = "";
            if(a[i] == '1' && b[j] == '1')
            {
                carry = '1';
                ch = '0';
            }
            else if(a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1')
            {
                ch = '1';
            }
            else{
                ch = '0';
            }
        }


    }
};