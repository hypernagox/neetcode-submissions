class Solution {
public:
    bool Check(int t[])
    {
        for(int i=0;i<26;++i)
        {
            if(t[i])return true;
        }
        return false;
    }
    int leastInterval(vector<char>& tasks, int n)
    {
        int t[26]{};
        for(const auto i: tasks)
        {
            ++t[i-'A'];
        }
        priority_queue<int> pq;
        for(int i=0;i<26;++i)
        {
            if(t[i])
            {
                pq.emplace(t[i]);
            }
        }
        int ans =0;
        while(pq.size())
        {
            int cnt = 0;
            vector<int> temp;
            while(pq.size())
            {
                ++cnt;
                ++ans;
                const auto val = pq.top() - 1;
                pq.pop();
                if(val)temp.emplace_back(val);
                if(cnt == n + 1)
                {
                    cnt = 0;
                    for(const auto i : temp)pq.emplace(i);
                    temp.clear();
                    //break;
                }
            }
             for(const auto i : temp)pq.emplace(i);
             if(!pq.size())break;
             if(cnt <= n + 1)
             {
                ans += (n + 1) - cnt;
             }
        }
        return ans;
    }
};
