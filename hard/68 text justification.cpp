class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0;

        while (i < n) {
            int lineLength = 0;
            int start = i;

            // Determine how many words can fit in the current line
            while (i < n && lineLength + words[i].length() + (i - start) <= maxWidth) {
                lineLength += words[i].length();
                i++;
            }

            int numWords = i - start;
            int spaces = maxWidth - lineLength;

            string line = "";
            if (numWords == 1 || i == n) {
                // Left-justified line (for the last line or single word line)
                for (int j = start; j < i; j++) {
                    line += words[j];
                    if (j != i - 1) line += ' ';
                }
                while (line.length() < maxWidth) {
                    line += ' ';
                }
            } else {
                // Fully justified line
                int spaceBetween = spaces / (numWords - 1);
                int extraSpaces = spaces % (numWords - 1);

                for (int j = start; j < i; j++) {
                    line += words[j];
                    if (j != i - 1) {
                        for (int k = 0; k < spaceBetween; k++) line += ' ';
                        if (extraSpaces > 0) {
                            line += ' ';
                            extraSpaces--;
                        }
                    }
                }
            }

            ans.push_back(line);
        }

        return ans;
    }
};
