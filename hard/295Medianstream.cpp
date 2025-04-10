class MedianFinder {
    priority_queue<int>maxheap; // 
    priority_queue<int, vector<int>, greater<int>>minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() && minheap.empty()) maxheap.push(num);
        else if(num <= maxheap.top()){
            maxheap.push(num);
        }
        else minheap.push(num);

        if(maxheap.size()==minheap.size() || maxheap.size()-minheap.size()==1) return;
        if(maxheap.size() > minheap.size()){
            int y = maxheap.top();
            maxheap.pop();
            minheap.push(y);
            return;
        }
        int y = minheap.top();
        minheap.pop();
        maxheap.push(y);
        return;
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()){
            return ((float)minheap.top()+(float)maxheap.top())/2.0;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
