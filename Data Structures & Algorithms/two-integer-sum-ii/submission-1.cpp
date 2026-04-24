class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> ans;ans.reserve(2);
        for(int i=0;i<numbers.size();++i)
        {
            const auto val = target - numbers[i];
            const auto iter = lower_bound(numbers.begin()+i+1, numbers.end(), val);
            if(iter != numbers.end() && *iter == val)
            {
                ans.emplace_back(i+1);
                ans.emplace_back(iter - numbers.begin() + 1);
                break;
            }
        }
        return ans;
    }
};
