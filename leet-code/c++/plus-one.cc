// https://leetcode.com/problems/plus-one/
//
// Given a non-negative number represented as an array of digits, plus one to the number.
//
// The digits are stored such that the most significant digit is at the head of the list.
//

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0, carry = 1;
        list<int> l;
        for (int i = digits.size() - 1; i >= 0; i--) {
            sum = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            l.push_front(sum);
        }
        if (carry == 1) l.push_front(carry);
        
        vector<int> v;
        for (list<int>::iterator j = l.begin(); j != l.end(); j++) {
            v.push_back(*j);
        }
        return v;
    }
};
