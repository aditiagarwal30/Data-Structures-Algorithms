// Memoization
class Solution
{
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 or j >= matrix[0].size())
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
        int lup = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
        int rup = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(up, min(lup, rup));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, solve(n - 1, i, matrix, dp));
        }
        return ans;
    }
};

// Tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j], lup = 1e9, rup = 1e9;

                up += dp[i - 1][j];
                if (j > 0)
                    lup = matrix[i][j] + dp[i - 1][j - 1];
                if (j + 1 < m)
                    rup = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min(up, min(lup, rup));
            }
        }

        for (int i = 0; i < m; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};

// space Optimized

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m, 0);
        for (int i = 0; i < m; i++)
        {
            dp[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j], lup = 1e9, rup = 1e9;

                up += dp[j];
                if (j > 0)
                    lup = matrix[i][j] + dp[j - 1];
                if (j + 1 < m)
                    rup = matrix[i][j] + dp[j + 1];

                temp[j] = min(up, min(lup, rup));
            }
            dp = temp;
        }

        for (int i = 0; i < m; i++)
        {
            ans = min(ans, dp[i]);
        }

        return ans;
    }
};
