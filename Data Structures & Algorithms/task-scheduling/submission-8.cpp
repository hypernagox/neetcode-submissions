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
        int ans = 0;
        sort(t,t+26,greater<int>{});
        while(Check(t))
        {
            int cnt = 0;
            for(int i=0;i<26;++i)
            {
                if(t[i])
                {
                    --t[i];
                    ++cnt;
                    ++ans;
                    if(cnt == n + 1)
                    {
                        sort(t,t+26,greater<int>{});
                        cnt = 0;
                        i = -1;
                    }
                }
            }
            if(!Check(t))break;
            if(cnt <= n + 1)
            {
                ans += (n + 1) - cnt;
            }
        }
        return ans; 
    }
};
