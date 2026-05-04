class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        set<int> s;
        //s.reserve(nums.size());
        for(const auto i : nums)
        {
            if(!s.emplace(i).second)return true;
        }
        return false;
    }
};