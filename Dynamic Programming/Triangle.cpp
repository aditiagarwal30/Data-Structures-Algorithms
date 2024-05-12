// REcursion
class Solution
{
    int solve(int i, int j, vector<vector<int>> &t)
    {
        if (i == t.size() - 1)
            return t[i][j];

        int down = t[i][j] + solve(i + 1, j, t);
        int diag = t[i][j] + solve(i + 1, j + 1, t);

        return min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>> &t)
    {
        return solve(0, 0, t);
    }
};

// Memoization

class Solution
{
    int solve(int i, int j, vector<vector<int>> &t, vector<vector<int>> &dp)
    {
        if (i == t.size() - 1)
            return t[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = t[i][j] + solve(i + 1, j, t, dp);
        int diag = t[i][j] + solve(i + 1, j + 1, t, dp);

        return dp[i][j] = min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>> &t)
    {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, t, dp);
    }
};

// Tabulation
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &t)
    {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = t[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = t[i][j] + dp[i + 1][j];
                int diag = t[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};

// Space Optimized

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &t)
    {
        int n = t.size();
        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++)
        {
            prev[i] = t[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> cur(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int down = t[i][j] + prev[j];
                int diag = t[i][j] + prev[j + 1];

                cur[j] = min(down, diag);
            }
            prev = cur;
        }
        return prev[0];
    }
};