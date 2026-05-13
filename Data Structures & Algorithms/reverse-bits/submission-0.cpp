class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> bits{n};
        string num;num.reserve(32);
        while(n)
        {
            num.push_back((n % 2) + '0');
            n /= 2;
        }
        while(num.size() != 32)
        {
            num.push_back('0');
        }
        reverse(num.begin(),num.end());
        uint32_t res = 0;
        for(int i = 0;i<32;++i)
        {
            const auto val = num[i] - '0';
            res += val * (int)pow(2,i);
        }
        return res;
    }
};
