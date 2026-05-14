class KthLargest {
public:
    int kth;
    vector<int> stream;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        stream.swap(nums);
        sort(stream.begin(),stream.end());      
    }
    
    int add(int val) {
        const auto iter = lower_bound(stream.begin(),stream.end(),val);
        stream.insert(iter,val);
        return stream[stream.size() - kth];
    }
};
