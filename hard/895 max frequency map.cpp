// my solution
class FreqStack {
    unordered_map<int, int>m1;
    map<int, vector<int>>m2;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
       m1[val]++;
       m2[-1*m1[val]].push_back(val);
       
    }
    
    int pop() {
        if(m2.size()==0) return -1;
        auto it = m2.begin();
        auto& v = it->second; // use reference
        int ans = v[v.size()-1];
        v.pop_back();
        if(v.size()==0){
            m2.erase(it->first);
            m1[ans]--;
            if(m1[ans]==0) m1.erase(ans);
            
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */ 




// better solution 
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int maxfreq = 0;

    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        m[freq[x]].push(x);
    }

    int pop() {
        int x = m[maxfreq].top();
        m[maxfreq].pop();
        if (!m[freq[x]--].size()) maxfreq--;
        return x;
    }
