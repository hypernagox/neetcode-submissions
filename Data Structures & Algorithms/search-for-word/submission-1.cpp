
constexpr const int dy[]{-1,0,1,0};
constexpr const int dx[]{0,1,0,-1};

class Solution {
public:
    vector<vector<char>> b;
    string w;
    bool visited[6][6]={};
    bool GO(const int y, const int x, const int depth)
    {
        if(depth == w.size() - 1)
        {
            return w[depth] == b[y][x];
        }
        if(w[depth] != b[y][x])return false;
        for(int i=0;i<4;++i)
        {
            const auto ny = y + dy[i];
            const auto nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= b.size() || nx >= b.back().size())continue;
            if(visited[ny][nx])continue;
            visited[ny][nx]=1;
            if(GO(ny,nx,depth + 1))return true;
            visited[ny][nx]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        b.swap(board);
        w.swap(word);
        for(int i=0;i<b.size();++i)
        {
            for(int j=0;j<b.back().size();++j)
            {
                visited[i][j]=1;
                if(GO(i,j,0))
                {
                    return true;
                }
                 visited[i][j]=0;
            }
        }
        return false;
    }
};
