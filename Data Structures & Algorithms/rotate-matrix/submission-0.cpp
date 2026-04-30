class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        // (y, x) -> (n - 1 - x, y)
        // (y, x) -> (x , n - 1 - y)
        const auto n = matrix.size();
        auto mat = matrix;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                mat[j][n-1-i]=matrix[i][j];
            }
        }
        mat.swap(matrix);
    }
};
