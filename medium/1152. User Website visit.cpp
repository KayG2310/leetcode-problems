class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // Map to store user -> list of (timestamp, website) pairs
        unordered_map<string, vector<pair<int, string>>> userVisits;

        // Collect all visits for each user
        int n = username.size();
        for (int i = 0; i < n; ++i) {
            string user = username[i];
            int ts = timestamp[i];
            string site = website[i];
            userVisits[user].emplace_back(ts, site);
        }

        // Map to count frequency of each 3-sequence pattern
        unordered_map<string, int> patternCount;

        // Process each user's visit history
        for (auto& [user, visits] : userVisits) {
            int visitCount = visits.size();
            // Set to store unique patterns for current user (avoid counting same pattern multiple times per user)
            unordered_set<string> uniquePatterns;

            // Only process users with at least 3 visits
            if (visitCount >= 3) {
                // Sort visits by timestamp to maintain chronological order
                sort(visits.begin(), visits.end());

                // Generate all possible 3-sequences from user's visits
                for (int i = 0; i < visitCount - 2; ++i) {
                    for (int j = i + 1; j < visitCount - 1; ++j) {
                        for (int k = j + 1; k < visitCount; ++k) {
                            // Create pattern string by concatenating websites with comma separator
                            string pattern = visits[i].second + "," +
                                           visits[j].second + "," +
                                           visits[k].second;
                            uniquePatterns.insert(pattern);
                        }
                    }
                }
            } 

            // Increment count for each unique pattern from this user
            for (const string& pattern : uniquePatterns) {
                patternCount[pattern]++;
            }
        }

        // Find the pattern with maximum count (lexicographically smallest if tie)
        int maxCount = 0;
        string bestPattern;

        for (const auto& [pattern, count] : patternCount) {
            // Update if we found a pattern with higher count, or same count but lexicographically smaller
            if (count > maxCount || (count == maxCount && pattern < bestPattern)) {
                maxCount = count;
                bestPattern = pattern;
            }
        }

        // Split the best pattern string into individual websites
        return split(bestPattern, ',');
    }

private:
    // Helper function to split a string by delimiter
    vector<string> split(string& s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string token;

        // Extract each token separated by delimiter
        while (getline(ss, token, delimiter)) {
            result.push_back(token);
        }

        return result;
    }
};
