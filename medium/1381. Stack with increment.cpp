class CustomStack {
public:
    vector<int>st; int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(st.size()<size){
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int y = st.back();
        st.pop_back();
        return y;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<st.size(); i++) st[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
