class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(auto &it:boxTypes){
            swap(it[0], it[1]);
            cout<<it[0]<< " "<<it[1]<<endl;
        }
        cout <<"==========="<<endl;
        sort(boxTypes.begin(), boxTypes.end());
        reverse(boxTypes.begin(), boxTypes.end());
        for(auto &it:boxTypes){
            // swap(it[0], it[1]);
            cout<<it[0]<< " "<<it[1]<<endl;
        }
        int units = 0;
        for(auto it:boxTypes){
            if(it[1]<=truckSize){
                units += it[0]*it[1];
                truckSize -= it[1];
            }
            else{
                units += truckSize*it[0];
                break;
            }
        }
        return units;

    }
};
