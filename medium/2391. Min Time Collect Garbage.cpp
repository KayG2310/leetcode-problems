class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int total = 0;
        int m = 0, p = 0, g = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                total++;  
                if (c == 'M') m = i;
                if (c == 'P') p = i;
                if (c == 'G') g = i;
            }
        }
        vector<int> prefix(travel.size() + 1, 0);
        for (int i = 1; i <= travel.size(); i++) {
            prefix[i] = prefix[i - 1] + travel[i - 1];
        }
        total += prefix[m] + prefix[p] + prefix[g];
        return total;
    }
};
