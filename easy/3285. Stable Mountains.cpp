class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = height.size();
        vector<int>temp;
        for(int i=1; i<n; i++){
            if(height[i-1]>threshold) temp.push_back(i);
        }
        return temp;
    }
};
