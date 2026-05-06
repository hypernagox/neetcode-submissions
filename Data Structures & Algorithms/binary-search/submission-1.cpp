class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        unordered_map<int,int> m;m.reserve(nums.size());
        for(int i=0;i<nums.size();++i)
        {
            m.try_emplace(nums[i],i);
        }
        const auto iter = m.find(target);
        return iter != m.end() ? iter->second : -1;
    }
};
