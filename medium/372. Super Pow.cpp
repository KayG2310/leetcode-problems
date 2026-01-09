class Solution {
private:
    void divide(vector<int>&b, int &n){
        int i=0, carry = 0; 
        while(i<n){
            if(!carry){
                if(b[i]%2==0) b[i] = b[i]/2;
                else{
                    b[i] = b[i]/2;
                    carry = 1;
                }
            }
            else{
                int y = b[i]; y+=10; 
                if(y%2 == 0){
                    carry = 0;
                }
                else carry = 1;
                y = y/2;
                b[i] = y;
            }
            i++;
        }
        while(b[0] == 0) b.erase(b.begin());
        n = b.size();
    }
    void minusone(vector<int>&b, int &n){
        b[n-1] = b[n-1]-1;
        while(b[0] == 0) b.erase(b.begin());
        n = b.size();
    }
public:
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        int mod = 1337;
        long long ans = 1;
        while(n>0){
            if(n==1 && b[0]==1){
                ans = (ans*a)%mod;
                break;
            } 
            if(b[n-1]%2 == 0){
                // even power 
                a = (((a%mod)*(a%mod))%mod);
                divide(b, n);
                
            }
            else{
                ans = ((ans*a)%mod);
                minusone(b, n);

            }
        }
        return ans%mod;
    }
};
