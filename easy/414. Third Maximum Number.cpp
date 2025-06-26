class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        for(int i: nums){
            if(a==LLONG_MIN) a=i;
            else if(b==LLONG_MIN){
                if(i>a){
                    b = a;
                    a = i;
                }
                else if(i==a) continue;
                else b = i;
            }
            else if(c==LLONG_MIN){
                if(i>a){
                    c = b;
                    b = a;
                    a = i;
                }
                else if(i==a) continue;
                else if(i>b){
                    c = b;
                    b = i;
                }
                else if(i==b) continue;
                else c = i;
            }
            else{
                // all are set
                if(i>a){
                    c = b;
                    b = a;
                    a = i;
                }
                else if(i==a) continue;
                else if(i>b){
                    c = b;
                    b = i;
                }
                else if(i==b) continue;
                else if(i>c){
                    c = i;
                }
            }
        }
        return c==LLONG_MIN ? a : c;
    }
};
