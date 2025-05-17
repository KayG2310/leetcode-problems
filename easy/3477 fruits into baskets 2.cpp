// brute force solution 
class Solution {
    /*
    what we are essentially doing is --> for a given index, we traverse through the entire array. the first basket that fulfills our purpose is the answer. 
    let's try brute force first
    */
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        vector<int>hash(baskets.size(), 0);
        for(int val: fruits){
            /*
                val = 4
                3 nope, 5 yes, hash[1] = 1
            */
            for(int i=0; i<baskets.size(); i++){
                if(baskets[i]>= val && hash[i] == 0){
                    cnt++;
                    hash[i] = 1;
                    break;
                }
            }
        }
        return fruits.size()-cnt;
    }
};


// optimal 
