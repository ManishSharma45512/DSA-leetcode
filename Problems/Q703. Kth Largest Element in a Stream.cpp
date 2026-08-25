class KthLargest {
    // Min-heap to keep track of the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_size;

public:
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // Keep heap size exactly k
        if (minHeap.size() > k_size) {
            minHeap.pop();
        }
        
        // The top of the min-heap is the kth largest element
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
