class MyHashMap {
    int N;
    vector<int> mpp;
public:
    MyHashMap() {
        N = 1e6 + 1;
        mpp = vector<int>(N, -1);
    }
    
    void put(int key, int value) {
        mpp[key] = value;
    }
    
    int get(int key) {
        return mpp[key];
    }
    
    void remove(int key) {
        mpp[key] = -1;
    }
};
