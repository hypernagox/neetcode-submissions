class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();++i)
        {
            m[nums[i]].emplace_back(i);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() - 1;++i)
        {
            const auto val = target - nums[i];
            const auto iter = lower_bound(nums.begin() + i + 1,nums.end(),val);
            if(nums.end() != iter && *iter == val)
            {
                ans.emplace_back(m[val].back());
                m[val].pop_back();
                ans.emplace_back(m[nums[i]].back());
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
