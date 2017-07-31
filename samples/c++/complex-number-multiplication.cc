// https://leetcode.com/problems/complex-number-multiplication/description/

class Solution {
public:
    string complexNumberMultiply(string s, string t) {        
        int a = stoi(s.substr(0, s.find("+")));
        int b = stoi(s.substr(s.find("+")+1));
        
        int c = stoi(t.substr(0, t.find("+")));
        int d = stoi(t.substr(t.find("+")+1));
        
        // (a + b i) * (c + d i) == ac - bd + (ad + bc) i
        int e = a*c - b*d;
        int f = a*d + b*c;
        
        return to_string(e) + "+" + to_string(f) + "i";                                                    
    }
};
