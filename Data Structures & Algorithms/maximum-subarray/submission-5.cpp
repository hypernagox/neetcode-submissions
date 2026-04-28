class Solution {
public:
    vector<int> n;
    int memo[1001];

    int GO(const int idx)
    {
        if(idx == n.size())return -1000000000;

        auto& ref = memo[idx];
        if(ref != -1000000000)return ref;

        return ref = max(n[idx], n[idx] + GO(idx + 1));
    }

    int maxSubArray(vector<int>& nums)
    {
        n = nums;

        for(int i=0;i<1001;++i)
        {
            memo[i] = -1000000000;
        }

        int ans = -1000000000;

        for(int i=0;i<nums.size();++i)
        {
            ans = max(ans, GO(i));
        }

        return ans;
    }
};
