class Solution {
private:
    long long t(long long height){
        return (height*(height+1))/2;
    }
    double quad(double y){
        double a = 1, b = 1, c = -y;
        double disc = 1+4*y;
        if(disc >=0){
            return floor(max((-1+pow(disc, 0.5))/2.0, (-1-pow(disc, 0.5))/2.0));
        }
        return 0.0;
    }
    bool f(long long mid, int n, int h, vector<int>& w){
        double ans = 0;
        for(int i=0; i<n; i++){
            // assuming this person takes mid time, find the max height it covers 
            double y = floor(2.0*(double)mid/(double)w[i]);
            ans += quad(y);
            // cout<<mid<<"--->"<<ans<<endl;
            if(ans >= h) return true;
        }
        if(ans >= h) return true;
        return false;
    }
public:
    long long minNumberOfSeconds(int h, vector<int>& w) {
        int n = w.size();
        long long x = h;
        if(n==1) return w[0]*t(x);
        long long low = 1, high = (*max_element(w.begin(), w.end()))*t(x);
        long long ans = high;
        while(low<=high){
            long long mid = (low+high)/2;
            // cout<<low<<"&"<<high<<"&"<<mid<<endl;
            if(f(mid, n, h, w)){
                high = mid-1;
                ans = min(ans, mid);
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
