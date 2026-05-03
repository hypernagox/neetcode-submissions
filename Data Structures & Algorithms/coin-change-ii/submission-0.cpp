#include <cstring>
class Solution {
public:
    vector<int> coins;
    int memo[101][5001]{};
    int GO(const int idx, const int cur_money)
    {
        if(cur_money < 0)return 0;
        if(idx == coins.size())return cur_money == 0;
        auto& ref = memo[idx][cur_money];
        if(~ref)return ref;
        // 쓴다.
        const auto a = GO(idx, cur_money - coins[idx]);
        // 쓰지 않는다.
        const auto b = GO(idx + 1, cur_money);
        return ref = a + b;
    }
    int change(int amount, vector<int>& coin)
    {
        coins.swap(coin);
        memset(memo,-1,sizeof(memo));
        return GO(0, amount);
    }
};
