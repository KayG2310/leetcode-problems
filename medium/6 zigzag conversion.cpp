#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // If there's only one row, return the original string
        
        string result;
        size_t len = s.length();
        
        for (int i = 0; i < numRows; i++) {
            for (size_t j = i; j < len; j += 2 * (numRows - 1)) {
                result += s[j];  // Add the current character
                
                // Add the character from the middle "diagonal" part if it exists
                if (i > 0 && i < numRows - 1 && j + 2 * (numRows - 1) - 2 * i < len) {
                    result += s[j + 2 * (numRows - 1) - 2 * i];
                }
            }
        }
        return result;
    }
};
