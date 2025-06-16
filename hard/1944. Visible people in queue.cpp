#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> v(n, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (!st.empty() && heights[i] > st.top()) {
                st.pop();
                count++;
            }
            if (st.size()>0) count++; 
            v[i] = count;
            st.push(heights[i]); 
        }

        return v;
    }
};
