// https://leetcode.com/problems/encode-and-decode-tinyurl/description/
class Solution {

private:
    long h = 0;
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.count(longUrl) > 0) return longToShort[longUrl];
        
        string hsh = to_string(h++);
        longToShort[longUrl] = hsh;
        shortToLong[hsh] = longUrl;
        
        return hsh;                
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortToLong.count(shortUrl) > 0) return shortToLong[shortUrl];
        return string("");
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
