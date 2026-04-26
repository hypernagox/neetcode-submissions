class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        sort(points.begin(),points.end(),[](const auto& a, const auto& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        vector<vector<int>> ans;ans.reserve(k);
        for(int i=0;i<k;++i)
        {
            ans.emplace_back(move(points[i]));
        }
        return ans;
    }
};
