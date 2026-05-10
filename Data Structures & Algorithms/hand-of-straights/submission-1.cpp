class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size() % groupSize  != 0)return false;
        multiset<int> s;
        for(const auto i : hand)
        {
            s.emplace(i);
        }
        int cur = *s.begin();
        s.erase(s.begin());
        int cur_s = 1;
        while(s.size())
        {
            if(cur_s == groupSize)
            {
                cur = *s.begin();
                s.erase(s.begin());
                cur_s = 1;
                continue;
            }
            const auto iter = s.find(cur + 1);
            if(iter != s.end())
            {
                s.erase(iter);
                cur = cur + 1;
                ++cur_s;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
