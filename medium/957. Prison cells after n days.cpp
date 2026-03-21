class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int>ans(8,0);
        map<vector<int>, int>occuredAt;
        // occuredAt[cells] = 0;
        int rep = 0;
        // if()
        for(int i=1; i<=n; i++){
            vector<int>temp = cells;
            temp[0] = cells[0];
            temp[7] = cells[7];
            for(int j=1; j<7; j++){
                if(cells[j-1] == cells[j+1]) temp[j] = 1;
                else temp[j] = 0;
            }
            temp[0] = 0;
            temp[7] = 0;
            if(occuredAt.find(temp) == occuredAt.end()){
                occuredAt[temp] = i;
            }
            else{
                rep = i-occuredAt[temp];
                break;
            }
            cells = temp;
        }
        int rem = n;
        if(rep != 0) rem = n%rep;
        for(auto it: occuredAt){
            if(it.second == rem) return it.first;
        }
        return cells;
    }
};
