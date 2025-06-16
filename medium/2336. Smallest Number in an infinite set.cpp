class SmallestInfiniteSet {
public:
    vector<int>v;
    SmallestInfiniteSet() {
        for(int i=0; i<2000; i++){
            v.push_back(1); // in set 
        }
    }
    
    int popSmallest() {
        int index = 0;
        for(int i=1; i<2000; i++){
            if(v[i]){
                index = i;
                break;
            }
        }
        v[index] = 0;
        return index;
    }
    
    void addBack(int num) {
        if(num>=2000) return;
        if(v[num]) return;
        v[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
