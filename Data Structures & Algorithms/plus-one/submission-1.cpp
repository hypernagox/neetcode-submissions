class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        string str;
        for(const auto i : digits)
        {
            str += (i + '0');
        }
        const auto num = stoull(str) + 1ULL;
        str = to_string(num);
        vector<int> ans;
        for(const auto ch : str)
        {
            ans.emplace_back(ch -'0');
        }
        return ans;
    }
};
