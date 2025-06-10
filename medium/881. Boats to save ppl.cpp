class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0, sum = 0, n = people.size();
        int i=0, j=n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                boats++;
                i++;
                j--;
            }
            else{
                boats++;
                j--;
            }
        }
        return boats;
    }
};
