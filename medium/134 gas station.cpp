# my solution -->gave runtime error 
class Solution {
private:
    bool check(vector<int>& start, vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        for (int i = start[2]; i < gas.size(); i++) {
            cur += gas[i] - cost[i];
            if (cur < 0) return false;
        }
        for (int i = 0; i < start[2]; i++) {
            cur += gas[i] - cost[i];
            if (cur < 0) return false;
        }
        return true;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty() || gas.size() != cost.size()) return -1; // Added safety check

        vector<vector<int>> total;
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] - cost[i] >= 0)
                total.push_back({cost[i], gas[i], i});
        }

        sort(total.begin(), total.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] >= b[1];
        });

        if (total.empty()) return -1;

        for (int i = 0; i < total.size(); i++) {
            vector<int> start = total[i];
            if (check(start, gas, cost)) {
                return start[2];
            }
        }
        return -1;
    }
};

# editorial 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int n = gas.size();
        int start = 0,tg=0,tc =0;
        for(int i=0;i<n;i++){
            tg += gas[i];
            tc += cost[i];
            sum += gas[i]-cost[i];
            if(sum<0){
                start = i+1;
                sum = 0;
            }
        }
        return (tg<tc) ? -1 : start;
    }
};
