#include <cstring>
class Solution {
public:
    int memo[46]{};
    int GO(const int n)
    {
        if(n < 0)return 0;
        if(n == 0)return 1;
        auto& ref = memo[n];
        if(~ref)return ref;
        return ref = GO(n - 1) + GO(n - 2);
    }
    int climbStairs(int n) 
    {
        memset(memo,-1,sizeof(memo));
        return GO(n);
    }
};
