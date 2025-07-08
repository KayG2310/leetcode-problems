// brute force 
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& f, int z) {
        vector<vector<int>>v;
        for(int x=1; x<=1000; x++){
            for(int y =1; y<=1000; y++){
                if(f.f(x, y)==z) v.push_back({x, y});
            }
        } 
        return v;
    }
};

// optimised 
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& f, int z) {
        vector<vector<int>>v;
        int low = 1, high = 1000; 
        int maxix = 0;
        while(low <=high){
            int mid = (low+high)/2;
            if(f.f(mid, 1) <=z){
                maxix = max(maxix, mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        int maxiy = 0;
        low = 1, high = 1000;
        while(low <=high){
            int mid = (low+high)/2;
            if(f.f(1, mid) <=z){
                maxiy = max(maxiy, mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        for(int x=1; x<=maxix; x++){
            for(int y =1; y<=maxiy; y++){
                if(f.f(x, y)==z) v.push_back({x, y});
            }
        } 
        return v;
    }
};
