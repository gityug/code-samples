// Given an absolute path for a file (Unix-style), simplify it.
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return "";
        
        vector<string> s;

        char* p = strdup(path.c_str());
        char* tok = strtok(p, "/");
        
        while (tok) {
            if (string(tok) == "..") {
                if (s.size() != 0) s.pop_back();
            } else if (string(tok) != ".") {
                s.push_back(tok);
            }
            tok = strtok(0, "/");
        }
        
        string res = "/";
        for (int i = 0; i < s.size(); ++i) {
            if (i != 0) res += "/";
            res += s[i];
        }
        free(p);
        return res;
    }
};
