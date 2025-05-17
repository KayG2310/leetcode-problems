class NumArray {
    int n;
    vector<int>SegmentTree;

    void buildtree(int i, int l, int r, vector<int>& nums){
        if(l==r){
            SegmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildtree(2*i+1, l, mid, nums);
        buildtree(2*i+2, mid+1, r, nums);
        SegmentTree[i] = SegmentTree[2*i+1]+SegmentTree[2*i+2];
    }
    void updateQuery(int index_where_to_update, int value, int root_index, int left, int right, vector<int>&SegmentTree){
        if(left == right){
            SegmentTree[root_index] = value;
            return;
        }
        int mid = left+(right-left)/2;
        if(index_where_to_update <= mid){
            updateQuery(index_where_to_update, value, 2*root_index+1, left, mid, SegmentTree);
        }
        else{
            updateQuery(index_where_to_update, value, 2*root_index+2, mid+1, right, SegmentTree);
        }
        SegmentTree[root_index] = SegmentTree[2*root_index+1]+SegmentTree[2*root_index+2];
    }

    int output(int query_start, int query_end, int left, int right, int i){
        if(left > query_end || right < query_start){
            return 0;
        }
        if(left >= query_start && right <= query_end){
            return SegmentTree[i];
        }
        int mid = left+(right-left)/2;
        return output(query_start, query_end, left, mid, 2*i+1)+output(query_start, query_end, mid+1, right, 2*i+2);
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        SegmentTree.resize(4*n);
        buildtree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateQuery(index, val, 0, 0, n-1, SegmentTree);
    }
    
    int sumRange(int left, int right) {
        return output(left, right, 0, n-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
