class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mpp;

    RandomizedCollection() {}

    bool insert(int val) {
        bool notPresent = (mpp.find(val) == mpp.end());

        nums.push_back(val);
        mpp[val].insert(nums.size() - 1);

        return notPresent;
    }

    bool remove(int val) {
        if (mpp.find(val) == mpp.end()) return false;
        int idx = *mpp[val].begin();
        mpp[val].erase(idx);
        int last = nums.back();
        nums[idx] = last;
        mpp[last].insert(idx);
        mpp[last].erase(nums.size() - 1);
        nums.pop_back();
        if (mpp[val].empty()) {
            mpp.erase(val);
        }
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
