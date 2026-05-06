class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        map<int,int> m;
        for(int i=0;i<nums.size();++i)
        {
            m[nums[i]] = i;
        }
        const auto iter = m.find(target);
        return iter != m.end() ? iter->second : -1;
    }
};
