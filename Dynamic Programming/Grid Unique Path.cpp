// Combinatrics
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int h = m + n - 2;
        int r = m - 1;
        double res = 1.0;

        for (int i = 1; i <= r; i++)
            res = res * (h - r + i) / i;
        return (int)res;
    }
};

// Tabulation
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Memoization
class Solution
{
    int solve(int i, int j, int m, int n, vector<vector<int>> dp)
    {
        if (i == m - 1 and j == n - 1)
        {
            return 1;
        }
        if (i >= m or j >= n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i, j + 1, m, n, dp) + solve(i + 1, j, m, n, dp);
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};