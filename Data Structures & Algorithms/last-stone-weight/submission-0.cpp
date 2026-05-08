class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> pq{stones.begin(),stones.end()};
        while(pq.size() > 1)
        {
            const auto a = pq.top();
            pq.pop();
            const auto b = pq.top();
            pq.pop();
            pq.emplace(abs(a - b));
        }
        return pq.empty() ? 0 : pq.top();
    }
};
