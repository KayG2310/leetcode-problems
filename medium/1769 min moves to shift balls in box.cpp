// brute force n2, 1 
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(boxes[j] == '1'){
                    // has a ball 
                    ans[i] += abs(i-j);
                }
            }
        }
        return ans;
    }
};

// optimal prefix sum 
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return answer;
    }
};
