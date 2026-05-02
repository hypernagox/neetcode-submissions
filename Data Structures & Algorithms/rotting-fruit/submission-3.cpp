class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        constexpr const int dy[]{-1,0,1,0};
        constexpr const int dx[]{0,1,0,-1};
        int visited[11][11]{};
        queue<pair<int,int>> q;
        bool flag=true;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid.back().size();++j)
            {
                if(2 == grid[i][j])
                {
                    q.emplace(i,j);
                }
                else if(1 == grid[i][j])
                {
                    flag = false;
                }
            }
        }
        if(q.empty())return flag ? 0 : -1;
        visited[q.front().first][q.front().second] = 1;
        while(q.size())
        {
            const auto [y,x] = q.front();
            q.pop();
            for(int i=0;i<4;++i)
            {
                const auto ny = y + dy[i];
                const auto nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >=grid.size() || nx >= grid.back().size())continue;
                if(visited[ny][nx])continue;
                if(1 != grid[ny][nx])continue;
                visited[ny][nx] = visited[y][x] + 1;
                grid[ny][nx] = 2;
                q.emplace(ny,nx);
            }
        }
        int ans = -1;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid.back().size();++j)
            {
                if(grid[i][j] == 1)return -1;
                ans = max(ans, visited[i][j]);
            }
        }
        return ans - 1;
    }
};
