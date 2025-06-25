// brute force
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> vowelCount;
            int consonantCount = 0;
            
            for (int j = i; j < n; j++) {
                char ch = word[j];
                if (vowelsSet.count(ch)) {
                    vowelCount[ch]++;
                } else {
                    consonantCount++;
                }
                
                if (consonantCount > k) break;
                if (consonantCount == k && vowelCount.size() == 5) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
