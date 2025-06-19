#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.length()) + '|' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.length()) {
            int delimiter_pos = s.find('|', i);
            if (delimiter_pos == string::npos) break;
            
            int length = stoi(s.substr(i, delimiter_pos - i));
            string str = s.substr(delimiter_pos + 1, length);
            decoded.push_back(str);
            
            i = delimiter_pos + 1 + length;
        }
        return decoded;
    }
};
