// sort of brute force
class Solution {
public:
    long long maximumTotalSum(vector<int>& he) {
        long long sum = 0;
        set<long long>track;
        for(int i: he){
            while(track.find(i)!=track.end()){
                i--; 
            }
            if(i==0) return -1;
            sum += i;
            track.insert(i);
        }
        return sum;
    }
};

// single pass
class Solution {
public:
    long long maximumTotalSum(vector<int>& he) {
        long long sum = 0;
        sort(he.begin(), he.end());
        reverse(he.begin(), he.end());
        long long cap = he[0];
        int n = he.size(), i = 0;
        while(i<n){
            if(i<n && cap==0) return -1;
            if(he[i]>=cap){
                sum += cap;
                cap--;
                i++;
            }
            else{
                cap = he[i];
            }
        }
        return sum;
    }
};
/*
2 3 4 3
4 3 3 2 cap = 4 sum = 4 


*/
