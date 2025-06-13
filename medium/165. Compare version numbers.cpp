class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1;
        vector<int>v2;
        stringstream ss1(version1);
        stringstream ss2(version2);
        string token1, token2;
        while(getline(ss1, token1, '.')){
            int num = 0;
            for(char c: token1){
                num = num*10+(c-'0');
            }
            v1.push_back(num);
        }
        while(getline(ss2, token2, '.')){
            int num = 0;
            for(char c: token2){
                num = num*10+(c-'0');
            }
            v2.push_back(num);
        }
        while(v1.size()<v2.size()){
            v1.push_back(0);
        }
        while(v2.size()<v1.size()){
            v2.push_back(0);
        }
        // now we can compare 
        int n = v1.size();
        for(int i=0; i<n; i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }
        return 0;
    }
};
