
// Q Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/


class Solution
{
public:
    vector<vector<char>> a;
    int n;
    int m;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


bool is_valid(int x, int y)
{
    if (x < n && x >= 0 && y < m && y >= 0)
        return 1;

    return 0;
}

bool vis[5001][5001];

bool dfs(int x, int y, int px, int py)
{

    vis[x][y] = true;


    for (int k = 0; k < 4; k++)
    {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (is_valid(nx, ny) == 1 && a[nx][ny] == a[x][y] && !(px == nx&&py == ny))
        {


            if (vis[nx][ny] == 1)
            {
                return true;
            }

            else {
                bool check = dfs(nx, ny,x,y);


                if (check == 1)
                    return true;
            }
        }
    }


    return false;
}



    bool containsCycle(vector<vector<char>>& grid)
    {

        a=grid;
        n=a.size();
        if(n<=1) return false;
        m=a[0].size();
         for (int i = 0; i < n; i++)
         {
              for (int j = 0; j < m; j++)
            vis[i][j]= false;
         }


    bool cycle =false;


    for (int i = 0; i <n; i++)
    {

        if (cycle == true)
        {
            return true;
        }


        for (int j = 0; j < m; j++) {


            if (vis[i][j] == 0)
            {
                cycle = dfs(i, j,-1, -1);
            }


            if (cycle)
            {
                return cycle;
            }

        }
    }

  return cycle;

    }
};
