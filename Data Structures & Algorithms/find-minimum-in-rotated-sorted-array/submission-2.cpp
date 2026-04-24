class Solution {
public:
    int findMin(vector<int> &nums) {
        const auto target = nums.back();
        int low =0;
        int high=nums.size();
        int ans = high;
        while(low < high)
        {
            const auto mid = (low+high)/2;
            if(nums[mid] <= target)
            {
                ans = mid;
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return nums[ans];
    }
};
