class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int count[26]{};
        int l = 0;
        int maxFreq = 0;
        int ans = 0;
        for (int r = 0; r < s.size(); ++r)
         {
            const int idx = s[r] - 'A';
            ++count[idx];
            maxFreq = max(maxFreq, count[idx]);
            while ((r - l + 1) - maxFreq > k)
             {
                --count[s[l] - 'A'];
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
