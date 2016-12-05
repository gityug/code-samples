// https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r;
        for (int i = 1; i <= n; ++i) {
            string s;
            if (i % 3 == 0) s = "Fizz";
            if (i % 5 == 0) s += "Buzz";
            if (s.empty()) s = to_string(i);
            r.push_back(s);
        }
        return r;
    }
};