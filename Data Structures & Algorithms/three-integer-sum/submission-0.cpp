class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        //vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i=0;i < nums.size();++i)
        {
            vector<int> v;
            const auto fixed = nums[i];
            int l = 0;
            int r = nums.size()-1;
            while(l < r)
            {
                if(l == i)
                {
                    ++l;
                    continue;
                }
                if(r == i)
                {
                    --r;
                    continue;
                }
                const auto val = fixed + nums[l] + nums[r];
                if(val > 0)
                {
                    --r;
                }
                else if(val < 0)
                {
                    ++l;
                }
                else
                {
                    v.emplace_back(nums[r]);
                    v.emplace_back(nums[l]);
                    v.emplace_back(nums[i]);
                    sort(v.begin(),v.end());
                    s.emplace(move(v));
                    --r;
                    ++l;
                }
            }
        }
        vector<vector<int>> ans{s.begin(),s.end()};
        return ans;
    }
};
