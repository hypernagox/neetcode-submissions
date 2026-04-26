class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        set<int> r;
        set<int> c;
        for(int i = 0;i<matrix.size();++i)
        {
            for(int j = 0;j<matrix.front().size();++j)
            {
                if(matrix[i][j]==0)
                {
                    r.emplace(i);
                    c.emplace(j);
                }
            }
        }
        for(const auto i : r)
        {
            for(auto& e : matrix[i])
            {
                e=0;
            }
        }
        for(const auto j : c)
        {
            for(int i=0;i<matrix.size();++i)
            {
                matrix[i][j]=0;
            }
        }
    }
};
