class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int>mpp;
        for(int i: answers) mpp[i]++;
        int rabbits = 0;
        for(auto it: mpp){
            cout<<it.first<<" "<<it.second<<endl; 
            if(it.first == 0) {
                rabbits += it.second;
                cout<<it.first<<"here1"<<endl;
            }
            else if(it.second<=it.first){
                rabbits += it.first+1;
                cout<<it.first<<"here2"<<endl;
            }
            else{
                if(it.first+1 == it.second) {
                    rabbits += it.second;
                    cout<<it.first<<"here3"<<endl;
                }
                else {
                    double x = (double)(it.second)/(double)(it.first+1);
                    int y = ceil(x);
                    rabbits += y*(it.first+1);
                    cout<<it.first<<"here4"<<endl;
                }
            }
        }
        return rabbits;
    }
};
