 class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string res = "";
        int i = 0;
        
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                counts.push(count);
            }
            else if (s[i] == '[') {
                resultStack.push(res);
                res = "";
                i++;
            }
            else if (s[i] == ']') {
                string temp = resultStack.top();
                resultStack.pop();
                int repeat = counts.top();
                counts.pop();
                string repeated = "";
                for (int j = 0; j < repeat; j++) {
                    repeated += res;
                }
                res = temp + repeated;
                i++;
            }
            else {
                res += s[i];
                i++;
            }
        }
        
        return res;
    }
};
