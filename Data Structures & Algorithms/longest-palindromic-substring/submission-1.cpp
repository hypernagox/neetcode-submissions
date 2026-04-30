#include <cstring>
class Solution {
public:
    string S;
    int memo[1001][1001];
    int GO(const int l ,const int r)
    {
        if(l >= r)return 1;
        auto& ref = memo[l][r];
        if(~ref)return ref;
        if(S[l] == S[r])
        {
            return ref = GO(l + 1, r - 1);
        }
        else
        {
            return ref = 0;
        }
    }
    string longestPalindrome(string s)
    {
        s.swap(S);
        memset(memo,-1,sizeof(memo));
        int len = -1;
        int l,r;
        for(int i=0;i<S.size();++i)
        {
            for(int j=i; j< S.size();++j)
            {
                if(GO(i,j))
                {
                    if(len < (j - i))
                    {
                        l = i;
                        r = j;
                        len = (j - i);
                    }
                }
            }
        }
        return S.substr(l, len + 1);
    }
};
