// RECURSION

class Solution
{
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        if (i == 0 and j == 0)
        {
            return grid[0][0];
        }
        if (i < 0 || j < 0)
            return 1e9;

        int up = grid[i][j] + solve(i - 1, j, m, n, grid);
        int left = grid[i][j] + solve(i, j - 1, m, n, grid);

        return min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, m, n, grid);
    }
};

// Dynamic Programming

class Solution
{
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 and j == 0)
        {
            return dp[0][0] = grid[0][0];
        }
        if (i < 0 || j < 0)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = grid[i][j] + solve(i - 1, j, m, n, grid, dp);
        int left = grid[i][j] + solve(i, j - 1, m, n, grid, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(m - 1, n - 1, m, n, grid, dp);
        return dp[m - 1][n - 1];
    }
};

// Tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j], left = grid[i][j];
                    if (i > 0)
                        up = up + dp[i - 1][j];
                    else
                        up += 1e9;

                    if (j > 0)
                        left = left + dp[i][j - 1];
                    else
                        left += 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space Optimized

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    temp[j] = grid[i][j];
                else
                {
                    int up = grid[i][j], left = grid[i][j];
                    if (i > 0)
                        up = up + prev[j];
                    else
                        up += 1e9;

                    if (j > 0)
                        left = left + temp[j - 1];
                    else
                        left += 1e9;

                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};